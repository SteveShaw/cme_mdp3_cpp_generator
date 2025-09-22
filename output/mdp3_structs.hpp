#pragma once
#include <cstdint>
#include <array>

using Asset = std::array<char, 6>;
using CFICode = std::array<char, 6>;
using CHAR = char;
using CountryCode = std::array<char, 2>;
using Currency = std::array<char, 3>;
using Int16 = int16_t;
using Int32 = int32_t;
using Int32NULL = int32_t;
using Int8 = int8_t;
using Int8NULL = int8_t;
using LocalMktDate = uint16_t;
using LongName = std::array<char, 35>;
using MDFeedType = std::array<char, 3>;
using QuoteReqId = std::array<char, 23>;
using SecurityExchange = std::array<char, 4>;
using SecurityGroup = std::array<char, 6>;
using SecuritySubType = std::array<char, 5>;
using SecurityType = std::array<char, 6>;
using String12 = std::array<char, 12>;
using String20 = std::array<char, 20>;
using String25 = std::array<char, 25>;
using String3 = std::array<char, 3>;
using String5 = std::array<char, 5>;
using String6 = std::array<char, 6>;
using String7 = std::array<char, 7>;
using String8 = std::array<char, 8>;
using Symbol = std::array<char, 20>;
using Text = std::array<char, 180>;
using UnderlyingSymbol = std::array<char, 20>;
using UnitOfMeasure = std::array<char, 30>;
using UserDefinedInstrument = std::array<char, 1>;
using uInt16 = uint16_t;
using uInt16NULL = uint16_t;
using uInt32 = uint32_t;
using uInt32NULL = uint32_t;
using uInt64 = uint64_t;
using uInt64NULL = uint64_t;
using uInt8 = uint8_t;
using uInt8NULL = uint8_t;

struct ConstValues {
    static constexpr int8_t InstAttribType= 24;
    static constexpr int32_t Int32NULL_NV = 2147483647;
    static constexpr int8_t Int8NULL_NV = 127;
    static constexpr uint16_t LocalMktDate_NV = 65535;
    static constexpr char MDEntryTypeChannelReset= 'J';
    static constexpr char MDEntryTypeLimits= 'g';
    static constexpr char MDEntryTypeTrade= '2';
    static constexpr char MDEntryTypeVol= 'e';
    static constexpr int8_t MDUpdateActionNew= 0;
    static constexpr int8_t MDUpdateTypeNew= 0;
    static constexpr uint8_t SecurityAltIDSourceISIN= 4;
    static constexpr char SecurityIDSource= '8';
    static constexpr uint16_t uInt16NULL_NV = 65535;
    static constexpr uint32_t uInt32NULL_NV = 4294967295;
    static constexpr uint64_t uInt64NULL_NV = 18446744073709551615ULL;
    static constexpr uint8_t uInt8NULL_NV = 255;
};

enum class AggressorFlag : uint8_t {
    NotAggressor = 0,
    Aggressor = 1,
};

enum class AggressorSide : uint8_t {
    NoAggressor = 0,
    Buy = 1,
    Sell = 2,
};

enum class EventType : uint8_t {
    Activation = 5,
    LastEligibleTradeDate = 7,
};

enum class HaltReason : uint8_t {
    GroupSchedule = 0,
    SurveillanceIntervention = 1,
    MarketEvent = 2,
    InstrumentActivation = 3,
    InstrumentExpiration = 4,
    Unknown = 5,
    RecoveryInProcess = 6,
    TradeDateRoll = 7,
};

enum class LegSide : uint8_t {
    BuySide = 1,
    SellSide = 2,
};

enum class MDEntryType : char {
    Bid = '0',
    Offer = '1',
    Trade = '2',
    OpenPrice = '4',
    SettlementPrice = '6',
    TradingSessionHighPrice = '7',
    TradingSessionLowPrice = '8',
    VWAP = '9',
    ClearedVolume = 'B',
    OpenInterest = 'C',
    ImpliedBid = 'E',
    ImpliedOffer = 'F',
    BookReset = 'J',
    SessionHighBid = 'N',
    SessionLowOffer = 'O',
    FixingPrice = 'W',
    ElectronicVolume = 'e',
    ThresholdLimitsandPriceBandVariation = 'g',
    MarketBestOffer = 'w',
    MarketBestBid = 'x',
};

enum class MDEntryTypeBook : char {
    Bid = '0',
    Offer = '1',
    ImpliedBid = 'E',
    ImpliedOffer = 'F',
    BookReset = 'J',
    MarketBestOffer = 'w',
    MarketBestBid = 'x',
};

enum class MDEntryTypeDailyStatistics : char {
    SettlementPrice = '6',
    ClearedVolume = 'B',
    OpenInterest = 'C',
    FixingPrice = 'W',
};

enum class MDEntryTypeStatistics : char {
    OpenPrice = '4',
    HighTrade = '7',
    LowTrade = '8',
    VWAP = '9',
    HighestBid = 'N',
    LowestOffer = 'O',
};

enum class MDUpdateAction : uint8_t {
    New = 0,
    Change = 1,
    Delete = 2,
    DeleteThru = 3,
    DeleteFrom = 4,
    Overlay = 5,
};

enum class MoneyOrPar : uint8_t {
    Money = 1,
    Par = 2,
};

enum class OpenCloseSettlFlag : uint8_t {
    DailyOpenPrice = 0,
    IndicativeOpeningPrice = 5,
    IntradayVWAP = 100,
    RepoAverage8_30AM = 101,
    RepoAverage10AM = 102,
    PrevSessionRepoAverage10AM = 103,
};

enum class OrderUpdateAction : uint8_t {
    New = 0,
    Update = 1,
    Delete = 2,
};

enum class PriceSource : uint8_t {
    MarketPlaceAssistant = 0,
    Globex = 1,
    Refinitiv = 2,
    ICAP = 3,
};

enum class PutOrCall : uint8_t {
    Put = 0,
    Call = 1,
};

enum class RepoSubType : uint8_t {
    Special = 0,
    GC = 1,
    GCForDBV = 2,
};

enum class SecurityAltIDSource : uint8_t {
    CUSIP = 1,
    ISIN = 4,
};

enum class SecurityTradingEvent : uint8_t {
    NoEvent = 0,
    NoCancel = 1,
    ResetStatistics = 4,
    ImpliedMatchingON = 5,
    ImpliedMatchingOFF = 6,
    EndOfWorkup = 7,
};

enum class SecurityTradingStatus : uint8_t {
    TradingHalt = 2,
    Close = 4,
    NewPriceIndication = 15,
    ReadyToTrade = 17,
    NotAvailableForTrading = 18,
    UnknownorInvalid = 20,
    PreOpen = 21,
    PreCross = 24,
    Cross = 25,
    PostClose = 26,
    NoChange = 103,
    PrivateWorkup = 201,
    PublicWorkup = 202,
};

enum class SecurityUpdateAction : char {
    Add = 'A',
    Delete = 'D',
    Modify = 'M',
};

enum class Side : uint8_t {
    Buy = 1,
    Sell = 2,
};

enum class WorkupTradingStatus : uint8_t {
    ReadyToTrade = 17,
    NotAvailableForTrading = 18,
    PrivateWorkup = 201,
    PublicWorkup = 202,
};

using InstAttribValue = uint32_t;
struct InstAttribValueSet {
static constexpr size_t ElectronicMatchEligible = 0;
static constexpr size_t OrderCrossEligible = 1;
static constexpr size_t BlockTradeEligible = 2;
static constexpr size_t EFPEligible = 3;
static constexpr size_t EBFEligible = 4;
static constexpr size_t EFSEligible = 5;
static constexpr size_t EFREligible = 6;
static constexpr size_t OTCEligible = 7;
static constexpr size_t iLinkIndicativeMassQuotingEligible = 8;
static constexpr size_t NegativeStrikeEligible = 9;
static constexpr size_t NegativePriceOutrightEligible = 10;
static constexpr size_t IsFractional = 11;
static constexpr size_t VolatilityQuotedOption = 12;
static constexpr size_t RFQCrossEligible = 13;
static constexpr size_t ZeroPriceOutrightEligible = 14;
static constexpr size_t DecayingProductEligibility = 15;
static constexpr size_t VariableProductEligibility = 16;
static constexpr size_t DailyProductEligibility = 17;
static constexpr size_t GTOrdersEligibility = 18;
static constexpr size_t ImpliedMatchingEligibility = 19;
static constexpr size_t TriangulationEligible = 20;
static constexpr size_t VariableCabEligible = 21;
static constexpr size_t InvertedBook = 22;
static constexpr size_t IsAoNInstrument = 23;
static constexpr size_t SEFRegulated = 24;
static constexpr size_t MTFRegulated = 25;
static constexpr size_t eFIXInstrument = 26;
static constexpr size_t HedgeInstrument = 27;
};

using MatchEventIndicator = uint8_t;
struct MatchEventIndicatorSet {
static constexpr size_t LastTradeMsg = 0;
static constexpr size_t LastVolumeMsg = 1;
static constexpr size_t LastQuoteMsg = 2;
static constexpr size_t LastStatsMsg = 3;
static constexpr size_t LastImpliedMsg = 4;
static constexpr size_t RecoveryMsg = 5;
static constexpr size_t Reserved = 6;
static constexpr size_t EndOfEvent = 7;
};

using SettlPriceType = uint8_t;
struct SettlPriceTypeSet {
static constexpr size_t FinalDaily = 0;
static constexpr size_t Actual = 1;
static constexpr size_t Rounded = 2;
static constexpr size_t Intraday = 3;
static constexpr size_t ReservedBits = 4;
static constexpr size_t NullValue = 7;
};

struct [[gnu::packed]] Decimal9 {
    int64_t mantissa;
    static constexpr int8_t EXPONENT = -9;
};

struct [[gnu::packed]] Decimal9NULL {
    int64_t mantissa;
    static constexpr int64_t MANTISSA_NV = 9223372036854775807;
    static constexpr int8_t EXPONENT = -9;
};

struct [[gnu::packed]] DecimalQty {
    int32_t mantissa;
    static constexpr int32_t MANTISSA_NV = 2147483647;
    static constexpr int8_t EXPONENT = -4;
};

struct [[gnu::packed]] MaturityMonthYear {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t week;
    static constexpr uint16_t YEAR_NV = 65535;
    static constexpr uint8_t MONTH_NV = 255;
    static constexpr uint8_t DAY_NV = 255;
    static constexpr uint8_t WEEK_NV = 255;
};

struct [[gnu::packed]] PRICE9 {
    int64_t mantissa;
    static constexpr int8_t EXPONENT = -9;
};

struct [[gnu::packed]] PRICENULL9 {
    int64_t mantissa;
    static constexpr int64_t MANTISSA_NV = 9223372036854775807;
    static constexpr int8_t EXPONENT = -9;
};

struct [[gnu::packed]] groupSize {
    uint16_t blockLength;
    uint8_t numInGroup;
};

struct [[gnu::packed]] groupSize8Byte {
    uint16_t blockLength;
    char padding[5];
    uint8_t numInGroup;
};

struct [[gnu::packed]] groupSizeEncoding {
    uint16_t blockLength;
    uint16_t numInGroup;
};

struct [[gnu::packed]] messageHeader {
    uint16_t blockLength;
    uint16_t templateId;
    uint16_t schemaId;
    uint16_t version;
};

struct [[gnu::packed]] ChannelReset4_MDEntries {
    static constexpr size_t MSG_LEN = 2;
    groupSize dimension;
    using Dimension_t = groupSize;
    Int16 applID;
};

struct [[gnu::packed]] ChannelReset4 { // ID=4
    static constexpr size_t MSG_LEN = 9;
    uInt64 transactTime;
    MatchEventIndicator matchEventIndicator;
    using MDEntries_t = ChannelReset4_MDEntries;
};

struct [[gnu::packed]] AdminHeartbeat12 { // ID=12
    static constexpr size_t MSG_LEN = 0;
};

struct [[gnu::packed]] AdminLogin15 { // ID=15
    static constexpr size_t MSG_LEN = 1;
    Int8 heartBtInt;
};

struct [[gnu::packed]] AdminLogout16 { // ID=16
    static constexpr size_t MSG_LEN = 180;
    Text text;
};

struct [[gnu::packed]] SecurityStatus30 { // ID=30
    static constexpr size_t MSG_LEN = 30;
    uInt64 transactTime;
    SecurityGroup securityGroup;
    Asset asset;
    Int32NULL securityID;
    LocalMktDate tradeDate;
    MatchEventIndicator matchEventIndicator;
    SecurityTradingStatus securityTradingStatus;
    HaltReason haltReason;
    SecurityTradingEvent securityTradingEvent;
};

struct [[gnu::packed]] MDIncrementalRefreshVolume37_MDEntries {
    static constexpr size_t MSG_LEN = 16;
    groupSize dimension;
    using Dimension_t = groupSize;
    Int32 mDEntrySize;
    Int32 securityID;
    uInt32 rptSeq;
    MDUpdateAction mDUpdateAction;
};

struct [[gnu::packed]] MDIncrementalRefreshVolume37 { // ID=37
    static constexpr size_t MSG_LEN = 11;
    uInt64 transactTime;
    MatchEventIndicator matchEventIndicator;
    using MDEntries_t = MDIncrementalRefreshVolume37_MDEntries;
};

struct [[gnu::packed]] QuoteRequest39_RelatedSym {
    static constexpr size_t MSG_LEN = 32;
    groupSize dimension;
    using Dimension_t = groupSize;
    Symbol symbol;
    Int32 securityID;
    Int32NULL orderQty;
    Int8 quoteType;
    Int8NULL side;
};

struct [[gnu::packed]] QuoteRequest39 { // ID=39
    static constexpr size_t MSG_LEN = 35;
    uInt64 transactTime;
    QuoteReqId quoteReqID;
    MatchEventIndicator matchEventIndicator;
    using RelatedSym_t = QuoteRequest39_RelatedSym;
};

struct [[gnu::packed]] MDIncrementalRefreshBook46_MDEntries {
    static constexpr size_t MSG_LEN = 32;
    groupSize dimension;
    using Dimension_t = groupSize;
    PRICENULL9 mDEntryPx;
    Int32NULL mDEntrySize;
    Int32 securityID;
    uInt32 rptSeq;
    Int32NULL numberOfOrders;
    uInt8 mDPriceLevel;
    MDUpdateAction mDUpdateAction;
    MDEntryTypeBook mDEntryType;
    Int32NULL tradeableSize;
};

struct [[gnu::packed]] MDIncrementalRefreshBook46_OrderIDEntries {
    static constexpr size_t MSG_LEN = 24;
    groupSize8Byte dimension;
    using Dimension_t = groupSize8Byte;
    uInt64 orderID;
    uInt64NULL mDOrderPriority;
    Int32NULL mDDisplayQty;
    uInt8NULL referenceID;
    OrderUpdateAction orderUpdateAction;
};

struct [[gnu::packed]] MDIncrementalRefreshBook46 { // ID=46
    static constexpr size_t MSG_LEN = 11;
    uInt64 transactTime;
    MatchEventIndicator matchEventIndicator;
    using MDEntries_t = MDIncrementalRefreshBook46_MDEntries;
    using OrderIDEntries_t = MDIncrementalRefreshBook46_OrderIDEntries;
};

struct [[gnu::packed]] MDIncrementalRefreshOrderBook47_MDEntries {
    static constexpr size_t MSG_LEN = 40;
    groupSize dimension;
    using Dimension_t = groupSize;
    uInt64NULL orderID;
    uInt64NULL mDOrderPriority;
    PRICENULL9 mDEntryPx;
    Int32NULL mDDisplayQty;
    Int32 securityID;
    MDUpdateAction mDUpdateAction;
    MDEntryTypeBook mDEntryType;
};

struct [[gnu::packed]] MDIncrementalRefreshOrderBook47 { // ID=47
    static constexpr size_t MSG_LEN = 11;
    uInt64 transactTime;
    MatchEventIndicator matchEventIndicator;
    using MDEntries_t = MDIncrementalRefreshOrderBook47_MDEntries;
};

struct [[gnu::packed]] MDIncrementalRefreshTradeSummary48_MDEntries {
    static constexpr size_t MSG_LEN = 32;
    groupSize dimension;
    using Dimension_t = groupSize;
    PRICE9 mDEntryPx;
    Int32 mDEntrySize;
    Int32 securityID;
    uInt32 rptSeq;
    Int32 numberOfOrders;
    AggressorSide aggressorSide;
    MDUpdateAction mDUpdateAction;
    uInt32NULL mDTradeEntryID;
};

struct [[gnu::packed]] MDIncrementalRefreshTradeSummary48_OrderIDEntries {
    static constexpr size_t MSG_LEN = 16;
    groupSize8Byte dimension;
    using Dimension_t = groupSize8Byte;
    uInt64 orderID;
    Int32 lastQty;
};

struct [[gnu::packed]] MDIncrementalRefreshTradeSummary48 { // ID=48
    static constexpr size_t MSG_LEN = 11;
    uInt64 transactTime;
    MatchEventIndicator matchEventIndicator;
    using MDEntries_t = MDIncrementalRefreshTradeSummary48_MDEntries;
    using OrderIDEntries_t = MDIncrementalRefreshTradeSummary48_OrderIDEntries;
};

struct [[gnu::packed]] MDIncrementalRefreshDailyStatistics49_MDEntries {
    static constexpr size_t MSG_LEN = 32;
    groupSize dimension;
    using Dimension_t = groupSize;
    PRICENULL9 mDEntryPx;
    Int32NULL mDEntrySize;
    Int32 securityID;
    uInt32 rptSeq;
    LocalMktDate tradingReferenceDate;
    SettlPriceType settlPriceType;
    MDUpdateAction mDUpdateAction;
    MDEntryTypeDailyStatistics mDEntryType;
};

struct [[gnu::packed]] MDIncrementalRefreshDailyStatistics49 { // ID=49
    static constexpr size_t MSG_LEN = 11;
    uInt64 transactTime;
    MatchEventIndicator matchEventIndicator;
    using MDEntries_t = MDIncrementalRefreshDailyStatistics49_MDEntries;
};

struct [[gnu::packed]] MDIncrementalRefreshLimitsBanding50_MDEntries {
    static constexpr size_t MSG_LEN = 32;
    groupSize dimension;
    using Dimension_t = groupSize;
    PRICENULL9 highLimitPrice;
    PRICENULL9 lowLimitPrice;
    PRICENULL9 maxPriceVariation;
    Int32 securityID;
    uInt32 rptSeq;
};

struct [[gnu::packed]] MDIncrementalRefreshLimitsBanding50 { // ID=50
    static constexpr size_t MSG_LEN = 11;
    uInt64 transactTime;
    MatchEventIndicator matchEventIndicator;
    using MDEntries_t = MDIncrementalRefreshLimitsBanding50_MDEntries;
};

struct [[gnu::packed]] MDIncrementalRefreshSessionStatistics51_MDEntries {
    static constexpr size_t MSG_LEN = 24;
    groupSize dimension;
    using Dimension_t = groupSize;
    PRICE9 mDEntryPx;
    Int32 securityID;
    uInt32 rptSeq;
    OpenCloseSettlFlag openCloseSettlFlag;
    MDUpdateAction mDUpdateAction;
    MDEntryTypeStatistics mDEntryType;
    Int32NULL mDEntrySize;
};

struct [[gnu::packed]] MDIncrementalRefreshSessionStatistics51 { // ID=51
    static constexpr size_t MSG_LEN = 11;
    uInt64 transactTime;
    MatchEventIndicator matchEventIndicator;
    using MDEntries_t = MDIncrementalRefreshSessionStatistics51_MDEntries;
};

struct [[gnu::packed]] SnapshotFullRefresh52_MDEntries {
    static constexpr size_t MSG_LEN = 22;
    groupSize dimension;
    using Dimension_t = groupSize;
    PRICENULL9 mDEntryPx;
    Int32NULL mDEntrySize;
    Int32NULL numberOfOrders;
    Int8NULL mDPriceLevel;
    LocalMktDate tradingReferenceDate;
    OpenCloseSettlFlag openCloseSettlFlag;
    SettlPriceType settlPriceType;
    MDEntryType mDEntryType;
};

struct [[gnu::packed]] SnapshotFullRefresh52 { // ID=52
    static constexpr size_t MSG_LEN = 59;
    uInt32 lastMsgSeqNumProcessed;
    uInt32 totNumReports;
    Int32 securityID;
    uInt32 rptSeq;
    uInt64 transactTime;
    uInt64 lastUpdateTime;
    LocalMktDate tradeDate;
    SecurityTradingStatus mDSecurityTradingStatus;
    PRICENULL9 highLimitPrice;
    PRICENULL9 lowLimitPrice;
    PRICENULL9 maxPriceVariation;
    using MDEntries_t = SnapshotFullRefresh52_MDEntries;
};

struct [[gnu::packed]] SnapshotFullRefreshOrderBook53_MDEntries {
    static constexpr size_t MSG_LEN = 29;
    groupSize dimension;
    using Dimension_t = groupSize;
    uInt64 orderID;
    uInt64NULL mDOrderPriority;
    PRICE9 mDEntryPx;
    Int32 mDDisplayQty;
    MDEntryTypeBook mDEntryType;
};

struct [[gnu::packed]] SnapshotFullRefreshOrderBook53 { // ID=53
    static constexpr size_t MSG_LEN = 28;
    uInt32 lastMsgSeqNumProcessed;
    uInt32 totNumReports;
    Int32 securityID;
    uInt32 noChunks;
    uInt32 currentChunk;
    uInt64 transactTime;
    using MDEntries_t = SnapshotFullRefreshOrderBook53_MDEntries;
};

struct [[gnu::packed]] MDInstrumentDefinitionFuture54_Events {
    static constexpr size_t MSG_LEN = 9;
    groupSize dimension;
    using Dimension_t = groupSize;
    EventType eventType;
    uInt64 eventTime;
};

struct [[gnu::packed]] MDInstrumentDefinitionFuture54_MDFeedTypes {
    static constexpr size_t MSG_LEN = 4;
    groupSize dimension;
    using Dimension_t = groupSize;
    MDFeedType mDFeedType;
    Int8 marketDepth;
};

struct [[gnu::packed]] MDInstrumentDefinitionFuture54_InstAttrib {
    static constexpr size_t MSG_LEN = 4;
    groupSize dimension;
    using Dimension_t = groupSize;
    InstAttribValue instAttribValue;
};

struct [[gnu::packed]] MDInstrumentDefinitionFuture54_LotTypeRules {
    static constexpr size_t MSG_LEN = 5;
    groupSize dimension;
    using Dimension_t = groupSize;
    Int8 lotType;
    DecimalQty minLotSize;
};

struct [[gnu::packed]] MDInstrumentDefinitionFuture54 { // ID=54
    static constexpr size_t MSG_LEN = 224;
    MatchEventIndicator matchEventIndicator;
    uInt32NULL totNumReports;
    SecurityUpdateAction securityUpdateAction;
    uInt64 lastUpdateTime;
    SecurityTradingStatus mDSecurityTradingStatus;
    Int16 applID;
    uInt8 marketSegmentID;
    uInt8 underlyingProduct;
    SecurityExchange securityExchange;
    SecurityGroup securityGroup;
    Asset asset;
    Symbol symbol;
    Int32 securityID;
    SecurityType securityType;
    CFICode cFICode;
    MaturityMonthYear maturityMonthYear;
    Currency currency;
    Currency settlCurrency;
    CHAR matchAlgorithm;
    uInt32 minTradeVol;
    uInt32 maxTradeVol;
    PRICE9 minPriceIncrement;
    Decimal9 displayFactor;
    uInt8NULL mainFraction;
    uInt8NULL subFraction;
    uInt8NULL priceDisplayFormat;
    UnitOfMeasure unitOfMeasure;
    Decimal9NULL unitOfMeasureQty;
    PRICENULL9 tradingReferencePrice;
    SettlPriceType settlPriceType;
    Int32NULL openInterestQty;
    Int32NULL clearedVolume;
    PRICENULL9 highLimitPrice;
    PRICENULL9 lowLimitPrice;
    PRICENULL9 maxPriceVariation;
    Int32NULL decayQuantity;
    LocalMktDate decayStartDate;
    Int32NULL originalContractSize;
    Int32NULL contractMultiplier;
    Int8NULL contractMultiplierUnit;
    Int8NULL flowScheduleType;
    PRICENULL9 minPriceIncrementAmount;
    UserDefinedInstrument userDefinedInstrument;
    LocalMktDate tradingReferenceDate;
    uInt64NULL instrumentGUID;
    using Events_t = MDInstrumentDefinitionFuture54_Events;
    using MDFeedTypes_t = MDInstrumentDefinitionFuture54_MDFeedTypes;
    using InstAttrib_t = MDInstrumentDefinitionFuture54_InstAttrib;
    using LotTypeRules_t = MDInstrumentDefinitionFuture54_LotTypeRules;
};

struct [[gnu::packed]] MDInstrumentDefinitionOption55_Events {
    static constexpr size_t MSG_LEN = 9;
    groupSize dimension;
    using Dimension_t = groupSize;
    EventType eventType;
    uInt64 eventTime;
};

struct [[gnu::packed]] MDInstrumentDefinitionOption55_MDFeedTypes {
    static constexpr size_t MSG_LEN = 4;
    groupSize dimension;
    using Dimension_t = groupSize;
    MDFeedType mDFeedType;
    Int8 marketDepth;
};

struct [[gnu::packed]] MDInstrumentDefinitionOption55_InstAttrib {
    static constexpr size_t MSG_LEN = 4;
    groupSize dimension;
    using Dimension_t = groupSize;
    InstAttribValue instAttribValue;
};

struct [[gnu::packed]] MDInstrumentDefinitionOption55_LotTypeRules {
    static constexpr size_t MSG_LEN = 5;
    groupSize dimension;
    using Dimension_t = groupSize;
    Int8 lotType;
    DecimalQty minLotSize;
};

struct [[gnu::packed]] MDInstrumentDefinitionOption55_Underlyings {
    static constexpr size_t MSG_LEN = 24;
    groupSize dimension;
    using Dimension_t = groupSize;
    Int32 underlyingSecurityID;
    UnderlyingSymbol underlyingSymbol;
};

struct [[gnu::packed]] MDInstrumentDefinitionOption55_RelatedInstruments {
    static constexpr size_t MSG_LEN = 24;
    groupSize dimension;
    using Dimension_t = groupSize;
    Int32 relatedSecurityID;
    Symbol relatedSymbol;
};

struct [[gnu::packed]] MDInstrumentDefinitionOption55 { // ID=55
    static constexpr size_t MSG_LEN = 221;
    MatchEventIndicator matchEventIndicator;
    uInt32NULL totNumReports;
    SecurityUpdateAction securityUpdateAction;
    uInt64 lastUpdateTime;
    SecurityTradingStatus mDSecurityTradingStatus;
    Int16 applID;
    uInt8 marketSegmentID;
    uInt8 underlyingProduct;
    SecurityExchange securityExchange;
    SecurityGroup securityGroup;
    Asset asset;
    Symbol symbol;
    Int32 securityID;
    SecurityType securityType;
    CFICode cFICode;
    PutOrCall putOrCall;
    MaturityMonthYear maturityMonthYear;
    Currency currency;
    PRICENULL9 strikePrice;
    Currency strikeCurrency;
    Currency settlCurrency;
    PRICENULL9 minCabPrice;
    CHAR matchAlgorithm;
    uInt32 minTradeVol;
    uInt32 maxTradeVol;
    PRICENULL9 minPriceIncrement;
    PRICENULL9 minPriceIncrementAmount;
    Decimal9 displayFactor;
    Int8NULL tickRule;
    uInt8NULL mainFraction;
    uInt8NULL subFraction;
    uInt8NULL priceDisplayFormat;
    UnitOfMeasure unitOfMeasure;
    Decimal9NULL unitOfMeasureQty;
    PRICENULL9 tradingReferencePrice;
    SettlPriceType settlPriceType;
    Int32NULL clearedVolume;
    Int32NULL openInterestQty;
    PRICENULL9 lowLimitPrice;
    PRICENULL9 highLimitPrice;
    UserDefinedInstrument userDefinedInstrument;
    LocalMktDate tradingReferenceDate;
    uInt64NULL instrumentGUID;
    using Events_t = MDInstrumentDefinitionOption55_Events;
    using MDFeedTypes_t = MDInstrumentDefinitionOption55_MDFeedTypes;
    using InstAttrib_t = MDInstrumentDefinitionOption55_InstAttrib;
    using LotTypeRules_t = MDInstrumentDefinitionOption55_LotTypeRules;
    using Underlyings_t = MDInstrumentDefinitionOption55_Underlyings;
    using RelatedInstruments_t = MDInstrumentDefinitionOption55_RelatedInstruments;
};

struct [[gnu::packed]] MDInstrumentDefinitionSpread56_Events {
    static constexpr size_t MSG_LEN = 9;
    groupSize dimension;
    using Dimension_t = groupSize;
    EventType eventType;
    uInt64 eventTime;
};

struct [[gnu::packed]] MDInstrumentDefinitionSpread56_MDFeedTypes {
    static constexpr size_t MSG_LEN = 4;
    groupSize dimension;
    using Dimension_t = groupSize;
    MDFeedType mDFeedType;
    Int8 marketDepth;
};

struct [[gnu::packed]] MDInstrumentDefinitionSpread56_InstAttrib {
    static constexpr size_t MSG_LEN = 4;
    groupSize dimension;
    using Dimension_t = groupSize;
    InstAttribValue instAttribValue;
};

struct [[gnu::packed]] MDInstrumentDefinitionSpread56_LotTypeRules {
    static constexpr size_t MSG_LEN = 5;
    groupSize dimension;
    using Dimension_t = groupSize;
    Int8 lotType;
    DecimalQty minLotSize;
};

struct [[gnu::packed]] MDInstrumentDefinitionSpread56_Legs {
    static constexpr size_t MSG_LEN = 18;
    groupSize dimension;
    using Dimension_t = groupSize;
    Int32 legSecurityID;
    LegSide legSide;
    Int8 legRatioQty;
    PRICENULL9 legPrice;
    DecimalQty legOptionDelta;
};

struct [[gnu::packed]] MDInstrumentDefinitionSpread56 { // ID=56
    static constexpr size_t MSG_LEN = 255;
    MatchEventIndicator matchEventIndicator;
    uInt32NULL totNumReports;
    SecurityUpdateAction securityUpdateAction;
    uInt64 lastUpdateTime;
    SecurityTradingStatus mDSecurityTradingStatus;
    Int16 applID;
    uInt8 marketSegmentID;
    uInt8NULL underlyingProduct;
    SecurityExchange securityExchange;
    SecurityGroup securityGroup;
    Asset asset;
    Symbol symbol;
    Int32 securityID;
    SecurityType securityType;
    CFICode cFICode;
    MaturityMonthYear maturityMonthYear;
    Currency currency;
    SecuritySubType securitySubType;
    UserDefinedInstrument userDefinedInstrument;
    CHAR matchAlgorithm;
    uInt32 minTradeVol;
    uInt32 maxTradeVol;
    PRICENULL9 minPriceIncrement;
    Decimal9 displayFactor;
    uInt8NULL priceDisplayFormat;
    PRICENULL9 priceRatio;
    Int8NULL tickRule;
    UnitOfMeasure unitOfMeasure;
    PRICENULL9 tradingReferencePrice;
    SettlPriceType settlPriceType;
    Int32NULL openInterestQty;
    Int32NULL clearedVolume;
    PRICENULL9 highLimitPrice;
    PRICENULL9 lowLimitPrice;
    PRICENULL9 maxPriceVariation;
    uInt8NULL mainFraction;
    uInt8NULL subFraction;
    LocalMktDate tradingReferenceDate;
    String5 priceQuoteMethod;
    String6 riskSet;
    String6 marketSet;
    uInt64NULL instrumentGUID;
    LongName financialInstrumentFullName;
    using Events_t = MDInstrumentDefinitionSpread56_Events;
    using MDFeedTypes_t = MDInstrumentDefinitionSpread56_MDFeedTypes;
    using InstAttrib_t = MDInstrumentDefinitionSpread56_InstAttrib;
    using LotTypeRules_t = MDInstrumentDefinitionSpread56_LotTypeRules;
    using Legs_t = MDInstrumentDefinitionSpread56_Legs;
};

struct [[gnu::packed]] MDInstrumentDefinitionFixedIncome57_Events {
    static constexpr size_t MSG_LEN = 9;
    groupSize dimension;
    using Dimension_t = groupSize;
    EventType eventType;
    uInt64 eventTime;
};

struct [[gnu::packed]] MDInstrumentDefinitionFixedIncome57_MDFeedTypes {
    static constexpr size_t MSG_LEN = 4;
    groupSize dimension;
    using Dimension_t = groupSize;
    MDFeedType mDFeedType;
    Int8 marketDepth;
};

struct [[gnu::packed]] MDInstrumentDefinitionFixedIncome57_InstAttrib {
    static constexpr size_t MSG_LEN = 4;
    groupSize dimension;
    using Dimension_t = groupSize;
    InstAttribValue instAttribValue;
};

struct [[gnu::packed]] MDInstrumentDefinitionFixedIncome57_LotTypeRules {
    static constexpr size_t MSG_LEN = 5;
    groupSize dimension;
    using Dimension_t = groupSize;
    Int8 lotType;
    DecimalQty minLotSize;
};

struct [[gnu::packed]] MDInstrumentDefinitionFixedIncome57 { // ID=57
    static constexpr size_t MSG_LEN = 338;
    MatchEventIndicator matchEventIndicator;
    uInt32NULL totNumReports;
    SecurityUpdateAction securityUpdateAction;
    uInt64 lastUpdateTime;
    SecurityTradingStatus mDSecurityTradingStatus;
    Int16 applID;
    uInt8 marketSegmentID;
    uInt8 underlyingProduct;
    SecurityExchange securityExchange;
    SecurityGroup securityGroup;
    Asset asset;
    Symbol symbol;
    Int32 securityID;
    SecurityType securityType;
    CFICode cFICode;
    Currency currency;
    Currency settlCurrency;
    CHAR matchAlgorithm;
    uInt32 minTradeVol;
    uInt32 maxTradeVol;
    PRICENULL9 minPriceIncrement;
    Decimal9 displayFactor;
    uInt8NULL mainFraction;
    uInt8NULL subFraction;
    uInt8NULL priceDisplayFormat;
    UnitOfMeasure unitOfMeasure;
    Decimal9NULL unitOfMeasureQty;
    PRICENULL9 tradingReferencePrice;
    LocalMktDate tradingReferenceDate;
    PRICENULL9 highLimitPrice;
    PRICENULL9 lowLimitPrice;
    PRICENULL9 maxPriceVariation;
    PRICENULL9 minPriceIncrementAmount;
    LocalMktDate issueDate;
    LocalMktDate datedDate;
    LocalMktDate maturityDate;
    Decimal9NULL couponRate;
    PRICENULL9 parValue;
    String3 couponFrequencyUnit;
    uInt16NULL couponFrequencyPeriod;
    String20 couponDayCount;
    CountryCode countryOfIssue;
    String25 issuer;
    LongName financialInstrumentFullName;
    String12 securityAltID;
    SecurityAltIDSource securityAltIDSource;
    String5 priceQuoteMethod;
    String5 partyRoleClearingOrg;
    UserDefinedInstrument userDefinedInstrument;
    String6 riskSet;
    String6 marketSet;
    uInt64NULL instrumentGUID;
    using Events_t = MDInstrumentDefinitionFixedIncome57_Events;
    using MDFeedTypes_t = MDInstrumentDefinitionFixedIncome57_MDFeedTypes;
    using InstAttrib_t = MDInstrumentDefinitionFixedIncome57_InstAttrib;
    using LotTypeRules_t = MDInstrumentDefinitionFixedIncome57_LotTypeRules;
};

struct [[gnu::packed]] MDInstrumentDefinitionRepo58_Events {
    static constexpr size_t MSG_LEN = 9;
    groupSize dimension;
    using Dimension_t = groupSize;
    EventType eventType;
    uInt64 eventTime;
};

struct [[gnu::packed]] MDInstrumentDefinitionRepo58_MDFeedTypes {
    static constexpr size_t MSG_LEN = 4;
    groupSize dimension;
    using Dimension_t = groupSize;
    MDFeedType mDFeedType;
    Int8 marketDepth;
};

struct [[gnu::packed]] MDInstrumentDefinitionRepo58_InstAttrib {
    static constexpr size_t MSG_LEN = 4;
    groupSize dimension;
    using Dimension_t = groupSize;
    InstAttribValue instAttribValue;
};

struct [[gnu::packed]] MDInstrumentDefinitionRepo58_LotTypeRules {
    static constexpr size_t MSG_LEN = 5;
    groupSize dimension;
    using Dimension_t = groupSize;
    Int8 lotType;
    DecimalQty minLotSize;
};

struct [[gnu::packed]] MDInstrumentDefinitionRepo58_Underlyings {
    static constexpr size_t MSG_LEN = 118;
    groupSize dimension;
    using Dimension_t = groupSize;
    UnderlyingSymbol underlyingSymbol;
    Int32NULL underlyingSecurityID;
    String12 underlyingSecurityAltID;
    SecurityAltIDSource underlyingSecurityAltIDSource;
    LongName underlyingFinancialInstrumentFullName;
    SecurityType underlyingSecurityType;
    CountryCode underlyingCountryOfIssue;
    String25 underlyingIssuer;
    uInt8NULL underlyingMaxLifeTime;
    uInt16NULL underlyingMinDaysToMaturity;
    uInt64NULL underlyingInstrumentGUID;
    LocalMktDate underlyingMaturityDate;
};

struct [[gnu::packed]] MDInstrumentDefinitionRepo58_RelatedInstruments {
    static constexpr size_t MSG_LEN = 32;
    groupSize dimension;
    using Dimension_t = groupSize;
    Int32 relatedSecurityID;
    Symbol relatedSymbol;
    uInt64NULL relatedInstrumentGUID;
};

struct [[gnu::packed]] MDInstrumentDefinitionRepo58_BrokenDates {
    static constexpr size_t MSG_LEN = 16;
    groupSize dimension;
    using Dimension_t = groupSize;
    uInt64 brokenDateGUID;
    Int32 brokenDateSecurityID;
    LocalMktDate brokenDateStart;
    LocalMktDate brokenDateEnd;
};

struct [[gnu::packed]] MDInstrumentDefinitionRepo58 { // ID=58
    static constexpr size_t MSG_LEN = 276;
    MatchEventIndicator matchEventIndicator;
    uInt32NULL totNumReports;
    SecurityUpdateAction securityUpdateAction;
    uInt64 lastUpdateTime;
    SecurityTradingStatus mDSecurityTradingStatus;
    Int16 applID;
    uInt8 marketSegmentID;
    uInt8 underlyingProduct;
    SecurityExchange securityExchange;
    SecurityGroup securityGroup;
    Asset asset;
    Symbol symbol;
    Int32 securityID;
    SecurityType securityType;
    CFICode cFICode;
    Currency currency;
    Currency settlCurrency;
    CHAR matchAlgorithm;
    uInt32 minTradeVol;
    uInt32 maxTradeVol;
    PRICE9 minPriceIncrement;
    Decimal9 displayFactor;
    UnitOfMeasure unitOfMeasure;
    Decimal9NULL unitOfMeasureQty;
    PRICENULL9 tradingReferencePrice;
    LocalMktDate tradingReferenceDate;
    PRICENULL9 highLimitPrice;
    PRICENULL9 lowLimitPrice;
    PRICENULL9 maxPriceVariation;
    LongName financialInstrumentFullName;
    String5 partyRoleClearingOrg;
    LocalMktDate startDate;
    LocalMktDate endDate;
    String8 terminationType;
    RepoSubType securitySubType;
    MoneyOrPar moneyOrPar;
    uInt8 maxNoOfSubstitutions;
    String5 priceQuoteMethod;
    UserDefinedInstrument userDefinedInstrument;
    String6 riskSet;
    String6 marketSet;
    uInt64NULL instrumentGUID;
    String20 termCode;
    uInt8NULL brokenDateTermType;
    using Events_t = MDInstrumentDefinitionRepo58_Events;
    using MDFeedTypes_t = MDInstrumentDefinitionRepo58_MDFeedTypes;
    using InstAttrib_t = MDInstrumentDefinitionRepo58_InstAttrib;
    using LotTypeRules_t = MDInstrumentDefinitionRepo58_LotTypeRules;
    using Underlyings_t = MDInstrumentDefinitionRepo58_Underlyings;
    using RelatedInstruments_t = MDInstrumentDefinitionRepo58_RelatedInstruments;
    using BrokenDates_t = MDInstrumentDefinitionRepo58_BrokenDates;
};

struct [[gnu::packed]] SnapshotRefreshTopOrders59_MDEntries {
    static constexpr size_t MSG_LEN = 29;
    groupSize dimension;
    using Dimension_t = groupSize;
    uInt64 orderID;
    uInt64 mDOrderPriority;
    PRICE9 mDEntryPx;
    Int32 mDDisplayQty;
    MDEntryTypeBook mDEntryType;
};

struct [[gnu::packed]] SnapshotRefreshTopOrders59 { // ID=59
    static constexpr size_t MSG_LEN = 13;
    uInt64 transactTime;
    MatchEventIndicator matchEventIndicator;
    Int32 securityID;
    using MDEntries_t = SnapshotRefreshTopOrders59_MDEntries;
};

struct [[gnu::packed]] SecurityStatusWorkup60_OrderIDEntries {
    static constexpr size_t MSG_LEN = 10;
    groupSize dimension;
    using Dimension_t = groupSize;
    uInt64 orderID;
    Side side;
    AggressorFlag aggressorIndicator;
};

struct [[gnu::packed]] SecurityStatusWorkup60 { // ID=60
    static constexpr size_t MSG_LEN = 30;
    uInt64 transactTime;
    PRICENULL9 mDEntryPx;
    Int32 securityID;
    MatchEventIndicator matchEventIndicator;
    LocalMktDate tradeDate;
    uInt32 tradeLinkID;
    WorkupTradingStatus securityTradingStatus;
    HaltReason haltReason;
    SecurityTradingEvent securityTradingEvent;
    using OrderIDEntries_t = SecurityStatusWorkup60_OrderIDEntries;
};

struct [[gnu::packed]] SnapshotFullRefreshTCP61_MDEntries {
    static constexpr size_t MSG_LEN = 26;
    groupSize dimension;
    using Dimension_t = groupSize;
    PRICENULL9 mDEntryPx;
    Int32NULL mDEntrySize;
    Int32NULL tradeableSize;
    Int32NULL numberOfOrders;
    Int8NULL mDPriceLevel;
    OpenCloseSettlFlag openCloseSettlFlag;
    MDEntryType mDEntryType;
    LocalMktDate tradingReferenceDate;
    SettlPriceType settlPriceType;
};

struct [[gnu::packed]] SnapshotFullRefreshTCP61 { // ID=61
    static constexpr size_t MSG_LEN = 37;
    uInt64 transactTime;
    MatchEventIndicator matchEventIndicator;
    Int32 securityID;
    PRICENULL9 highLimitPrice;
    PRICENULL9 lowLimitPrice;
    PRICENULL9 maxPriceVariation;
    using MDEntries_t = SnapshotFullRefreshTCP61_MDEntries;
};

struct [[gnu::packed]] CollateralMarketValue62_MDEntries {
    static constexpr size_t MSG_LEN = 40;
    groupSize dimension;
    using Dimension_t = groupSize;
    String12 underlyingSecurityAltID;
    SecurityAltIDSource underlyingSecurityAltIDSource;
    PRICE9 collateralMarketPrice;
    PRICE9 dirtyPrice;
    uInt64 underlyingInstrumentGUID;
    PriceSource mDStreamID;
};

struct [[gnu::packed]] CollateralMarketValue62 { // ID=62
    static constexpr size_t MSG_LEN = 11;
    uInt64 transactTime;
    MatchEventIndicator matchEventIndicator;
    using MDEntries_t = CollateralMarketValue62_MDEntries;
};

struct [[gnu::packed]] MDInstrumentDefinitionFX63_Events {
    static constexpr size_t MSG_LEN = 9;
    groupSize dimension;
    using Dimension_t = groupSize;
    EventType eventType;
    uInt64 eventTime;
};

struct [[gnu::packed]] MDInstrumentDefinitionFX63_MDFeedTypes {
    static constexpr size_t MSG_LEN = 4;
    groupSize dimension;
    using Dimension_t = groupSize;
    MDFeedType mDFeedType;
    Int8 marketDepth;
};

struct [[gnu::packed]] MDInstrumentDefinitionFX63_InstAttrib {
    static constexpr size_t MSG_LEN = 4;
    groupSize dimension;
    using Dimension_t = groupSize;
    InstAttribValue instAttribValue;
};

struct [[gnu::packed]] MDInstrumentDefinitionFX63_LotTypeRules {
    static constexpr size_t MSG_LEN = 9;
    groupSize dimension;
    using Dimension_t = groupSize;
    Int8 lotType;
    uInt64 minLotSize;
};

struct [[gnu::packed]] MDInstrumentDefinitionFX63_TradingSessions {
    static constexpr size_t MSG_LEN = 18;
    groupSize dimension;
    using Dimension_t = groupSize;
    LocalMktDate tradeDate;
    LocalMktDate settlDate;
    LocalMktDate maturityDate;
    String12 securityAltID;
};

struct [[gnu::packed]] MDInstrumentDefinitionFX63 { // ID=63
    static constexpr size_t MSG_LEN = 337;
    MatchEventIndicator matchEventIndicator;
    uInt32NULL totNumReports;
    SecurityUpdateAction securityUpdateAction;
    uInt64 lastUpdateTime;
    SecurityTradingStatus mDSecurityTradingStatus;
    Int16 applID;
    uInt8 marketSegmentID;
    uInt8 underlyingProduct;
    SecurityExchange securityExchange;
    SecurityGroup securityGroup;
    Asset asset;
    Symbol symbol;
    Int32 securityID;
    SecurityType securityType;
    CFICode cFICode;
    Currency currency;
    Currency settlCurrency;
    Currency priceQuoteCurrency;
    CHAR matchAlgorithm;
    uInt32 minTradeVol;
    uInt32 maxTradeVol;
    PRICE9 minPriceIncrement;
    Decimal9 displayFactor;
    uInt8 pricePrecision;
    UnitOfMeasure unitOfMeasure;
    Decimal9NULL unitOfMeasureQty;
    PRICENULL9 highLimitPrice;
    PRICENULL9 lowLimitPrice;
    PRICENULL9 maxPriceVariation;
    UserDefinedInstrument userDefinedInstrument;
    LongName financialInstrumentFullName;
    String7 fXCurrencySymbol;
    String3 settlType;
    uInt16 interveningDays;
    String20 fXBenchmarkRateFix;
    String12 rateSource;
    String8 fixRateLocalTime;
    String20 fixRateLocalTimeZone;
    uInt32 minQuoteLife;
    PRICE9 maxPriceDiscretionOffset;
    uInt64NULL instrumentGUID;
    MaturityMonthYear maturityMonthYear;
    String8 settlementLocale;
    PRICENULL9 altMinPriceIncrement;
    uInt32NULL altMinQuoteLife;
    PRICENULL9 altPriceIncrementConstraint;
    PRICENULL9 maxBidAskConstraint;
    using Events_t = MDInstrumentDefinitionFX63_Events;
    using MDFeedTypes_t = MDInstrumentDefinitionFX63_MDFeedTypes;
    using InstAttrib_t = MDInstrumentDefinitionFX63_InstAttrib;
    using LotTypeRules_t = MDInstrumentDefinitionFX63_LotTypeRules;
    using TradingSessions_t = MDInstrumentDefinitionFX63_TradingSessions;
};

struct [[gnu::packed]] MDIncrementalRefreshBookLongQty64_MDEntries {
    static constexpr size_t MSG_LEN = 32;
    groupSize dimension;
    using Dimension_t = groupSize;
    PRICENULL9 mDEntryPx;
    uInt64NULL mDEntrySize;
    Int32 securityID;
    uInt32 rptSeq;
    Int32NULL numberOfOrders;
    uInt8 mDPriceLevel;
    MDUpdateAction mDUpdateAction;
    MDEntryTypeBook mDEntryType;
};

struct [[gnu::packed]] MDIncrementalRefreshBookLongQty64_OrderIDEntries {
    static constexpr size_t MSG_LEN = 24;
    groupSize8Byte dimension;
    using Dimension_t = groupSize8Byte;
    uInt64 orderID;
    uInt64NULL mDOrderPriority;
    Int32NULL mDDisplayQty;
    uInt8NULL referenceID;
    OrderUpdateAction orderUpdateAction;
};

struct [[gnu::packed]] MDIncrementalRefreshBookLongQty64 { // ID=64
    static constexpr size_t MSG_LEN = 11;
    uInt64 transactTime;
    MatchEventIndicator matchEventIndicator;
    using MDEntries_t = MDIncrementalRefreshBookLongQty64_MDEntries;
    using OrderIDEntries_t = MDIncrementalRefreshBookLongQty64_OrderIDEntries;
};

struct [[gnu::packed]] MDIncrementalRefreshTradeSummaryLongQty65_MDEntries {
    static constexpr size_t MSG_LEN = 40;
    groupSize dimension;
    using Dimension_t = groupSize;
    PRICE9 mDEntryPx;
    uInt64 mDEntrySize;
    Int32 securityID;
    uInt32 rptSeq;
    Int32 numberOfOrders;
    uInt32 mDTradeEntryID;
    AggressorSide aggressorSide;
    MDUpdateAction mDUpdateAction;
};

struct [[gnu::packed]] MDIncrementalRefreshTradeSummaryLongQty65_OrderIDEntries {
    static constexpr size_t MSG_LEN = 16;
    groupSize8Byte dimension;
    using Dimension_t = groupSize8Byte;
    uInt64 orderID;
    Int32 lastQty;
};

struct [[gnu::packed]] MDIncrementalRefreshTradeSummaryLongQty65 { // ID=65
    static constexpr size_t MSG_LEN = 11;
    uInt64 transactTime;
    MatchEventIndicator matchEventIndicator;
    using MDEntries_t = MDIncrementalRefreshTradeSummaryLongQty65_MDEntries;
    using OrderIDEntries_t = MDIncrementalRefreshTradeSummaryLongQty65_OrderIDEntries;
};

struct [[gnu::packed]] MDIncrementalRefreshVolumeLongQty66_MDEntries {
    static constexpr size_t MSG_LEN = 24;
    groupSize dimension;
    using Dimension_t = groupSize;
    uInt64 mDEntrySize;
    Int32 securityID;
    uInt32 rptSeq;
    MDUpdateAction mDUpdateAction;
};

struct [[gnu::packed]] MDIncrementalRefreshVolumeLongQty66 { // ID=66
    static constexpr size_t MSG_LEN = 11;
    uInt64 transactTime;
    MatchEventIndicator matchEventIndicator;
    using MDEntries_t = MDIncrementalRefreshVolumeLongQty66_MDEntries;
};

struct [[gnu::packed]] MDIncrementalRefreshSessionStatisticsLongQty67_MDEntries {
    static constexpr size_t MSG_LEN = 32;
    groupSize dimension;
    using Dimension_t = groupSize;
    PRICE9 mDEntryPx;
    uInt64NULL mDEntrySize;
    Int32 securityID;
    uInt32 rptSeq;
    OpenCloseSettlFlag openCloseSettlFlag;
    MDUpdateAction mDUpdateAction;
    MDEntryTypeStatistics mDEntryType;
};

struct [[gnu::packed]] MDIncrementalRefreshSessionStatisticsLongQty67 { // ID=67
    static constexpr size_t MSG_LEN = 11;
    uInt64 transactTime;
    MatchEventIndicator matchEventIndicator;
    using MDEntries_t = MDIncrementalRefreshSessionStatisticsLongQty67_MDEntries;
};

struct [[gnu::packed]] SnapshotFullRefreshTCPLongQty68_MDEntries {
    static constexpr size_t MSG_LEN = 23;
    groupSize dimension;
    using Dimension_t = groupSize;
    PRICENULL9 mDEntryPx;
    uInt64NULL mDEntrySize;
    Int32NULL numberOfOrders;
    uInt8NULL mDPriceLevel;
    OpenCloseSettlFlag openCloseSettlFlag;
    MDEntryType mDEntryType;
};

struct [[gnu::packed]] SnapshotFullRefreshTCPLongQty68 { // ID=68
    static constexpr size_t MSG_LEN = 37;
    uInt64 transactTime;
    MatchEventIndicator matchEventIndicator;
    Int32 securityID;
    PRICENULL9 highLimitPrice;
    PRICENULL9 lowLimitPrice;
    PRICENULL9 maxPriceVariation;
    using MDEntries_t = SnapshotFullRefreshTCPLongQty68_MDEntries;
};

struct [[gnu::packed]] SnapshotFullRefreshLongQty69_MDEntries {
    static constexpr size_t MSG_LEN = 23;
    groupSize dimension;
    using Dimension_t = groupSize;
    PRICENULL9 mDEntryPx;
    uInt64NULL mDEntrySize;
    Int32NULL numberOfOrders;
    uInt8NULL mDPriceLevel;
    OpenCloseSettlFlag openCloseSettlFlag;
    MDEntryType mDEntryType;
};

struct [[gnu::packed]] SnapshotFullRefreshLongQty69 { // ID=69
    static constexpr size_t MSG_LEN = 59;
    uInt32 lastMsgSeqNumProcessed;
    uInt32 totNumReports;
    Int32 securityID;
    uInt32 rptSeq;
    uInt64 transactTime;
    uInt64 lastUpdateTime;
    LocalMktDate tradeDate;
    SecurityTradingStatus mDSecurityTradingStatus;
    PRICENULL9 highLimitPrice;
    PRICENULL9 lowLimitPrice;
    PRICENULL9 maxPriceVariation;
    using MDEntries_t = SnapshotFullRefreshLongQty69_MDEntries;
};
