# cme_mdp3_cpp_generator
Generate C++ header file from cme mdp template file


## Usage

Run `python3 code_generatory.py`. The generated file is `mdp3_struct.hpp`. Make sure template file is in the same folder as the python file.

## Features

1. Constants are defined with `static constexpr`
2. Sets are defined with struct with all members are `static constexpr size_t`. The members are the names for each bit position.
3. For messages, `blockLength` is defined in the struct with `static constexpr size_t`. each group type in a message is defined in a standalone struct including dimension.
4. Enums are defined with `enum class`.
5. When parsing the message, just do `reinterpret_cast<MessageType*>` to do message parsing by taking consideration of block length and dimension size.
