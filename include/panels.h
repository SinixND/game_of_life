#ifndef PANELS_H
#define PANELS_H

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

int AlignHorizontalLeft(cPanel panel, int offset);
int AlignHorizontalCenter(cPanel panel, int contentWidth, int offset);
int AlignHorizontalRight(cPanel panel, int contentWidth, int offset);
int AlignVerticalTop(cPanel panel, int offset);
int AlignVerticalCenter(cPanel panel, int contentHeight, int offset);
int AlignVerticalBottom(cPanel panel, int contentHeight, int offset);

#endif
