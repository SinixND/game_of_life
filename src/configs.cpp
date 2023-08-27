#include "configs.h" // provide object "config" for configurable parameters

cConfig config; // define extern object
cConfig::cConfig()
    : windowWidth(640)
    , windowHeight(480)
    , targetFPS(60)
    , fadingAgents(true)
    , agentColorDebug(true)
    , initialLifeDensity(25)
    , agentGap(1)
    , agentWidth(50)
    , agentHeight(agentWidth)
    , agentInnerBorderWeight(1)
    , tickTime(0.5)
{
}
