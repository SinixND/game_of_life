#ifndef GLOBALS_H
#define GLOBALS_H

#include <raylib.h>

// NOT CUSTOMIZABLE BY USER
//---------------------------------
class Global
{
public:
    Global();
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

    void SetColors();
};
extern Global global; // declare extern object
#endif