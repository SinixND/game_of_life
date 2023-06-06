#ifndef CONFIGS_H
#define CONFIGS_H

//---------------------------------
// CUSTOMIZABLE BY USER
//---------------------------------
class cConfig {
public:
  cConfig();

  // APPLICATION
  int windowWidth;
  int windowHeight;
  int targetFPS;

  // AGENT
  int agentWidth;
  int agentHeight; // independent height and width possible
  int agentInnerBorderWeight;
  bool decayAgents;

  // AGENTS / ENVIRONMENT
  int agentGap;
  float lifeDensity; // in %, eg. 25

  // CONTROLS
  int evolutionTime; // in ms

};
extern cConfig config;

#endif