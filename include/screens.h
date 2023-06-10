#ifndef SCREENS_H
#define SCREENS_H

typedef enum screen
{
  MENU,
  GAME,
  SETTINGS,
} screen;

extern screen currentScreen;

// SCREENS
//---------------------------------
void RunScreenMenu();
void RunScreenGame();
void RunScreenSettings();

#endif