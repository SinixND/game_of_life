#ifndef CONFIGS_H
#define CONFIGS_H

// CUSTOMIZABLE BY USER
//---------------------------------
class cConfig
{
public:
    cConfig();

    // APPLICATION
    int windowWidth;
    int windowHeight;
    int targetFPS;

    // AGENTS AND ENVIRONMENT
    bool fadingAgents;
    int initialLifeDensity;

    // DISPLAY
    int agentGap;
    float agentWidth;
    float agentHeight; // independent height and width possible
    float agentInnerBorderWeight;

    // CONTROLS
    float tickTime;
};
extern cConfig config; // declare extern object

#endif