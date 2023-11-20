#ifndef GLOBALS_H
#define GLOBALS_H

// external
#include <raylib.h>

// NOT CUSTOMIZABLE BY USER
//---------------------------------
class Global
{
public:
    Global();

    bool exitApp;

    // GUI ELEMENTS
    void ToggleDarkMode();
    bool GetDarkMode();

    Color GetBackground();
    Color GetForeground();

private:
    // DARK MODE
    bool darkMode;
    Color background;
    Color foreground;

    void SetColors();
};
extern Global global; // declare extern object
#endif