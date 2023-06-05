#ifndef GLOBALS_H
#define GLOBALS_H

#include "raylib.h"

//============================
// NOT CUSTOMIZABLE BY USER
//============================
class cGlobal {
public:
  cGlobal();

  // GUI ELEMENTS
  int txtSmall;
  int txtNormal;
  int guiButtonBaseWidth;
  int guiButtonBaseHeight;

private:
  // DARK MODE
  bool darkMode;
  Color colorBackground;
  Color colorForeground;
  Color colorAgentDecay1;
  Color colorAgentDecay2;
  Color colorAgentDecay3;

public:
  void setDarkMode(bool arg);
  bool getDarkMode();
  Color getColorBackground();
  Color getColorForeground();
  Color getColorAgentDecay1();
  Color getColorAgentDecay2();
  Color getColorAgentDecay3();
};
extern cGlobal global;

#endif