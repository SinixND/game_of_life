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
/*
As comented, you can use GetFontDefault() with MeasureTetEx() but default raylib font is 10 pixels height, actually you can access the default height of any font with font.baseSize. i.e. GetFontDefault().baseSize.
*/