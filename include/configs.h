#ifndef CONFIGS_H
#define CONFIGS_H

// CUSTOMIZABLE BY USER
//---------------------------------
class cConfig {
public:
  cConfig();

  // APPLICATION
  int windowWidth;
  int windowHeight;
  int targetFPS;
  float targetTickTime;

  // AGENT
  int agentWidth;
  int agentHeight; // independent height and width possible
  int agentInnerBorderWeight;
  bool decayAgents;

  // AGENTS / ENVIRONMENT
  int agentGap;
  float lifeDensity;

  // CONTROLS
  float tickTime;

};
extern cConfig config;

#endif