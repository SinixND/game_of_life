#include <stdio.h>
#include "sndlayout.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Testname/description", "[tag1] [tag2]")
{
    int var prerequisite = 0;

    REQUIRE(prerequisite == 1);

    SECTION("subset of tests")
    {
        int var subprerequisite = 0;

        REQUIRE(subprerequisite == 1);
    }
}