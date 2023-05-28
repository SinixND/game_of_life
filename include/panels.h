#ifndef PANELS_H
#define PANELS_H

class cPanel {
public:
  cPanel(int width, int height, int offsetX, int offsetY, int margin);

  ~cPanel();

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
  int getPanelRightX();
  int getPanelBottomY();

  int getPanelContentLeftX();
  int getPanelContentTopY();
  int getPanelContentRightX();
  int getPanelContentBottomY();
  int getPanelContentWidth();
  int getPanelContentHeight();
};

int alignHorizontalLeft(cPanel panel, int offset);
int alignHorizontalCenter(cPanel panel, int contentWidth);
int alignHorizontalRight(cPanel panel, int contentWidth, int offset);
int alignVerticalTop(cPanel panel, int offset);
int alignVerticalCenter(cPanel panel, int contentHeight);
int alignVerticalBottom(cPanel panel, int contentHeight, int offset);

#endif