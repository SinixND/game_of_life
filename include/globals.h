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
  Color colorAgentDecay1;
  Color colorAgentDecay2;
  Color colorAgentDecay3;

public:
  void SetDarkMode(bool arg);
  bool GetDarkMode();
  Color GetColorBackground();
  Color GetColorForeground();
  Color GetColorAgentDecay1();
  Color GetColorAgentDecay2();
  Color GetColorAgentDecay3();
};
extern cGlobal global;

#endif