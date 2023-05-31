#include "globals.h"

#include "raylib.h"

#include "screens.h"

// SETTINGS
// APPLICATION
int windowWidth = 640;
int windowHeight = 480;
int targetFPS = 144;

// GUI ELEMENTS
// default = 16
int txtSmall = 20;
int txtNormal = 30;

Vector2 buttonBase = {20, 30};
int guiButtonBaseWidth = 20;
int guiButtonBaseHeight = 30;

// AGENT
int agentWidth = 3;
int agentHeight = agentWidth;
int agentInnerBorderWeight = 0;
bool decayingAgents = true;

// AGENTS / ENVIRONMENT
int agentGap = 1;
float lifeDensity = 0.25; // in %, eg. 25

// CONTROLS
int evolutionTime = 100;

// GLOBALS
screen currentScreen = MENU;
bool darkMode = false;
Color BG = BLACK;
Color FG = WHITE;
Color FG2 = LIGHTGRAY;
Color FG3 = GRAY;
Color FG4 = DARKGRAY;

