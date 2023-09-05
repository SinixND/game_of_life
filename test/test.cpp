#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "sndAgent.h"

TEST_CASE("Agent methods", "[Agent]")
{
    //Agent agent(0, 0);
    SECTION("Decrease Vitality")
    {
        REQUIRE((1) == 1);
    }
}
