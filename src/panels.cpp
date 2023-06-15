#include "panels.h"

cPanel::cPanel(float width, float height, float offsetX = 0, float offsetY = 0, float margin = 0) 
  : panelWidth_{width}
  , panelHeight_{height}
  , panelLeftX_{offsetX}
  , panelTopY_{offsetY}
  , panelMargin_{margin}
{
  width = panelWidth_;
  height = panelHeight_;
  x = panelLeftX_;
  y = panelTopY_;

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

int AlignHorizontalLeft(cPanel parent, int offset) {
  return parent.GetPanelContentLeftX() + offset;
}

int AlignHorizontalCenter(cPanel parent, int objectWidth, int offset) {
  return parent.GetPanelContentLeftX() + ((parent.GetPanelContentWidth() - objectWidth) / 2) + offset;
}

int AlignHorizontalRight(cPanel parent, int objectWidth, int offset) {
  return parent.GetPanelContentLeftX() + parent.GetPanelContentWidth() - objectWidth - offset;
}

int AlignVerticalTop(cPanel parent, int offset) {
  return parent.GetPanelContentTopY() + offset;
}

int AlignVerticalCenter(cPanel parent, int objectHeight, int offset) {
  return parent.GetPanelContentTopY() + ((parent.GetPanelContentHeight() - objectHeight) / 2) + offset;
}

int AlignVerticalBottom(cPanel parent, int objectHeight, int offset) {
  return parent.GetPanelContentTopY() + (parent.GetPanelContentHeight() - objectHeight - offset);
}
