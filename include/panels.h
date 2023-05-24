#ifndef PANELS_H
#define PANELS_H

class cPanel
{
public:
  cPanel(int width, int height, int offsetX, int offsetY, int margin);

  ~cPanel();

  // setters and getters
  void setPanelWidth(int width);
  int getPanelWidth();

  void setPanelHeight(int height);
  int getPanelHeight();

  void setPanelLeftX(int offsetX);
  int getPanelLeftX();

  void setPanelTopY(int offsetY);
  int getPanelTopY();

  void setPanelMargin(int margin);
  int getPanelMargin();

  // only getters
  int getPanelRightX();
  int getPanelBottomY();

  int getPanelContentLeftX();
  int getPanelContentTopY();
  int getPanelContentRightX();
  int getPanelContentBottomY();
  int getPanelContentWidth();
  int getPanelContentHeight();
  

private:
  int mPanelWidth;
  int mPanelHeight;
  int mPanelLeftX;
  int mPanelTopY;
  int mPanelMargin;

  int mPanelRightX;
  int mPanelBottomY;
  int mPanelContentLeftX;
  int mPanelContentTopY;
  int mPanelContentRightX;
  int mPanelContentBottomY;
  int mPanelContentWidth;
  int mPanelContentHeight;
};

int alignHorizontalLeft(cPanel panel, int offset);

int alignHorizontalCenter(cPanel panel, int contentWidth);

int alignHorizontalRight(cPanel panel, int contentWidth, int offset);

int alignVerticalTop(cPanel panel, int offset);

int alignVerticalCenter(cPanel panel, int contentHeight);

int alignVerticalBottom(cPanel panel, int contentHeight, int offset);

#endif