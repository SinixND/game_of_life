#include "sndGlobals.h" // provide object "global" for not configurable application parameters
#include <iostream>
#include <raylib.h>

Global global; // define extern object
Global::Global()
    : textSizeDefault(20)
    , guiButtonBaseWidth(20)
    , guiButtonBaseHeight(30)
    , darkMode(true)
    , background(WHITE)
    , foreground(BLACK)
    , exitApp(false)
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

Color Global::Getbackground()
{
    return background;
};

Color Global::Getforeground()
{
    return foreground;
};