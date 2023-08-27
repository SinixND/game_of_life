#include "panels.h"

Panel::Panel(float offsetX, float offsetY, float width, float height, float margin)
    : width_(width)
    , height_(height)
    , leftX_(offsetX)
    , topY_(offsetY)
    , margin_(margin)
{
    x = leftX_;
    y = topY_;
    width = width_;
    height = height_;

    contentLeftX_ = leftX_ + margin_;
    contentTopY_ = topY_ + margin_;
    contentRightX_ = leftX_ + width_ - margin_;
    contentBottomY_ = topY_ + height_ - margin_;
    contentWidth_ = width_ - (2 * margin_);
    contentHeight_ = height_ - (2 * margin_);
}

float Panel::GetRightX()
{
    return leftX_ + width_;
}

float Panel::GetBottomY()
{
    return topY_ + height_;
}

float Panel::GetCenterX()
{
    return width_ / 2;
}

float Panel::GetCenterY()
{
    return height_ / 2;
}

float Panel::GetContentLeftX()
{
    contentLeftX_ = leftX_ + margin_;
    return contentLeftX_;
}

float Panel::GetContentTopY()
{
    contentTopY_ = topY_ + margin_;
    return contentTopY_;
}

float Panel::GetContentRightX()
{
    contentRightX_ = leftX_ + width_ - margin_;
    return contentRightX_;
}

float Panel::GetContentBottomY()
{
    contentBottomY_ = topY_ + height_ - margin_;
    return contentBottomY_;
}

float Panel::GetContentWidth()
{
    contentWidth_ = width_ - (2 * margin_);
    return contentWidth_;
}

float Panel::GetContentHeight()
{
    contentHeight_ = height_ - (2 * margin_);
    return contentHeight_;
}

float AlignHorizontalLeft(Panel parent, float offset)
{
    return parent.GetContentLeftX() + offset;
}

float AlignHorizontalCenter(Panel parent, float objectWidth, float offset)
{
    return parent.GetContentLeftX() + ((parent.GetContentWidth() - objectWidth) / 2) + offset;
}

float AlignHorizontalRight(Panel parent, float objectWidth, float offset)
{
    return parent.GetContentLeftX() + parent.GetContentWidth() - objectWidth - offset;
}

float AlignVerticalTop(Panel parent, float offset)
{
    return parent.GetContentTopY() + offset;
}

float AlignVerticalCenter(Panel parent, float objectHeight, float offset)
{
    return parent.GetContentTopY() + ((parent.GetContentHeight() - objectHeight) / 2) + offset;
}

float AlignVerticalBottom(Panel parent, float objectHeight, float offset)
{
    return parent.GetContentTopY() + (parent.GetContentHeight() - objectHeight - offset);
}
