#ifndef GLOBALS_H
#define GLOBALS_H

#include "raylib.h"

// NOT CUSTOMIZABLE BY USER
//---------------------------------
class cGlobal {
public:
  cGlobal();

  // GUI ELEMENTS
  Font font;
  float txtSmall;
  float txtNormal;
  float guiButtonBaseWidth;
  float guiButtonBaseHeight;

private:
  // DARK MODE
  bool darkMode;
  Color colorBackground;
  Color colorForeground;
  Color colorAgentFaded1;
  Color colorAgentFaded2;
  Color colorAgentFaded3;

public:
  void SetDarkMode(bool arg);
  bool GetDarkMode();
  Color GetColorBackground();
  Color GetColorForeground();
  Color GetColorAgentFaded1();
  Color GetColorAgentFaded2();
  Color GetColorAgentFaded3();
};
extern cGlobal global;

#endif