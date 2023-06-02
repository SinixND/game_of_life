#ifndef GLOBALS_H
#define GLOBALS_H

#include "raylib.h"
#include "screens.h"


// SETTINGS / CONFIGS
//---------------------------------
class MySingleton{
public:
  //getter
  //setter

  static MySingleton& getInstance(); // public method to make an instance

private:
  //member

  MySingleton()= default; // private constructor
  ~MySingleton()= default; // private destructor
  MySingleton(const MySingleton&)= delete; // delete copy constructor
  MySingleton& operator=(const MySingleton&)= delete; // delete copy operator(?)
};

// APPLICATION
extern int windowWidth;
extern int windowHeight;
extern int targetFPS;

// GUI ELEMENTS
extern int txtSmall;
extern int txtNormal;
extern int guiButtonBaseWidth;
extern int guiButtonBaseHeight;

// AGENT
extern int agentWidth;
extern int agentHeight; // independent height and width possible
extern int agentInnerBorderWeight;
extern bool decayingAgents;

// AGENTS / ENVIRONMENT
extern int agentGap;
extern float lifeDensity; // in %, eg. 25

// CONTROLS
extern int evolutionTime; // in ms
//---------------------------------

// GLOBALS
extern screen currentScreen;
extern bool darkMode;
extern Color BG;
extern Color FG;
extern Color FG2;
extern Color FG3;
extern Color FG4;

#endif