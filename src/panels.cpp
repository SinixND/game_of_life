#include "panels.h"

cPanel::cPanel(float offsetX, float offsetY, float panelWidth, float panelHeight, float margin)
    : panelWidth_(panelWidth)
    , panelHeight_(panelHeight)
    , panelLeftX_(offsetX)
    , panelTopY_(offsetY)
    , panelMargin_(margin)
{
    x = panelLeftX_;
    y = panelTopY_;
    width = panelWidth_;
    height = panelHeight_;

    panelContentLeftX_ = panelLeftX_ + panelMargin_;
    panelContentTopY_ = panelTopY_ + panelMargin_;
    panelContentRightX_ = panelLeftX_ + panelWidth_ - panelMargin_;
    panelContentBottomY_ = panelTopY_ + panelHeight_ - panelMargin_;
    panelContentWidth_ = panelWidth_ - (2 * panelMargin_);
    panelContentHeight_ = panelHeight_ - (2 * panelMargin_);
}

float cPanel::GetPanelRightX()
{
    return panelLeftX_ + panelWidth_;
}

float cPanel::GetPanelBottomY()
{
    return panelTopY_ + panelHeight_;
}

float cPanel::GetPanelCenterX()
{
    return panelWidth_ / 2;
}

float cPanel::GetPanelCenterY()
{
    return panelHeight_ / 2;
}

float cPanel::GetPanelContentLeftX()
{
    panelContentLeftX_ = panelLeftX_ + panelMargin_;
    return panelContentLeftX_;
}

float cPanel::GetPanelContentTopY()
{
    panelContentTopY_ = panelTopY_ + panelMargin_;
    return panelContentTopY_;
}

float cPanel::GetPanelContentRightX()
{
    panelContentRightX_ = panelLeftX_ + panelWidth_ - panelMargin_;
    return panelContentRightX_;
}

float cPanel::GetPanelContentBottomY()
{
    panelContentBottomY_ = panelTopY_ + panelHeight_ - panelMargin_;
    return panelContentBottomY_;
}

float cPanel::GetPanelContentWidth()
{
    panelContentWidth_ = panelWidth_ - (2 * panelMargin_);
    return panelContentWidth_;
}

float cPanel::GetPanelContentHeight()
{
    panelContentHeight_ = panelHeight_ - (2 * panelMargin_);
    return panelContentHeight_;
}

float AlignHorizontalLeft(cPanel parent, float offset)
{
    return parent.GetPanelContentLeftX() + offset;
}

float AlignHorizontalCenter(cPanel parent, float objectWidth, float offset)
{
    return parent.GetPanelContentLeftX() + ((parent.GetPanelContentWidth() - objectWidth) / 2) + offset;
}

float AlignHorizontalRight(cPanel parent, float objectWidth, float offset)
{
    return parent.GetPanelContentLeftX() + parent.GetPanelContentWidth() - objectWidth - offset;
}

float AlignVerticalTop(cPanel parent, float offset)
{
    return parent.GetPanelContentTopY() + offset;
}

float AlignVerticalCenter(cPanel parent, float objectHeight, float offset)
{
    return parent.GetPanelContentTopY() + ((parent.GetPanelContentHeight() - objectHeight) / 2) + offset;
}

float AlignVerticalBottom(cPanel parent, float objectHeight, float offset)
{
    return parent.GetPanelContentTopY() + (parent.GetPanelContentHeight() - objectHeight - offset);
}
