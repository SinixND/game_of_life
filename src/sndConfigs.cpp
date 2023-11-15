#include "sndConfigs.h" // provide object "config" for configurable parameters

Config config; // define extern object
Config::Config()
    : debugMode(true)
    , multiThread(false) // MEMORY LEAK WHEN REDUCING WINDOW SIZE!!!
    , tickTime(0.125) // in s
    , targetFPS(60)
    , drawFPS(false)
    , windowSize(0)
    , initialLifeDensity(25)
    , fadingAgents(false)
    , agentWidth(18)
    , agentHeight(agentWidth)
    , agentGap(1)
    , agentInnerBorderWeight(1)
{
}
