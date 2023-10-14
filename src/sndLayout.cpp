#include "sndLayout.h"

#define DEBUGGING

#include <raygui.h>
#include <raylib.h>
#include <vector>
#include "sndGlobals.h"

sndWrapper::sndWrapper()
{
    Update();
};

sndWrapper::sndWrapper(int left, int top, int right, int bottom)
{
    SetOuterLeft(left);
    SetOuterTop(top);
    SetOuterRight(right);
    SetOuterBottom(bottom);
};

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
    DrawRectangleLinesEx(frameRect, this->GetFrameWeight(), this->GetFrameColor());

    if (wrappers_.size() == 0) return;

    for (auto wrapper : wrappers_)
    {
        wrapper.Render();
    }
}

void sndWrapper::AddWrapper(sndWrapper wrapper)
{
    wrappers_.push_back(wrapper);
}

void sndWrapper::ClearWrappers()
{
    wrappers_.clear();
}

int sndWrapper::GetOuterLeft(){ return outerLeft_; }
void sndWrapper::SetOuterLeft(int outerLeft){ outerLeft_ = outerLeft; }
int sndWrapper::GetOuterTop(){ return outerTop_; }
void sndWrapper::SetOuterTop(int outerTop){ outerTop_ = outerTop; }
int sndWrapper::GetOuterRight(){ return outerRight_; }
void sndWrapper::SetOuterRight(int outerRight)
{ 
    outerRight_ = outerRight;
    outerWidth_ = outerRight_ - outerLeft_;
    Update();
}

int sndWrapper::GetOuterBottom(){ return outerBottom_; }
void sndWrapper::SetOuterBottom(int outerBottom)
{ 
    outerBottom_ = outerBottom;
    outerHeight_ = outerBottom_ - outerTop_;
    Update();
}

int sndWrapper::GetOuterWidth(){ return outerWidth_; }
void sndWrapper::SetOuterWidth(int outerWidth)
{ 
    outerWidth_ = outerWidth;
    outerRight_ = outerLeft_ + outerWidth_;
    Update();
}

int sndWrapper::GetOuterHeight(){ return outerHeight_; }
void sndWrapper::SetOuterHeight(int outerHeight)
{ 
    outerHeight_ = outerHeight;
    outerBottom_ = outerTop_ + outerHeight_;
    Update();
}

int sndWrapper::GetMargin(){ return margin_; }
void sndWrapper::SetMargin(int marginWeight)
{
    margin_ = marginWeight;

    sndWrapper margin(
        this->GetOuterLeft(),
        this->GetOuterTop(),
        this->GetOuterRight(),
        this->GetOuterBottom());
    margin.SetFrameWeight(marginWeight);

#ifdef DEBUGGING
    margin.SetFrameColor(RED);
#endif

    AddWrapper(margin);
}

int sndWrapper::GetBorder(){ return border_; }
void sndWrapper::SetBorder(int borderWeight)
{
    border_ = borderWeight;

    sndWrapper border(
        this->GetOuterLeft() + this->GetMargin(),
        this->GetOuterTop() + this->GetMargin(),
        this->GetOuterRight() - this->GetMargin(),
        this->GetOuterBottom() - this->GetMargin());
    border.SetFrameWeight(borderWeight);

#ifdef DEBUGGING
    border.SetFrameColor(GRAY);
#endif

    AddWrapper(border);
}

int sndWrapper::GetPadding(){ return padding_; }
void sndWrapper::SetPadding(int paddingWeight)
{
    padding_ = paddingWeight;

    sndWrapper padding(
        this->GetOuterLeft() + this->GetMargin() + this->GetBorder(),
        this->GetOuterTop() + this->GetMargin() + this->GetBorder(),
        this->GetOuterRight() - this->GetMargin() - this->GetBorder(),
        this->GetOuterBottom() - this->GetMargin() - this->GetBorder());
    padding.SetFrameWeight(paddingWeight);

#ifdef DEBUGGING
    padding.SetFrameColor(GREEN);
#endif

    AddWrapper(padding);
}

int sndWrapper::GetFrameWeight(){ return frameWeight_; }
void sndWrapper::SetFrameWeight(int frameWeight){ frameWeight_ = frameWeight; }
Color sndWrapper::GetFrameColor(){ return frameColor_; }
void sndWrapper::SetFrameColor(Color frameColor){ frameColor_ = frameColor; }


int sndWrapper::GetInnerLeft(){ return innerLeft_; }
int sndWrapper::GetInnerTop(){ return innerTop_; }
int sndWrapper::GetInnerRight(){ return innerRight_; }
int sndWrapper::GetInnerBottom(){ return innerBottom_; }
int sndWrapper::GetInnerWidth(){ return innerWidth_; }
int sndWrapper::GetInnerHeight(){ return innerHeight_; }

std::vector<sndWrapper> sndWrapper::GetWrappers()
{
    return wrappers_;
}

void sndWrapper::Update()
{
    frameWeight_ = margin_ + border_ + padding_;

    innerLeft_ = GetOuterLeft() + frameWeight_;
    innerTop_ = GetOuterTop() + frameWeight_;
    innerRight_ = GetOuterRight() - frameWeight_;
    innerBottom_ = GetOuterBottom() - frameWeight_;
    innerWidth_ = innerRight_ - innerLeft_;
    innerHeight_ = innerBottom_ - innerTop_;
}

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