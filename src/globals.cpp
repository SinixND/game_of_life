#include "globals.h"

#include "raylib.h"

#include "screens.h"

// SETTINGS
int windowWidth = 640;
int windowHeight = 480;
int targetFPS = 144;

int txtNormal = windowWidth / 20;
int txtSmall = txtNormal / 1.5;

// GLOBALS
screen currentScreen = MENU;
bool darkMode = false;
Color BG = BLACK;
Color FG = WHITE;
Color FG2 = LIGHTGRAY;
Color FG3 = GRAY;
Color FG4 = DARKGRAY;