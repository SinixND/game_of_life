#ifndef GLOBALS_H
#define GLOBALS_H

#include "raylib.h"
#include "screens.h"

// SETTINGS
// APPLICATION
extern int windowWidth;
extern int windowHeight;
extern int targetFPS;

// GUI ELEMENTS
extern int txtSmall;
extern int txtNormal;
extern Vector2 buttonBase;
extern int guiButtonBaseWidth;
extern int guiButtonBaseHeight;

// AGENT
extern int agentWidth;
extern int agentHeight; // independent height and width possible
extern int agentInnerBorderWeight;
extern bool decayingAgents;

// AGENTS / ENVIRONMENT
extern int agentGap;

// CONTROLS
extern int evolutionTime; // in ms

// GLOBALS
extern screen currentScreen;
extern bool darkMode;
extern Color BG;
extern Color FG;
extern Color FG2;
extern Color FG3;
extern Color FG4;

#endif