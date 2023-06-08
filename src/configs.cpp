#include "configs.h" // provide object "config" for configurable parameters

// CUSTOMIZABLE BY USER
//---------------------------------
cConfig config; // declare extern object
cConfig::cConfig(){
  // APPLICATION
  windowWidth = 640;
  windowHeight = 480;
  targetFPS = 144;

  // AGENT
  agentWidth = 3;
  agentHeight = agentWidth;
  agentInnerBorderWeight = 0;
  decayAgents = true;

  // AGENTS / ENVIRONMENT
  agentGap = 1;
  lifeDensity = 0.0025; // in %, eg. 25

  // CONTROLS
  evolutionTime = 100;
}