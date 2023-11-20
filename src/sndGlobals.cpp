// paired
#include "sndGlobals.h" // provide object "global" for not configurable application parameters

// external
#include <raylib.h>

// std
#include <iostream>

Global global; // define extern object
Global::Global()
    : exitApp {false}
    , darkMode {true}
    , background {WHITE}
    , foreground {BLACK}
{
    SetColors();
};

void Global::ToggleDarkMode()
{
    darkMode = !darkMode;
    SetColors();
};

void Global::SetColors()
{
    if (darkMode == true)
    {
        background = BLACK;
        foreground = WHITE;
    }
    else
    {
        background = WHITE;
        foreground = BLACK;
    }
}

bool Global::GetDarkMode()
{
    return darkMode;
};

Color Global::GetBackground()
{
    return background;
};

Color Global::GetForeground()
{
    return foreground;
};