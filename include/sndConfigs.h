#ifndef CONFIGS_H
#define CONFIGS_H

#include <raylib.h>

// CUSTOMIZABLE BY USER
//---------------------------------
class Config
{
public:
    Config();

    // APPLICATION
    bool debugMode;
    float tickTime;

    // DISPLAY
    int targetFPS;
    bool drawFPS;
    int windowSize;

    // GRID
    int initialLifeDensity;

    // AGENTS
    bool fadingAgents;
    int agentWidth;
    int agentHeight; // independent height and width possible
    int agentGap;
    float agentInnerBorderWeight;
};
extern Config config; // declare extern object
#endif