#include "include/tsuzuri/logger.h"
#include "tests/extern/doctest.h"

using namespace tsuzuri;

TEST_CASE("logger")
{
    Logger logger{};
    logger.log("testing");
}
