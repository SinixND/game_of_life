#include "panels.h"

cPanel::cPanel(int width, int height, int offsetX = 0, int offsetY = 0, int margin = 0) 
  : Rectangle(offsetX, offsetY, width, height)
  , mPanelMargin{margin}
{
  //mPanelWidth = width;
  //mPanelHeight = height;
  //mPanelLeftX = offsetX;
  //mPanelTopY = offsetY;
  //mPanelMargin = margin;

  mPanelContentLeftX = mPanelLeftX + mPanelMargin;
  mPanelContentTopY = mPanelTopY + mPanelMargin;
  mPanelContentRightX = mPanelLeftX + mPanelWidth - mPanelMargin;
  mPanelContentBottomY = mPanelTopY + mPanelHeight - mPanelMargin;
  mPanelContentWidth = mPanelWidth - (2 * mPanelMargin);
  mPanelContentHeight = mPanelHeight - (2 * mPanelMargin);
}

int cPanel::GetPanelRightX() {
  return mPanelLeftX + mPanelWidth;
}

int cPanel::GetPanelBottomY() {
  return mPanelTopY + mPanelHeight;
}

int cPanel::GetPanelContentLeftX() {
  mPanelContentLeftX = mPanelLeftX + mPanelMargin;
  return mPanelContentLeftX;
}

int cPanel::GetPanelContentTopY() {
  mPanelContentTopY = mPanelTopY + mPanelMargin;
  return mPanelContentTopY;
}

int cPanel::GetPanelContentRightX() {
  mPanelContentRightX = mPanelLeftX + mPanelWidth - mPanelMargin;
  return mPanelContentRightX;
}

int cPanel::GetPanelContentBottomY() {
  mPanelContentBottomY = mPanelTopY + mPanelHeight - mPanelMargin;
  return mPanelContentBottomY;
}

int cPanel::GetPanelContentWidth() {
  mPanelContentWidth = mPanelWidth - (2 * mPanelMargin);
  return mPanelContentWidth;
}

int cPanel::GetPanelContentHeight() {
  mPanelContentHeight = mPanelHeight - (2 * mPanelMargin);
  return mPanelContentHeight;
}

int AlignHorizontalLeft(cPanel panel, int offset) {
  return panel.GetPanelContentLeftX() + offset;
}

int AlignHorizontalCenter(cPanel panel, int contentWidth, int offset) {
  return panel.GetPanelContentLeftX() + ((panel.GetPanelContentWidth() - contentWidth) / 2) + offset;
}

int AlignHorizontalRight(cPanel panel, int contentWidth, int offset) {
  return panel.GetPanelContentLeftX() + panel.GetPanelContentWidth() - contentWidth - offset;
}

int AlignVerticalTop(cPanel panel, int offset) {
  return panel.GetPanelContentTopY() + offset;
}

int AlignVerticalCenter(cPanel panel, int contentHeight, int offset) {
  return panel.GetPanelContentTopY() + ((panel.GetPanelContentHeight() - contentHeight) / 2) + offset;
}

int AlignVerticalBottom(cPanel panel, int contentHeight, int offset) {
  return panel.GetPanelContentTopY() + (panel.GetPanelContentHeight() - contentHeight - offset);
}