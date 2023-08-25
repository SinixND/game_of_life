#include "panels.h"

Panel::Panel(float offsetX, float offsetY, float width, float height, float margin)
    : Width_(width)
    , Height_(height)
    , LeftX_(offsetX)
    , TopY_(offsetY)
    , Margin_(margin)
{
    x = LeftX_;
    y = TopY_;
    width = Width_;
    height = Height_;

    ContentLeftX_ = LeftX_ + Margin_;
    ContentTopY_ = TopY_ + Margin_;
    ContentRightX_ = LeftX_ + Width_ - Margin_;
    ContentBottomY_ = TopY_ + Height_ - Margin_;
    ContentWidth_ = Width_ - (2 * Margin_);
    ContentHeight_ = Height_ - (2 * Margin_);
}

float Panel::GetRightX()
{
    return LeftX_ + Width_;
}

float Panel::GetBottomY()
{
    return TopY_ + Height_;
}

float Panel::GetCenterX()
{
    return Width_ / 2;
}

float Panel::GetCenterY()
{
    return Height_ / 2;
}

float Panel::GetContentLeftX()
{
    ContentLeftX_ = LeftX_ + Margin_;
    return ContentLeftX_;
}

float Panel::GetContentTopY()
{
    ContentTopY_ = TopY_ + Margin_;
    return ContentTopY_;
}

float Panel::GetContentRightX()
{
    ContentRightX_ = LeftX_ + Width_ - Margin_;
    return ContentRightX_;
}

float Panel::GetContentBottomY()
{
    ContentBottomY_ = TopY_ + Height_ - Margin_;
    return ContentBottomY_;
}

float Panel::GetContentWidth()
{
    ContentWidth_ = Width_ - (2 * Margin_);
    return ContentWidth_;
}

float Panel::GetContentHeight()
{
    ContentHeight_ = Height_ - (2 * Margin_);
    return ContentHeight_;
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
