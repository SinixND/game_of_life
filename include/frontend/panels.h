#ifndef PANELS_H
#define PANELS_H
// panel class used to provide an entity derived from Rectangle to get additional values to the rectangle ones
// also introduces methods to position

#include <raylib.h>

class Panel : public Rectangle
{
public:
    Panel(float offsetX, float offsetY, float width, float height, float margin);

    float Width_;
    float Height_;
    float LeftX_;
    float TopY_;
    float Margin_;

private:
    float RightX_;
    float BottomY_;
    float ContentLeftX_;
    float ContentTopY_;
    float ContentRightX_;
    float ContentBottomY_;
    float ContentWidth_;
    float ContentHeight_;

public:
    float GetRightX();
    float GetBottomY();
    float GetCenterX();
    float GetCenterY();

    float GetContentLeftX();
    float GetContentTopY();
    float GetContentRightX();
    float GetContentBottomY();
    float GetContentWidth();
    float GetContentHeight();
};

// Align function to return the position relative to the parent (first argument)
float AlignHorizontalLeft(Panel parent, float offset);
float AlignHorizontalCenter(Panel parent, float objectWidth, float offset);
float AlignHorizontalRight(Panel parent, float objectWidth, float offset);
float AlignVerticalTop(Panel parent, float offset);
float AlignVerticalCenter(Panel parent, float objectHeight, float offset);
float AlignVerticalBottom(Panel parent, float objectHeight, float offset);

#endif
