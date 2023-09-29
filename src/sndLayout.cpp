#include "sndLayout.h"

// #define DEBUGGING


#include <raygui.h>
#include <raylib.h>
#include <vector>

#include "sndGlobals.h"

void sndWrapper::Append(sndWrapper& element, sndAlign flags, int offset)
{
    int positionLeft = 0;
    int positionTop = 0;

    if (flags & LEFT)
    {
        positionLeft = AlignHorizontalLeft(this, offset);
    }
    else if (flags & CENTER_HORIZONTAL)
    {
        positionLeft = AlignHorizontalCenter(this, element.GetOuterWidth(), offset);
    }
    else if (flags & RIGHT)
    {
        positionLeft = AlignHorizontalRight(this, element.GetOuterWidth(), offset);
    }

    if (flags & TOP)
    {
        positionTop = AlignVerticalTop(this, offset);
    }
    else if (flags & CENTER_VERTICAL)
    {
        positionTop = AlignVerticalCenter(this, element.GetOuterHeight(), offset);
    }
    else if (flags & BOTTOM)
    {
        positionTop = AlignVerticalBottom(this, element.GetOuterHeight(), offset);
    };

    element.SetOuterLeft(positionLeft);
    element.SetOuterTop(positionTop);
}

void sndWrapper::Render()
{
    Rectangle frameRect{
        static_cast<float>(GetOuterLeft()),
        static_cast<float>(GetOuterTop()),
        static_cast<float>(GetOuterWidth()),
        static_cast<float>(GetOuterHeight())};
    DrawRectangleLinesEx(frameRect, GetFrameWeight(), GRAY);

    if (wrapper_.size() == 0) return;

    for (auto wrapper : wrapper_)
    {
        wrapper.Render();
    }
}

void sndWrapper::AddWrapper(sndWrapper wrapper)
{
    wrapper_.push_back(wrapper);
}

int& sndWrapper::GetOuterLeft(){ return outerLeft_; }
void sndWrapper::SetOuterLeft(int& outerLeft){ outerLeft_ = outerLeft; }
int& sndWrapper::GetOuterTop(){ return outerTop_; }
void sndWrapper::SetOuterTop(int& outerTop){ outerTop_ = outerTop; }
int& sndWrapper::GetOuterRight(){ return outerRight_; }
void sndWrapper::SetOuterRight(int& outerRight)
{ 
    outerRight_ = outerRight;
    Update();
}

int& sndWrapper::GetOuterBottom(){ return outerBottom_; }
void sndWrapper::SetOuterBottom(int& outerBottom)
{ 
    outerBottom_ = outerBottom;
    Update();
}

int& sndWrapper::GetOuterWidth(){ return outerWidth_; }
void sndWrapper::SetOuterWidth(int& outerWidth)
{ 
    outerWidth_ = outerWidth;
    Update();
}

int& sndWrapper::GetOuterHeight(){ return outerHeight_; }
void sndWrapper::SetOuterHeight(int& outerHeight)
{ 
    outerHeight_ = outerHeight;
    Update();
}

int& sndWrapper::GetMargin(){ return margin_; }
void sndWrapper::SetMargin(int& margin)
{
    margin_ = margin;

    sndWrapper margin(this->GetOuterLeft(), this->GetOuterTop(), this->GetOuterRight(), this->GetOuterBottom());
    margin.SetFrameWeight(margin);

#ifdef DEBUGGING
    margin.SetFrameColor(BLUE);
    //Color border = YELLOW;
    //Color padding = GREEN;
#endif

    AddWrapper(margin);
}

int& sndWrapper::GetBorder(){ return border_; }
void sndWrapper::SetBorder(int& border)
{
    border_ = border;
}

int& sndWrapper::GetPadding(){ return padding_; }
void sndWrapper::SetPadding(int& padding)
{
    padding_ = padding;
}

int& sndWrapper::GetFrameWeight(){ return frameWeight_; }
void sndWrapper::SetFrameWeight(int& frameWeight){ frameWeight_ = frameWeight; }
Color sndWrapp::GetFrameColor(){ return frameColor_; }
void sndWrapp::SetFrameColor(Color frameColor){ frameColor_ = frameColor; }


int& sndWrapper::GetInnerLeft(){ return innerLeft_; }
void sndWrapper::SetInnerLeft(int& innerLeft){ innerLeft_ = innerLeft; }
int& sndWrapper::GetInnerTop(){ return innerTop_; }
void sndWrapper::SetInnerTop(int& innerTop){ innerTop_ = innerTop; }
int& sndWrapper::GetInnerRight(){ return innerRight_; }
void sndWrapper::SetInnerRight(int& innerRight){ innerRight_ = innerRight; }
int& sndWrapper::GetInnerBottom(){ return innerBottom_; }
void sndWrapper::SetInnerBottom(int& innerBottom){ innerBottom_ = innerBottom; }
int& sndWrapper::GetInnerWidth(){ return innerWidth_; }
void sndWrapper::SetInnerWidth(int& innerWidth){ innerWidth_ = innerWidth; }
int& sndWrapper::GetInnerHeight(){ return innerHeight_; }
void sndWrapper::SetInnerHeight(int& innerHeight){ innerHeight_ = innerHeight; }

void sndWrapper::Update()
{
    innerLeft_ = GetOuterLeft() + frameWeight_;
    innerTop_ = GetOuterTop() + frameWeight_;
    innerRight_ = GetOuterRight() - frameWeight_;
    innerBottom_ = GetOuterBottom() - frameWeight_;
    innerWidth_ = innerRight_ - innerLeft_;
    innerHeight_ = innerBottom_ - innerTop_;
}

//sndButton::sndButton(const char* text, int fontSize)
//{

//}

int AlignHorizontalLeft(sndWrapper* parent, int offset)
{
    return parent->GetInnerLeft() + offset;
}

int AlignHorizontalCenter(sndWrapper* parent, int objectWidth, int offset)
{
    return parent->GetInnerLeft() + ((parent->GetInnerWidth() - objectWidth) / 2) + offset;
}

int AlignHorizontalRight(sndWrapper* parent, int objectWidth, int offset)
{
    return parent->GetInnerLeft() + parent->GetInnerWidth() - objectWidth - offset;
}

int AlignVerticalTop(sndWrapper* parent, int offset)
{
    return parent->GetInnerTop() + offset;
}

int AlignVerticalCenter(sndWrapper* parent, int objectHeight, int offset)
{
    return parent->GetInnerTop() + ((parent->GetInnerHeight() - objectHeight) / 2) + offset;
}

int AlignVerticalBottom(sndWrapper* parent, int objectHeight, int offset)
{
    return parent->GetInnerTop() + (parent->GetInnerHeight() - objectHeight - offset);
}