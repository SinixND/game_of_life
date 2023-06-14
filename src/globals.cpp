#include "globals.h" // provide object "global" for not configurable application parameters

#include "raylib.h"

// NOT CUSTOMIZABLE BY USER
//---------------------------------
cGlobal global; // declare extern object
cGlobal::cGlobal(){
  // GUI ELEMENTS
  Font font = GetFontDefault();
  //GetFontDefault().baseSize == 10
  txtSmall = 20;
  txtNormal = 30;
  guiButtonBaseWidth = 20;
  guiButtonBaseHeight = 30;


  // PRIVATE
  // DARK MODE
  darkMode = false;
  colorBackground = WHITE;
  colorForeground = BLACK;
  colorAgentFaded1 = Fade(colorForeground, 0.75f);
  colorAgentFaded2 = Fade(colorForeground, 0.50f);
  colorAgentFaded3 = Fade(colorForeground, 0.25f);
};

void cGlobal::SetDarkMode(bool arg){
  darkMode = arg;

  if (darkMode == true) {
    colorBackground = BLACK;
    colorForeground = WHITE;
    colorAgentFaded1 = Fade(colorForeground, 0.25f);
    colorAgentFaded2 = Fade(colorForeground, 0.50f);
    colorAgentFaded3 = Fade(colorForeground, 0.75f);
  } else {
    colorBackground = WHITE;
    colorForeground = BLACK;
    colorAgentFaded1 = Fade(colorForeground, 0.75f);
    colorAgentFaded2 = Fade(colorForeground, 0.50f);
    colorAgentFaded3 = Fade(colorForeground, 0.25f);
  }
};
bool cGlobal::GetDarkMode(){ return darkMode; };

Color cGlobal::GetColorBackground(){ return colorBackground; };
Color cGlobal::GetColorForeground(){ return colorForeground; };
Color cGlobal::GetColorAgentFaded1(){ return colorAgentFaded1; };
Color cGlobal::GetColorAgentFaded2(){ return colorAgentFaded2; };
Color cGlobal::GetColorAgentFaded3(){ return colorAgentFaded3; };