#include "configs.h" // provide object "config" for configurable parameters

// CUSTOMIZABLE BY USER
//---------------------------------
cConfig config; // declare extern object
cConfig::cConfig(){
  // APPLICATION
  windowWidth = 320;
  windowHeight = 240;
  targetFPS = 60;

  // AGENT
  agentWidth = 20;
  agentHeight = agentWidth;
  agentInnerBorderWeight = 0;
  fadingAgents = true;

  // AGENTS / ENVIRONMENT
  agentGap = 1;
  lifeDensity = 0.25;

  // CONTROLS
  tickTime = 0.5;
}
