#include "globals.h" // provide object "global" for not configurable application parameters

#include "raylib.h"

cGlobal global; // define extern object
cGlobal::cGlobal()
    // Font font = GetFontDefault();
    // GetFontDefault().baseSize == 10
    : txtSmall{20}
    , txtNormal{30}
    , guiButtonBaseWidth{20}
    , guiButtonBaseHeight{30}
    , darkMode{false}
    , colorBackground{WHITE}
    , colorForeground{BLACK} {};

void cGlobal::ToggleDarkMode()
{
  darkMode = !darkMode;

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
};
bool cGlobal::GetDarkMode() { return darkMode; };

Color cGlobal::GetColorBackground() { return colorBackground; };
Color cGlobal::GetColorForeground() { return colorForeground; };