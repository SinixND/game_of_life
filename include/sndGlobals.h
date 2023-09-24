#ifndef GLOBALS_H
#define GLOBALS_H

#include <raylib.h>

// NOT CUSTOMIZABLE BY USER
//---------------------------------
class Global
{
public:
    Global();

    // GUI ELEMENTS
    float textSizeDefault;
    float guiButtonBaseWidth;
    float guiButtonBaseHeight;

    void ToggleDarkMode();
    bool GetDarkMode();

    Color Getbackground();
    Color Getforeground();

private:
    // DARK MODE
    bool darkMode;
    Color background;
    Color foreground;

    void SetColors();
};
extern Global global; // declare extern object
#endif