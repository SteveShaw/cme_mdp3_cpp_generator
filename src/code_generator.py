import xml.etree.ElementTree as ET

TYPE_MAP = {
    "int8": "int8_t",
    "int16": "int16_t",
    "int32": "int32_t",
    "int64": "int64_t",
    "uint8": "uint8_t",
    "uint16": "uint16_t",
    "uint32": "uint32_t",
    "uint64": "uint64_t",
    "char": "char",
}

TYPE_SIZE = {
    "int8" : 1,
    "int16" : 2,
    "int32": 4,
    "int64": 8,
    "uint8": 1,
    "uint16": 2,
    "uint32": 4,
    "uint64": 8,
    "char": 1
}

def cpp_type_from_xml(field_type, types_dict):
    # Map known typedefs to primitive types
    if field_type in types_dict:
        prim, len, option_values = types_dict[field_type]
        return [TYPE_MAP.get(prim, prim), len, option_values]
    return [None, None, None]

def parse_types(root, ns):
    """Build dictionary of <type> definitions."""
    types = {}
    for t in root.findall("types/type", ns):
        name = t.attrib["name"]
        prim_type = t.attrib.get("primitiveType", None)
        length = t.attrib.get("length", None)
        options = {}
        presense = t.attrib.get("presense", None)
        if presense == "optional":
            options[presense] = t.attrib.get("nullValue", None)
        elif presense == "constant":
            options[presense] = t.text.strip()
        if prim_type: 
            types[name] = [prim_type, length, options]
    return types

def parse_types2(root, ns, constant_types):
    lines = []
    constants = []
    for t in root.findall("types/type", ns):
        name = t.attrib["name"]
        prim_type = t.attrib.get("primitiveType", None)
        length = t.attrib.get("length", None)
        presence = t.attrib.get("presence", None)
        cpp_type = TYPE_MAP.get(prim_type, None)
        if cpp_type is None:
            continue
        if presence == "constant":
            constant_types[name] = "ConstValues::{}".format(name)
            if cpp_type == "char":
                constants.append("    static constexpr {} {}= '{}';".format(cpp_type, name, t.text.strip()))
            else:
                constants.append("    static constexpr {} {}= {};".format(cpp_type, name, t.text.strip()))
        elif presence == "optional":
            null_value = t.attrib.get("nullValue", None)
            if null_value:
                lines.append("using {} = {};".format(name, cpp_type))
                if cpp_type == "uint64_t":
                    constants.append("    static constexpr {} {}_NV = {}ULL;".format(cpp_type, name, null_value))
                else:
                    constants.append("    static constexpr {} {}_NV = {};".format(cpp_type, name, null_value))
        else:
            length = t.attrib.get("length", None)
            if length:
                lines.append("using {} = std::array<{}, {}>;".format(name, cpp_type, length))
            else:
                lines.append("using {} = {};".format(name, cpp_type))
    lines.append("\nstruct ConstValues {")
    for constant in constants:
        lines.append(constant)
    lines.append("};\n")
    return lines




def generate_enums(root, ns):
    lines = []
    for e in root.findall("types/enum", ns):
        name = e.attrib["name"]
        encoding = e.attrib.get("encodingType", "int32")
        cpp_type = TYPE_MAP.get(encoding.replace("NULL","").lower(), "int32_t")
        lines.append(f"enum class {name} : {cpp_type} {{")
        for v in e.findall("validValue"):
            vname = v.attrib["name"]
            vval = v.text.strip()
            if cpp_type == 'char':
                lines.append(f"    {vname} = '{vval}',")
            else:
                lines.append(f"    {vname} = {vval},")
        lines.append("};\n")
    return lines

def generate_sets(root, ns):
    lines = []
    for e in root.findall("types/set", ns):
        name = e.attrib["name"]
        encoding = e.attrib.get("encodingType", "uInt8")
        cpp_type = TYPE_MAP.get(encoding.replace("NULL", "").lower(), "int32_t")
        lines.append(f"using {name} = {cpp_type};")
        lines.append(f"struct {name}Set {{")
        for v in e.findall("choice"):
            vname = v.attrib["name"]
            vval = v.text.strip()
            lines.append(f"static constexpr size_t {vname} = {vval};")
        lines.append("};\n")
    return lines

def generate_composites(root, ns):
    lines = []
    for comp in root.findall("types/composite", ns):
        cname = comp.attrib["name"]
        lines.append("struct [[gnu::packed]] {} {{".format(cname))
        null_lines = []
        const_lines = []
        cur_len = 0
        for t in comp.findall("type"):
            type_name = t.attrib["name"]
            prim_type = t.attrib.get("primitiveType", None)
            cpp_type = TYPE_MAP.get(prim_type.lower(), None)
            null_value = t.attrib.get("nullValue", None)
            presence = t.attrib.get("presence", None)
            const_val = t.text.strip() if t.text else None
            offset = t.attrib.get("offset", None)
            if offset:
                padding_chars = int(offset) - cur_len
                lines.append(f"    char padding[{padding_chars}];")
            if presence == "optional" and null_value and cpp_type:
                lines.append(f"    {cpp_type} {type_name};")
                null_lines.append(f"    static constexpr {cpp_type} {type_name.upper()}_NV = {null_value};")
            elif presence == "constant" and const_val and cpp_type:
                const_lines.append(f"    static constexpr {cpp_type} {type_name.upper()} = {const_val};")
            else:
                lines.append(f"    {cpp_type} {type_name};")
            cur_len += TYPE_SIZE.get(prim_type, 0)

        lines.extend(null_lines)
        lines.extend(const_lines)
        lines.append("};\n")
    return lines

def generate_messages(root, ns, types_dict):
    lines = []
    for msg in root.findall("ns2:message", ns):
        msg_name = msg.attrib["name"]
        msg_id = msg.attrib["id"]
        msg_len = msg.attrib["blockLength"]
        lines.append(f"struct [[gnu::packed]] {msg_name} {{ // ID={msg_id}")
        
        # Fields
        cur_len = 0;
        for field in msg.findall("field"):
            f_name = field.attrib["name"]
            f_type = field.attrib["type"]
            cpp_type, len, option_values = cpp_type_from_xml(f_type, types_dict)
            if cpp_type == f_name:
                f_name = '{}{}'.format(f_name[0].lower(), f_name[1:])
            lines.append(f"    {cpp_type} {f_name};")
        
        # Groups
        # for group in msg.findall("group"):
        #     g_name = group.attrib["name"]
        #     g_dimensionType = group.attrib["dimensionType"]
        #     lines.append(f"    {g_dimensionType} {g_name}Size;")
        #     g_struct = f"{msg_name}_{g_name}"
        #     lines.append(f"    struct [[gnu::packed]] {g_struct} {{")
        #     for gfield in group.findall("field"):
        #         gf_name = gfield.attrib["name"]
        #         gf_type = gfield.attrib["type"]
        #         cpp_type = cpp_type_from_xml(gf_type, types_dict)
        #         lines.append(f"        {cpp_type} {gf_name};")
        #     lines.append("    };")
        #     lines.append(f"    std::vector<{g_struct}> {g_name};")
        
        lines.append("};\n")
    return lines

def generate_messages2(root, ns, constant_types):
    lines = []
    for msg in root.findall("ns2:message", ns):
        msg_name = msg.attrib["name"]
        msg_id = msg.attrib["id"]
        msg_length = msg.attrib["blockLength"]
        
        
        # Groups
        group_lines = []
        group_type_lines = []
        for group in msg.findall("group"):
            g_name = group.attrib["name"]
            g_length = group.attrib["blockLength"]
            g_dimensionType = group.attrib["dimensionType"]
            group_type_name = "{}_{}".format(msg_name, g_name[2:])
            group_lines.append("struct [[gnu::packed]] {}_{} {{".format(msg_name, g_name[2:]))
            group_lines.append("    static constexpr size_t MSG_LEN = {};".format(g_length))
            group_lines.append(f"    {g_dimensionType} dimension;")
            group_lines.append("    using Dimension_t = {};".format(g_dimensionType))
            group_type_lines.append("    using {}_t = {};".format(g_name[2:], group_type_name))
            for gfield in group.findall("field"):
                gf_name = gfield.attrib["name"]
                gf_type = gfield.attrib["type"]
                field_offset = gfield.attrib.get("offset", None)
                if field_offset:
                    group_lines.append("    {} {}{};".format(gf_type, gf_name[0].lower(), gf_name[1:]))
            group_lines.append("};\n")
        lines.extend(group_lines)

        # Fields
        lines.append("struct [[gnu::packed]] {} {{ // ID={}".format(msg_name, msg_id))
        lines.append("    static constexpr size_t MSG_LEN = {};".format(msg_length))
        for field in msg.findall("field"):
            f_name = field.attrib["name"]
            f_type = field.attrib["type"]
            field_offset = field.attrib.get("offset", None)
            if field_offset:
                lines.append("    {} {}{};".format(f_type, f_name[0].lower(), f_name[1:]))
        
        lines.extend(group_type_lines)
        lines.append("};\n")
    return lines

def generate_structs(xml_file):
    tree = ET.parse(xml_file)
    root = tree.getroot()
    ns = {"ns2": "http://www.fixprotocol.org/ns/simple/1.0"}


    cpp_lines = [
        "#pragma once",
        "#include <cstdint>",
        "#include <array>",
        "",
    ]

    id_type_dict = {}
    constant_types = {}

    cpp_lines += parse_types2(root, ns, constant_types)
    cpp_lines += generate_enums(root, ns)
    cpp_lines += generate_sets(root, ns)
    cpp_lines += generate_composites(root, ns)
    cpp_lines += generate_messages2(root, ns, constant_types)

    return "\n".join(cpp_lines)

if __name__ == "__main__":
    cpp_code = generate_structs("templates_FixBinary.xml")
    with open("mdp3_structs.hpp", "w") as f:
        f.write(cpp_code)
    print("Generated mdp3_structs.hpp")
