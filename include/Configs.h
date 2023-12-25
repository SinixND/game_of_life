#ifndef CONFIGS_H_202311201531
#define CONFIGS_H_202311201531

#include "raylib.h"

// CUSTOMIZABLE BY USER
//---------------------------------
class Config
{
public:
    Config();

    // APPLICATION
    bool debugMode;
    bool multiThread;
    double tickTime; // in s

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
    double agentInnerBorderWeight;
};
extern Config config; // declare extern object
#endif
