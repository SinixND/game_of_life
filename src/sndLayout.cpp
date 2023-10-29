#include "sndLayout.h"

#include "sndGlobals.h"
#include <functional>
#include <memory>
#include <raygui.h>
#include <raylib.h>
#include <vector>

#define DEBUGGING

sndWrapper::sndWrapper()
{
    Update();
};

sndWrapper::sndWrapper(const char* label)
{
    label_ = label;

    Update();
};

sndWrapper::sndWrapper(const char* label, int left, int top, int right, int bottom)
{
    label_ = label;

    ResizeOuterLeft(left);
    ResizeOuterTop(top);
    ResizeOuterRight(right);
    ResizeOuterBottom(bottom);

    Update();
};

void sndWrapper::Render()
{
    Rectangle frameRect{
        static_cast<float>(GetOuterLeft()),
        static_cast<float>(GetOuterTop()),
        static_cast<float>(GetOuterWidth()),
        static_cast<float>(GetOuterHeight())};
    DrawRectangleLinesEx(frameRect, this->GetFrameWeight(), this->GetFrameColor());

    if (wrappers_.size() == 0)
    {
        return;
    }

    for (auto wrapper : wrappers_)
    {
        wrapper->Render();
    }
}

void sndWrapper::AddWrapper(std::shared_ptr<sndWrapper> wrapper)
{
    wrappers_.push_back(wrapper);
}

void sndWrapper::ClearWrappers()
{
    wrappers_.clear();
}

void sndWrapper::Update()
{
    frameWeight_ = margin_ + border_ + padding_;

    innerLeft_ = outerLeft_ + frameWeight_;
    innerTop_ = outerTop_ + frameWeight_;
    innerRight_ = outerRight_ - frameWeight_;
    innerBottom_ = outerBottom_ - frameWeight_;
    innerWidth_ = innerRight_ - innerLeft_;
    innerHeight_ = innerBottom_ - innerTop_;
}

int sndWrapper::GetOuterLeft() { return outerLeft_; }
void sndWrapper::ResizeOuterLeft(int outerLeft)
{
    outerLeft_ = outerLeft;
    outerWidth_ = outerRight_ - outerLeft_;
    Update();
}

void sndWrapper::MoveOuterLeft(int outerLeft)
{
    outerLeft_ = outerLeft;
    outerRight_ = outerLeft_ + outerWidth_;
    Update();
}

int sndWrapper::GetOuterTop() { return outerTop_; }
void sndWrapper::ResizeOuterTop(int outerTop)
{
    outerTop_ = outerTop;
    outerHeight_ = outerBottom_ - outerTop_;
    Update();
}

void sndWrapper::MoveOuterTop(int outerTop)
{
    outerTop_ = outerTop;
    outerBottom_ = outerTop_ + outerHeight_;
    Update();
}

int sndWrapper::GetOuterRight() { return outerRight_; }
void sndWrapper::ResizeOuterRight(int outerRight)
{
    outerRight_ = outerRight;
    outerWidth_ = outerRight_ - outerLeft_;
    Update();
}

void sndWrapper::MoveOuterRight(int outerRight)
{
    outerRight_ = outerRight;
    outerLeft_ = outerRight_ - outerWidth_;
    Update();
}

int sndWrapper::GetOuterBottom() { return outerBottom_; }
void sndWrapper::ResizeOuterBottom(int outerBottom)
{
    outerBottom_ = outerBottom;
    outerHeight_ = outerBottom_ - outerTop_;
    Update();
}

void sndWrapper::MoveOuterBottom(int outerBottom)
{
    outerBottom_ = outerBottom;
    outerTop_ = outerBottom_ - outerHeight_;
    Update();
}

int sndWrapper::GetOuterWidth() { return outerWidth_; }
int sndWrapper::GetOuterHeight() { return outerHeight_; }

int sndWrapper::GetMargin() { return margin_; }
void sndWrapper::SetMargin(int marginWeight)
{
    margin_ = marginWeight;

    auto margin = std::make_shared<sndWrapper>(
        "margin",
        this->GetOuterLeft(),
        this->GetOuterTop(),
        this->GetOuterRight(),
        this->GetOuterBottom());
    margin->SetFrameWeight(marginWeight);

#ifdef DEBUGGING
    margin->SetFrameColor(RED);
#endif

    AddWrapper(margin);
    Update();
}

int sndWrapper::GetBorder() { return border_; }
void sndWrapper::SetBorder(int borderWeight)
{
    border_ = borderWeight;

    auto border = std::make_shared<sndWrapper>(
        "border",
        this->GetOuterLeft() + this->GetMargin(),
        this->GetOuterTop() + this->GetMargin(),
        this->GetOuterRight() - this->GetMargin(),
        this->GetOuterBottom() - this->GetMargin());
    border->SetFrameWeight(borderWeight);

#ifdef DEBUGGING
    border->SetFrameColor(GRAY);
#endif

    AddWrapper(border);
    Update();
}

int sndWrapper::GetPadding() { return padding_; }
void sndWrapper::SetPadding(int paddingWeight)
{
    padding_ = paddingWeight;

    auto padding = std::make_shared<sndWrapper>(
        "padding",
        this->GetOuterLeft() + this->GetMargin() + this->GetBorder(),
        this->GetOuterTop() + this->GetMargin() + this->GetBorder(),
        this->GetOuterRight() - this->GetMargin() - this->GetBorder(),
        this->GetOuterBottom() - this->GetMargin() - this->GetBorder());
    padding->SetFrameWeight(paddingWeight);

#ifdef DEBUGGING
    padding->SetFrameColor(GREEN);
#endif

    AddWrapper(padding);
    Update();
}

int sndWrapper::GetFrameWeight() { return frameWeight_; }
void sndWrapper::SetFrameWeight(int frameWeight) { frameWeight_ = frameWeight; }
Color sndWrapper::GetFrameColor() { return frameColor_; }
void sndWrapper::SetFrameColor(Color frameColor) { frameColor_ = frameColor; }

int sndWrapper::GetInnerLeft() { return innerLeft_; }
int sndWrapper::GetInnerTop() { return innerTop_; }
int sndWrapper::GetInnerRight() { return innerRight_; }
int sndWrapper::GetInnerBottom() { return innerBottom_; }
int sndWrapper::GetInnerWidth() { return innerWidth_; }
int sndWrapper::GetInnerHeight() { return innerHeight_; }

sndButton::sndButton()
    : sndWrapper() {}

sndButton::sndButton(const char* label)
    : sndWrapper(label) {}

sndButton::sndButton(const char* label, std::function<void()> fn, int left, int top, int right, int bottom)
    : sndWrapper(label, left, top, right, bottom)
{
    SetAction(fn);
}

sndButton::sndButton(const char* label, std::function<void()> fn, sndWrapper* parent, sndAlign flags, int offset)
    : sndWrapper(label, 0, 0, MeasureText(label, global.textSizeDefault) + global.guiButtonBaseWidth, global.textSizeDefault + global.guiButtonBaseHeight)
{
    SetAction(fn);

    AlignToParent(parent, flags, offset);
}

void sndButton::Render()
{
    sndWrapper::Render();

    if (GuiButton(
            (Rectangle){
                static_cast<float>(GetInnerLeft()),
                static_cast<float>(GetInnerTop()),
                static_cast<float>(GetInnerWidth()),
                static_cast<float>(GetInnerHeight())},
            GetLabel()))
    {
        GetAction()();
    };
}

const char* sndButton::GetLabel()
{
    return label_;
}

std::function<void()> sndButton::GetAction()
{
    return action_;
}

void sndButton::SetAction(std::function<void()> action)
{
    action_ = action;
}

void sndButton::AlignToParent(sndWrapper* parent, sndAlign flags, int offset)
{
    int positionLeft = 0;
    int positionTop = 0;

    if (flags & LEFT)
    {
        positionLeft = AlignHorizontalLeft(parent, offset);
        alignedHorizontal = LEFT;
    }
    else if (flags & CENTER_HORIZONTAL)
    {
        positionLeft = AlignHorizontalCenter(parent, GetOuterWidth(), offset);
        alignedHorizontal = CENTER_HORIZONTAL;
    }
    else if (flags & RIGHT)
    {
        positionLeft = AlignHorizontalRight(parent, GetOuterWidth(), offset);
        alignedHorizontal = RIGHT;
    }

    if (flags & TOP)
    {
        positionTop = AlignVerticalTop(parent, offset);
        alignedVertical = TOP;
    }
    else if (flags & CENTER_VERTICAL)
    {
        positionTop = AlignVerticalCenter(parent, GetOuterHeight(), offset);
        alignedVertical = CENTER_VERTICAL;
    }
    else if (flags & BOTTOM)
    {
        positionTop = AlignVerticalBottom(parent, GetOuterHeight(), offset);
        alignedVertical = BOTTOM;
    };

    MoveOuterLeft(positionLeft);
    MoveOuterTop(positionTop);
}

void sndButton::AttachToLeft(sndButton* parent)
{
    parent_ = parent;

    if (alignedHorizontal == CENTER_HORIZONTAL)
    {
        sndButton* nextParent = parent;

        do
        {
            nextParent->MoveOuterLeft(nextParent->GetOuterLeft() + GetOuterWidth() / 2);
            nextParent = nextParent->parent_;
        } while (nextParent != nullptr);
    }

    MoveOuterRight(parent->GetOuterLeft());
}

void sndButton::AttachToTop(sndButton* parent)
{
    parent_ = parent;

    if (alignedVertical == CENTER_VERTICAL)
    {
        sndButton* nextParent = parent;

        do
        {
            nextParent->MoveOuterTop(nextParent->GetOuterTop() + GetOuterHeight() / 2);
            nextParent = nextParent->parent_;
        } while (nextParent != nullptr);
    }

    MoveOuterBottom(parent->GetOuterTop());

    if (parent->GetInnerWidth() < (MeasureText(GetLabel(), global.textSizeDefault) + global.guiButtonBaseWidth))
    {
        parent->ResizeOuterLeft(GetOuterLeft());
        parent->ResizeOuterRight(GetOuterRight());
    }
    else
    {
        ResizeOuterLeft(parent->GetOuterLeft());
        ResizeOuterRight(parent->GetOuterRight());
    }
}

void sndButton::AttachToRight(sndButton* parent)
{
    parent_ = parent;

    if (alignedHorizontal == CENTER_HORIZONTAL)
    {
        sndButton* nextParent = parent;

        do
        {
            nextParent->MoveOuterRight(nextParent->GetOuterRight() - (GetOuterWidth() / 2));
            nextParent = nextParent->parent_;
        } while (nextParent != nullptr);
    }

    MoveOuterLeft(parent->GetOuterRight());
}

void sndButton::AttachToBottom(sndButton* parent)
{
    parent_ = parent;

    if (alignedVertical == CENTER_VERTICAL)
    {
        sndButton* nextParent = parent;

        do
        {
            nextParent->MoveOuterBottom(nextParent->GetOuterBottom() - GetOuterHeight() / 2);
            nextParent = nextParent->parent_;
        } while (nextParent != nullptr);
    }

    MoveOuterTop(parent->GetOuterBottom());

    if (parent->GetInnerWidth() < (MeasureText(GetLabel(), global.textSizeDefault) + global.guiButtonBaseWidth))
    {
        parent->ResizeOuterLeft(GetOuterLeft());
        parent->ResizeOuterRight(GetOuterRight());
    }
    else
    {
        ResizeOuterLeft(parent->GetOuterLeft());
        ResizeOuterRight(parent->GetOuterRight());
    }
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
