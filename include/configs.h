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

  // AGENT
  float agentWidth;
  float agentHeight; // independent height and width possible
  float agentInnerBorderWeight;
  bool fadingAgents;

  // AGENTS / ENVIRONMENT
  float agentGap;
  float lifeDensity;

  // CONTROLS
  float tickTime;
};
extern cConfig config; // declare extern object

#endif