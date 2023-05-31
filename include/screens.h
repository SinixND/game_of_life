#ifndef SCREENS_H
#define SCREENS_H

typedef enum screen
{
  MENU,
  GAME,
  SETTINGS,
  ABOUT
} screen;

//============================
// SCREENS
//============================
void RunGameScreen();
void RunMenuScreen();

#endif