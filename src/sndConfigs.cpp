#include "sndConfigs.h" // provide object "config" for configurable parameters

Config config; // define extern object
Config::Config()
    : debugMode(false)
    , tickTime(0.2)
    , targetFPS(60)
    , drawFPS(false)
    , windowSize(0)
    , initialLifeDensity(25)
    , fadingAgents(false)
    , agentWidth(10)
    , agentHeight(agentWidth)
    , agentGap(1)
    , agentInnerBorderWeight(1)
{
}
