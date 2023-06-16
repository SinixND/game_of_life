#ifndef GLOBALS_H
#define GLOBALS_H

#include <raylib.h>

// NOT CUSTOMIZABLE BY USER
//---------------------------------
class cGlobal
{
public:
  cGlobal();

  // GUI ELEMENTS
  float textSizeDefault;
  float guiButtonBaseWidth;
  float guiButtonBaseHeight;

private:
  // DARK MODE
  bool darkMode;
  Color colorBackground;
  Color colorForeground;

public:
  void ToggleDarkMode();
  bool GetDarkMode();

  Color GetColorBackground();
  Color GetColorForeground();
};
extern cGlobal global; // declare extern object

#endif