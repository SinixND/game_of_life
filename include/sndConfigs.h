#ifndef CONFIGS_H
#define CONFIGS_H

// CUSTOMIZABLE BY USER
//---------------------------------
class Config
{
public:
    Config();

    // APPLICATION
    int targetFPS;

    // AGENTS AND ENVIRONMENT
    bool fadingAgents;
    bool debugMode;
    int initialLifeDensity;

    // DISPLAY
    int agentGap;
    float agentWidth;
    float agentHeight; // independent height and width possible
    float agentInnerBorderWeight;

    // CONTROLS
    float tickTime;
};
extern Config config; // declare extern object
#endif