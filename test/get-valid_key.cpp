#include "get.h"


TEST_F( Get, ValidKey_KeyA )
{
    using ValueType    = int;
    using OptionalType = std::optional< ValueType >;
    JSONConfig::Config config {getConfigFilename()};

    ValueType    valueReference      = getConfigContent().at( "/KeyA"_json_pointer ).get< ValueType >();
    ValueType    valueDefault        = ValueType {};
    ValueType    valueConfig         = config / "KeyA" | valueDefault;
    OptionalType valueConfigOptional = config / "KeyA";

    ASSERT_EQ( valueConfig, valueReference );
    ASSERT_TRUE( valueConfigOptional.has_value() );
    ASSERT_EQ( valueConfigOptional, valueReference );
}


TEST_F( Get, ValidKey_KeyB )
{
    using ValueType    = std::string;
    using OptionalType = std::optional< ValueType >;
    JSONConfig::Config config {getConfigFilename()};

    ValueType    valueReference      = getConfigContent().at( "/KeyB"_json_pointer ).get< ValueType >();
    ValueType    valueDefault        = ValueType {};
    ValueType    valueConfig         = config / "KeyB" | valueDefault;
    OptionalType valueConfigOptional = config / "KeyB";

    ASSERT_EQ( valueConfig, valueReference );
    ASSERT_TRUE( valueConfigOptional.has_value() );
    ASSERT_EQ( valueConfigOptional, valueReference );
}


TEST_F( Get, ValidKey_KeyC )
{
    using ValueType    = bool;
    using OptionalType = std::optional< ValueType >;
    JSONConfig::Config config {getConfigFilename()};

    ValueType    valueReference      = getConfigContent().at( "/KeyC"_json_pointer ).get< ValueType >();
    ValueType    valueDefault        = ValueType {};
    ValueType    valueConfig         = config / "KeyC" | valueDefault;
    OptionalType valueConfigOptional = config / "KeyC";

    ASSERT_EQ( valueConfig, valueReference );
    ASSERT_TRUE( valueConfigOptional.has_value() );
    ASSERT_EQ( valueConfigOptional, valueReference );
}


TEST_F( Get, ValidKey_KeyD )
{
    using ValueType    = std::vector< int >;
    using OptionalType = std::optional< ValueType >;
    JSONConfig::Config config {getConfigFilename()};

    ValueType    valueReference      = getConfigContent().at( "/KeyD"_json_pointer ).get< ValueType >();
    ValueType    valueDefault        = ValueType {};
    ValueType    valueConfig         = config / "KeyD" | valueDefault;
    OptionalType valueConfigOptional = config / "KeyD";

    ASSERT_EQ( valueConfig, valueReference );
    ASSERT_TRUE( valueConfigOptional.has_value() );
    ASSERT_EQ( valueConfigOptional, valueReference );
}


TEST_F( Get, ValidKey_KeyD_Indexing )
{
    using ValueType    = int;
    using OptionalType = std::optional< ValueType >;
    JSONConfig::Config config {getConfigFilename()};

    for( int i = 0; i < 4; ++i )
    {
        ValueType    valueReference      = getConfigContent().at( "/KeyD"_json_pointer )[ i ].get< ValueType >();
        ValueType    valueDefault        = ValueType {};
        ValueType    valueConfig         = config / "KeyD" / i | valueDefault;
        OptionalType valueConfigOptional = config / "KeyD" / i;

        ASSERT_EQ( valueConfig, valueReference );
        ASSERT_TRUE( valueConfigOptional.has_value() );
        ASSERT_EQ( valueConfigOptional, valueReference );
    }
}


TEST_F( Get, ValidKey_KeyE )
{
    using ValueType    = std::vector< std::string >;
    using OptionalType = std::optional< ValueType >;
    JSONConfig::Config config {getConfigFilename()};

    ValueType    valueReference      = getConfigContent().at( "/KeyE"_json_pointer ).get< ValueType >();
    ValueType    valueDefault        = ValueType {};
    ValueType    valueConfig         = config / "KeyE" | valueDefault;
    OptionalType valueConfigOptional = config / "KeyE";

    ASSERT_EQ( valueConfig, valueReference );
    ASSERT_TRUE( valueConfigOptional.has_value() );
    ASSERT_EQ( valueConfigOptional, valueReference );
}


TEST_F( Get, ValidKey_KeyE_Indexing )
{
    using ValueType    = std::string;
    using OptionalType = std::optional< ValueType >;
    JSONConfig::Config config {getConfigFilename()};

    for( int i = 0; i < 4; ++i )
    {
        ValueType    valueReference      = getConfigContent().at( "/KeyE"_json_pointer )[ i ].get< ValueType >();
        ValueType    valueDefault        = ValueType {};
        ValueType    valueConfig         = config / "KeyE" / i | valueDefault;
        OptionalType valueConfigOptional = config / "KeyE" / i;

        ASSERT_EQ( valueConfig, valueReference );
        ASSERT_TRUE( valueConfigOptional.has_value() );
        ASSERT_EQ( valueConfigOptional, valueReference );
    }
}


TEST_F( Get, ValidKey_KeyFKeyA )
{
    using ValueType    = int;
    using OptionalType = std::optional< ValueType >;
    JSONConfig::Config config {getConfigFilename()};

    ValueType    valueReference      = getConfigContent().at( "/KeyF/KeyA"_json_pointer ).get< ValueType >();
    ValueType    valueDefault        = ValueType {};
    ValueType    valueConfig         = config / "KeyF" / "KeyA" | valueDefault;
    OptionalType valueConfigOptional = config / "KeyF" / "KeyA";

    ASSERT_EQ( valueConfig, valueReference );
    ASSERT_TRUE( valueConfigOptional.has_value() );
    ASSERT_EQ( valueConfigOptional, valueReference );
}


TEST_F( Get, ValidKey_KeyFKeyB )
{
    using ValueType    = std::string;
    using OptionalType = std::optional< ValueType >;
    JSONConfig::Config config {getConfigFilename()};

    ValueType    valueReference      = getConfigContent().at( "/KeyF/KeyB"_json_pointer ).get< ValueType >();
    ValueType    valueDefault        = ValueType {};
    ValueType    valueConfig         = config / "KeyF" / "KeyB" | valueDefault;
    OptionalType valueConfigOptional = config / "KeyF" / "KeyB";

    ASSERT_EQ( valueConfig, valueReference );
    ASSERT_TRUE( valueConfigOptional.has_value() );
    ASSERT_EQ( valueConfigOptional, valueReference );
}


TEST_F( Get, ValidKey_KeyFKeyC )
{
    using ValueType    = bool;
    using OptionalType = std::optional< ValueType >;
    JSONConfig::Config config {getConfigFilename()};

    ValueType    valueReference      = getConfigContent().at( "/KeyF/KeyC"_json_pointer ).get< ValueType >();
    ValueType    valueDefault        = ValueType {};
    ValueType    valueConfig         = config / "KeyF" / "KeyC" | valueDefault;
    OptionalType valueConfigOptional = config / "KeyF" / "KeyC";

    ASSERT_EQ( valueConfig, valueReference );
    ASSERT_TRUE( valueConfigOptional.has_value() );
    ASSERT_EQ( valueConfigOptional, valueReference );
}


TEST_F( Get, ValidKey_KeyFKeyD )
{
    using ValueType    = std::vector< int >;
    using OptionalType = std::optional< ValueType >;
    JSONConfig::Config config {getConfigFilename()};

    ValueType    valueReference      = getConfigContent().at( "/KeyF/KeyD"_json_pointer ).get< ValueType >();
    ValueType    valueDefault        = ValueType {};
    ValueType    valueConfig         = config / "KeyF" / "KeyD" | valueDefault;
    OptionalType valueConfigOptional = config / "KeyF" / "KeyD";

    ASSERT_EQ( valueConfig, valueReference );
    ASSERT_TRUE( valueConfigOptional.has_value() );
    ASSERT_EQ( valueConfigOptional, valueReference );
}


TEST_F( Get, ValidKey_KeyFKeyD_Indexing )
{
    using ValueType    = int;
    using OptionalType = std::optional< ValueType >;
    JSONConfig::Config config {getConfigFilename()};

    for( int i = 0; i < 4; ++i )
    {
        ValueType    valueReference      = getConfigContent().at( "/KeyF/KeyD"_json_pointer )[ i ].get< ValueType >();
        ValueType    valueDefault        = ValueType {};
        ValueType    valueConfig         = config / "KeyF" / "KeyD" / i | valueDefault;
        OptionalType valueConfigOptional = config / "KeyF" / "KeyD" / i;

        ASSERT_EQ( valueConfig, valueReference );
        ASSERT_TRUE( valueConfigOptional.has_value() );
        ASSERT_EQ( valueConfigOptional, valueReference );
    }
}


TEST_F( Get, ValidKey_KeyFKeyE )
{
    using ValueType    = std::vector< std::string >;
    using OptionalType = std::optional< ValueType >;
    JSONConfig::Config config {getConfigFilename()};

    ValueType    valueReference      = getConfigContent().at( "/KeyF/KeyE"_json_pointer ).get< ValueType >();
    ValueType    valueDefault        = ValueType {};
    ValueType    valueConfig         = config / "KeyF" / "KeyE" | valueDefault;
    OptionalType valueConfigOptional = config / "KeyF" / "KeyE";

    ASSERT_EQ( valueConfig, valueReference );
    ASSERT_TRUE( valueConfigOptional.has_value() );
    ASSERT_EQ( valueConfigOptional, valueReference );
}


TEST_F( Get, ValidKey_KeyFKeyE_Indexing )
{
    using ValueType    = std::string;
    using OptionalType = std::optional< ValueType >;
    JSONConfig::Config config {getConfigFilename()};

    for( int i = 0; i < 4; ++i )
    {
        ValueType    valueReference      = getConfigContent().at( "/KeyF/KeyE"_json_pointer )[ i ].get< ValueType >();
        ValueType    valueDefault        = ValueType {};
        ValueType    valueConfig         = config / "KeyF" / "KeyE" / i | valueDefault;
        OptionalType valueConfigOptional = config / "KeyF" / "KeyE" / i;

        ASSERT_EQ( valueConfig, valueReference );
        ASSERT_TRUE( valueConfigOptional.has_value() );
        ASSERT_EQ( valueConfigOptional, valueReference );
    }
}
