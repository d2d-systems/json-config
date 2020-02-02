#include "get.h"


TEST_F( Get, InvalidKey_KeyNone )
{
using ValueType    = int;
using OptionalType = std::optional< ValueType >;
JSONConfig::Config config {getConfigFilename()};

ValueType    valueDefault        = 0;
ValueType    valueConfig         = config / "KeyNone" | valueDefault;
OptionalType valueConfigOptional = config / "KeyNone";

ASSERT_EQ( valueConfig, valueDefault );
ASSERT_FALSE( valueConfigOptional.has_value() );
}
