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
  colorAgentDecay1 = DARKGRAY;
  colorAgentDecay2 = GRAY;
  colorAgentDecay3 = LIGHTGRAY;
};

void cGlobal::SetDarkMode(bool arg){
  darkMode = arg;

  if (darkMode == true) {
    colorBackground = BLACK;
    colorForeground = WHITE;
    colorAgentDecay1 = LIGHTGRAY;
    colorAgentDecay2 = GRAY;
    colorAgentDecay3 = DARKGRAY;
  } else {
    colorBackground = WHITE;
    colorForeground = BLACK;
    colorAgentDecay1 = DARKGRAY;
    colorAgentDecay2 = GRAY;
    colorAgentDecay3 = LIGHTGRAY;
  }
};
bool cGlobal::GetDarkMode(){ return darkMode; };

Color cGlobal::GetColorBackground(){ return colorBackground; };
Color cGlobal::GetColorForeground(){ return colorForeground; };
Color cGlobal::GetColorAgentDecay1(){ return colorAgentDecay1; };
Color cGlobal::GetColorAgentDecay2(){ return colorAgentDecay2; };
Color cGlobal::GetColorAgentDecay3(){ return colorAgentDecay3; };