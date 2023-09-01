#include "sndGlobals.h" // provide object "global" for not configurable application parameters

#include <iostream>
#include <raylib.h>
#include <raygui.h>

Global global; // define extern object
Global::Global()
    : exitApp(false)
    , textSizeDefault(20)
    , guiButtonBaseWidth(20)
    , guiButtonBaseHeight(30)
    , darkMode(true)
    , colorBackground(WHITE)
    , colorForeground(BLACK)
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
        colorBackground = BLACK;
        colorForeground = WHITE;
    }
    else
    {
        colorBackground = WHITE;
        colorForeground = BLACK;
    }
}

bool Global::GetDarkMode()
{
    return darkMode;
};

Color Global::GetColorBackground()
{
    return colorBackground;
};

Color Global::GetColorForeground()
{
    return colorForeground;
};