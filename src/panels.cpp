#include "panels.h"

cPanel::cPanel(int width, int height, int offsetX = 0, int offsetY = 0, int margin = 0) 
  : panelMargin_{margin}
{
  //mPanelWidth = width;
  //mPanelHeight = height;
  //mPanelLeftX = offsetX;
  //mPanelTopY = offsetY;
  //mPanelMargin = margin;

  panelContentLeftX_ = panelLeftX_ + panelMargin_;
  panelContentTopY_ = panelTopY_ + panelMargin_;
  panelContentRightX_ = panelLeftX_ + panelWidth_ - panelMargin_;
  panelContentBottomY_ = panelTopY_ + panelHeight_ - panelMargin_;
  panelContentWidth_ = panelWidth_ - (2 * panelMargin_);
  panelContentHeight_ = panelHeight_ - (2 * panelMargin_);
}

int cPanel::GetPanelRightX() {
  return panelLeftX_ + panelWidth_;
}

int cPanel::GetPanelBottomY() {
  return panelTopY_ + panelHeight_;
}

int cPanel::GetPanelContentLeftX() {
  panelContentLeftX_ = panelLeftX_ + panelMargin_;
  return panelContentLeftX_;
}

int cPanel::GetPanelContentTopY() {
  panelContentTopY_ = panelTopY_ + panelMargin_;
  return panelContentTopY_;
}

int cPanel::GetPanelContentRightX() {
  panelContentRightX_ = panelLeftX_ + panelWidth_ - panelMargin_;
  return panelContentRightX_;
}

int cPanel::GetPanelContentBottomY() {
  panelContentBottomY_ = panelTopY_ + panelHeight_ - panelMargin_;
  return panelContentBottomY_;
}

int cPanel::GetPanelContentWidth() {
  panelContentWidth_ = panelWidth_ - (2 * panelMargin_);
  return panelContentWidth_;
}

int cPanel::GetPanelContentHeight() {
  panelContentHeight_ = panelHeight_ - (2 * panelMargin_);
  return panelContentHeight_;
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
