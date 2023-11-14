#include "sndConfigs.h" // provide object "config" for configurable parameters

Config config; // define extern object
Config::Config()
    : debugMode(false)
    , multiThread(false)
    , tickTime(1) // in s
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
