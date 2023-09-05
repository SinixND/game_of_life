#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "sndAgent.h"
#include "sndGrid.h"

TEST_CASE("Agent methods", "[Agent]")
{
    Agent agent(0, 0);

    SECTION("Decrease Vitality")
    {
        agent.DecreaseVitality();
        REQUIRE(agent.GetVitality() >= 0);
        REQUIRE(agent.GetVitality() < agent.GetMaxVitality());
    }
}

TEST_CASE("Grid methods", "[Grid]")
{
    Grid grid(1,1);

    SECTION("Initialize Grid")
    {
        grid.Reset();
    }
}
