#ifndef PANELS_H
#define PANELS_H
// panel class used to provide an entity derived from Rectangle to get additional values to the rectangle ones 
// also introduces methods to position 

#include "raylib.h"

class cPanel : Rectangle {
public:
  cPanel(float width, float height, float offsetX, float offsetY, float margin);

  int panelWidth_;
  int panelHeight_;
  int panelLeftX_;
  int panelTopY_;
  int panelMargin_;

private:
  int panelRightX_;
  int panelBottomY_;
  int panelContentLeftX_;
  int panelContentTopY_;
  int panelContentRightX_;
  int panelContentBottomY_;
  int panelContentWidth_;
  int panelContentHeight_;

public:
  int GetPanelRightX();
  int GetPanelBottomY();

  int GetPanelContentLeftX();
  int GetPanelContentTopY();
  int GetPanelContentRightX();
  int GetPanelContentBottomY();
  int GetPanelContentWidth();
  int GetPanelContentHeight();
};

// Align function to return the position relative to the parent (first argument)
int AlignHorizontalLeft(Rectangle parent, int offset);
int AlignHorizontalCenter(Rectangle parent, int objectWidth, int offset);
int AlignHorizontalRight(Rectangle parent, int objectWidth, int offset);
int AlignVerticalTop(Rectangle parent, int offset);
int AlignVerticalCenter(Rectangle parent, int objectHeight, int offset);
int AlignVerticalBottom(Rectangle parent, int objectHeight, int offset);

#endif
