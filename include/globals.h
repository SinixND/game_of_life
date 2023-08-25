#ifndef GLOBALS_H
#define GLOBALS_H

#include <raylib.h>

// NOT CUSTOMIZABLE BY USER
//---------------------------------
class cGlobal
{
public:
    cGlobal();
    // APPLICATION
    bool exitApp;

    // GUI ELEMENTS
    float textSizeDefault;
    float guiButtonBaseWidth;
    float guiButtonBaseHeight;

    void ToggleDarkMode();
    bool GetDarkMode();

    Color GetColorBackground();
    Color GetColorForeground();
private:
    // DARK MODE
    bool darkMode;
    Color colorBackground;
    Color colorForeground;
};
extern cGlobal global; // declare extern object

#endif