#include "globals.h"

#include "raylib.h"

//---------------------------------
// NOT CUSTOMIZABLE BY USER
//---------------------------------
cGlobal global; // declare extern object
cGlobal::cGlobal(){
  // GUI ELEMENTS
  // default text size is 16
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

void cGlobal::setDarkMode(bool arg){
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
bool cGlobal::getDarkMode(){ return darkMode; };

Color cGlobal::getColorBackground(){ return colorBackground; };
Color cGlobal::getColorForeground(){ return colorForeground; };
Color cGlobal::getColorAgentDecay1(){ return colorAgentDecay1; };
Color cGlobal::getColorAgentDecay2(){ return colorAgentDecay2; };
Color cGlobal::getColorAgentDecay3(){ return colorAgentDecay3; };