#include "panels.h"

cPanel::cPanel(int width, int height, int offsetX = 0, int offsetY = 0, int margin = 0) {
  mPanelWidth = width;
  mPanelHeight = height;
  mPanelLeftX = offsetX;
  mPanelTopY = offsetY;
  mPanelMargin = margin;

  mPanelContentLeftX = mPanelLeftX + mPanelMargin;
  mPanelContentTopY = mPanelTopY + mPanelMargin;
  mPanelContentRightX = mPanelLeftX + mPanelWidth - mPanelMargin;
  mPanelContentBottomY = mPanelTopY + mPanelHeight - mPanelMargin;
  mPanelContentWidth = mPanelWidth - (2 * mPanelMargin);
  mPanelContentHeight = mPanelHeight - (2 * mPanelMargin);
}

cPanel::~cPanel(){}

void cPanel::setPanelWidth(int width) {
  mPanelWidth = width;
}

int cPanel::getPanelWidth() {
  return mPanelWidth;
}

void cPanel::setPanelHeight(int height) {
  mPanelHeight = height;
}

int cPanel::getPanelHeight() {
  return mPanelHeight;
}

void cPanel::setPanelLeftX(int offsetX) {
  mPanelLeftX = offsetX;
}

int cPanel::getPanelLeftX() {
  return mPanelLeftX;
}

void cPanel::setPanelTopY(int offsetY) {
  mPanelTopY = offsetY;
}

int cPanel::getPanelTopY() {
  return mPanelTopY;
}

void cPanel::setPanelMargin(int margin) {
  mPanelMargin = margin;
}

int cPanel::getPanelMargin() {
  return mPanelMargin;
}

int cPanel::getPanelRightX() {
  return mPanelLeftX + mPanelWidth;
}

int cPanel::getPanelBottomY() {
  return mPanelTopY + mPanelHeight;
}

int cPanel::getPanelContentLeftX() {
  mPanelContentLeftX = mPanelLeftX + mPanelMargin;
  return mPanelContentLeftX;
}

int cPanel::getPanelContentTopY() {
  mPanelContentTopY = mPanelTopY + mPanelMargin;
  return mPanelContentTopY;
}

int cPanel::getPanelContentRightX() {
  mPanelContentRightX = mPanelLeftX + mPanelWidth - mPanelMargin;
  return mPanelContentRightX;
}

int cPanel::getPanelContentBottomY() {
  mPanelContentBottomY = mPanelTopY + mPanelHeight - mPanelMargin;
  return mPanelContentBottomY;
}

int cPanel::getPanelContentWidth() {
  mPanelContentWidth = mPanelWidth - (2 * mPanelMargin);
  return mPanelContentWidth;
}

int cPanel::getPanelContentHeight() {
  mPanelContentHeight = mPanelHeight - (2 * mPanelMargin);
  return mPanelContentHeight;
}

int alignHorizontalLeft(cPanel panel, int offset) {
  return panel.getPanelContentLeftX() + offset;
}

int alignHorizontalCenter(cPanel panel, int contentWidth) {
  return panel.getPanelContentLeftX() + ((panel.getPanelContentWidth() - contentWidth) / 2);
}

int alignHorizontalRight(cPanel panel, int contentWidth, int offset) {
  return panel.getPanelContentLeftX() + (panel.getPanelContentWidth() - contentWidth - offset);
}

int alignVerticalTop(cPanel panel, int offset) {
  return panel.getPanelContentTopY() + offset;
}

int alignVerticalCenter(cPanel panel, int contentHeight) {
  return panel.getPanelContentTopY() + ((panel.getPanelContentHeight() - contentHeight) / 2);
}

int alignVerticalBottom(cPanel panel, int contentHeight, int offset) {
  return panel.getPanelContentTopY() + (panel.getPanelContentHeight() - contentHeight - offset);
}