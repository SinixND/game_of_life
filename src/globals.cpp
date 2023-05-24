#include "globals.h"

#include "screens.h"

int windowWidth = 640 *2;
int windowHeight = 480 *2;
int targetFPS = 144;

screen currentScreen = MENU;

int txtSmall = 20;
int txtNormal = 30;

bool darkMode = false;
Color BG = BLACK;
Color FG = WHITE;
Color FG2 = LIGHTGRAY;
Color FG3 = GRAY;
Color FG4 = DARKGRAY;