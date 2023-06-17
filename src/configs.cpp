#include "configs.h" // provide object "config" for configurable parameters

cConfig config; // define extern object
cConfig::cConfig()
    : windowWidth(640)
    , windowHeight(480)
    , targetFPS(60)
    , agentWidth(20)
    , agentHeight(agentWidth)
    , agentInnerBorderWeight(0)
    , fadingAgents(false)
    , agentGap(1)
    , initialLifeDensity(25)
    , tickTime(0.5)
{
}
