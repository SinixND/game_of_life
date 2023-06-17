#ifndef PANELS_H
#define PANELS_H
// panel class used to provide an entity derived from Rectangle to get additional values to the rectangle ones
// also introduces methods to position

#include <raylib.h>

class cPanel : public Rectangle
{
  public:
  cPanel(float offsetX, float offsetY, float panelWidth, float panelHeight, float margin);

  float panelWidth_;
  float panelHeight_;
  float panelLeftX_;
  float panelTopY_;
  float panelMargin_;

  private:
  float panelRightX_;
  float panelBottomY_;
  float panelContentLeftX_;
  float panelContentTopY_;
  float panelContentRightX_;
  float panelContentBottomY_;
  float panelContentWidth_;
  float panelContentHeight_;

  public:
  float GetPanelRightX();
  float GetPanelBottomY();
  float GetPanelCenterX();
  float GetPanelCenterY();

  float GetPanelContentLeftX();
  float GetPanelContentTopY();
  float GetPanelContentRightX();
  float GetPanelContentBottomY();
  float GetPanelContentWidth();
  float GetPanelContentHeight();
};

// Align function to return the position relative to the parent (first argument)
float AlignHorizontalLeft(cPanel parent, float offset);
float AlignHorizontalCenter(cPanel parent, float objectWidth, float offset);
float AlignHorizontalRight(cPanel parent, float objectWidth, float offset);
float AlignVerticalTop(cPanel parent, float offset);
float AlignVerticalCenter(cPanel parent, float objectHeight, float offset);
float AlignVerticalBottom(cPanel parent, float objectHeight, float offset);

#endif
