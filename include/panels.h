#ifndef PANELS_H
#define PANELS_H

#include "raylib.h"

class cPanel : Rectangle {
public:
  cPanel(int width, int height, int offsetX, int offsetY, int margin);

  int mPanelWidth;
  int mPanelHeight;
  int mPanelLeftX;
  int mPanelTopY;
  int mPanelMargin;

private:
  int mPanelRightX;
  int mPanelBottomY;
  int mPanelContentLeftX;
  int mPanelContentTopY;
  int mPanelContentRightX;
  int mPanelContentBottomY;
  int mPanelContentWidth;
  int mPanelContentHeight;

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
