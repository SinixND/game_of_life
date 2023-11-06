#include "sndLayout.h"

#include "sndConfigs.h"
#include "sndGlobals.h"
#include <functional>
#include <iostream>
#include <memory>
#include <raygui.h>
#include <raylib.h>
#include <vector>
#include "string.h"

#include <iostream>

#define DEBUGGING

// sndWrapper
//-------------------------------------
sndWrapper::sndWrapper(const char* label)
{
    label_ = label;

    SetMargin(margin_);
    SetBorder(border_);
    SetPadding(padding_);

    UpdateFrame();
};

sndWrapper::sndWrapper(int left, int top, int right, int bottom)
{
    ResizeOuterLeft(left);
    ResizeOuterTop(top);
    ResizeOuterRight(right);
    ResizeOuterBottom(bottom);

    UpdateFrame();
};

sndWrapper::sndWrapper(const char* label, int left, int top, int right, int bottom)
{
    label_ = label;

    ResizeOuterLeft(left);
    ResizeOuterTop(top);
    ResizeOuterRight(right);
    ResizeOuterBottom(bottom);

    SetMargin(margin_);
    SetBorder(border_);
    SetPadding(padding_);

    UpdateFrame();
};

sndWrapper::~sndWrapper(){};

void sndWrapper::Render()
{
    Rectangle frameRect{
        static_cast<float>(GetOuterLeft()),
        static_cast<float>(GetOuterTop()),
        static_cast<float>(GetOuterWidth()),
        static_cast<float>(GetOuterHeight())};

    DrawRectangleLinesEx(frameRect, this->GetFrameWeight(), this->GetFrameColor());

    //if (wrappers_.size() == 0)
    //{
        //return;
    //}

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

void sndWrapper::UpdateFrame()
{
    for (auto wrapper : wrappers_)
    {
        if (strcmp(wrapper->label_, "Margin") == 0)
        {
            wrapper->MoveOuterLeft(GetOuterLeft());
            wrapper->MoveOuterTop(GetOuterTop());
            wrapper->ResizeOuterRight(GetOuterRight());
            wrapper->ResizeOuterBottom(GetOuterBottom());
        }
        
        else if (strcmp(wrapper->label_, "Border") == 0)
        {
            wrapper->MoveOuterLeft(GetOuterLeft() + margin_);
            wrapper->MoveOuterTop(GetOuterTop() + margin_);
            wrapper->ResizeOuterRight(GetOuterRight() - margin_);
            wrapper->ResizeOuterBottom(GetOuterBottom() - margin_);
        }
        
        else if (strcmp(wrapper->label_, "Padding") == 0)
        {
            wrapper->MoveOuterLeft(GetOuterLeft() + margin_ + border_);
            wrapper->MoveOuterTop(GetOuterTop() + margin_ + border_);
            wrapper->ResizeOuterRight(GetOuterRight() - margin_ - border_);
            wrapper->ResizeOuterBottom(GetOuterBottom() - margin_ - border_);
        }
    }

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
    UpdateFrame();
}

void sndWrapper::MoveOuterLeft(int outerLeft)
{
    outerLeft_ = outerLeft;
    outerRight_ = outerLeft_ + outerWidth_;
    UpdateFrame();
}

int sndWrapper::GetOuterTop() { return outerTop_; }
void sndWrapper::ResizeOuterTop(int outerTop)
{
    outerTop_ = outerTop;
    outerHeight_ = outerBottom_ - outerTop_;
    UpdateFrame();
}

void sndWrapper::MoveOuterTop(int outerTop)
{
    outerTop_ = outerTop;
    outerBottom_ = outerTop_ + outerHeight_;
    UpdateFrame();
}

int sndWrapper::GetOuterRight() { return outerRight_; }
void sndWrapper::ResizeOuterRight(int outerRight)
{
    outerRight_ = outerRight;
    outerWidth_ = outerRight_ - outerLeft_;
    UpdateFrame();
}

void sndWrapper::MoveOuterRight(int outerRight)
{
    outerRight_ = outerRight;
    outerLeft_ = outerRight_ - outerWidth_;
    UpdateFrame();
}

int sndWrapper::GetOuterBottom() { return outerBottom_; }
void sndWrapper::ResizeOuterBottom(int outerBottom)
{
    outerBottom_ = outerBottom;
    outerHeight_ = outerBottom_ - outerTop_;
    UpdateFrame();
}

void sndWrapper::MoveOuterBottom(int outerBottom)
{
    outerBottom_ = outerBottom;
    outerTop_ = outerBottom_ - outerHeight_;
    UpdateFrame();
}

int sndWrapper::GetOuterWidth() { return outerWidth_; }
int sndWrapper::GetOuterHeight() { return outerHeight_; }

int sndWrapper::GetMargin() { return margin_; }
void sndWrapper::SetMargin(int marginWeight)
{
    margin_ = marginWeight;

    auto margin = std::make_shared<sndWrapper>(
        this->GetOuterLeft(),
        this->GetOuterTop(),
        this->GetOuterRight(),
        this->GetOuterBottom());

    margin->SetFrameWeight(marginWeight);
    margin->label_ = "Margin";

#ifdef DEBUGGING
    margin->SetFrameColor(RED);
#endif

    for (std::size_t i = 0; i < wrappers_.size(); ++i)
    {
        if (strcmp(wrappers_[i]->label_, "Margin") == 0)
        {
            wrappers_.erase(wrappers_.begin()+i);
        }
    }

    AddWrapper(margin);

    UpdateFrame();
}

int sndWrapper::GetBorder() { return border_; }
void sndWrapper::SetBorder(int borderWeight)
{
    border_ = borderWeight;

    auto border = std::make_shared<sndWrapper>(
        this->GetOuterLeft() + this->GetMargin(),
        this->GetOuterTop() + this->GetMargin(),
        this->GetOuterRight() - this->GetMargin(),
        this->GetOuterBottom() - this->GetMargin());

    border->SetFrameWeight(borderWeight);
    border->label_ = "Border";

#ifdef DEBUGGING
    border->SetFrameColor(GRAY);
#endif

    for (std::size_t i = 0; i < wrappers_.size(); ++i)
    {
        if (strcmp(wrappers_[i]->label_, "Border") == 0)
        {
            wrappers_.erase(wrappers_.begin()+i);
        }
    }

    AddWrapper(border);
    UpdateFrame();
}

int sndWrapper::GetPadding() { return padding_; }
void sndWrapper::SetPadding(int paddingWeight)
{
    padding_ = paddingWeight;

    auto padding = std::make_shared<sndWrapper>(
        this->GetOuterLeft() + this->GetMargin() + this->GetBorder(),
        this->GetOuterTop() + this->GetMargin() + this->GetBorder(),
        this->GetOuterRight() - this->GetMargin() - this->GetBorder(),
        this->GetOuterBottom() - this->GetMargin() - this->GetBorder());

    padding->SetFrameWeight(paddingWeight);
    padding->label_ = "Padding";

#ifdef DEBUGGING
    padding->SetFrameColor(GREEN);
#endif

    for (std::size_t i = 0; i < wrappers_.size(); ++i)
    {
        if (strcmp(wrappers_[i]->label_, "Padding") == 0)
        {
            wrappers_.erase(wrappers_.begin()+i);
        }
    }

    AddWrapper(padding);
    UpdateFrame();
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
//-------------------------------------

// sndElement
//-------------------------------------
sndElement::sndElement(const char* label)
    : sndWrapper(label)
{
}

sndElement::sndElement(const char* label, int fontSize, int left, int top, int right, int bottom)
    : sndWrapper(label, left, top, right, bottom)
{
    fontSize_ = fontSize;
}

sndElement::~sndElement() {};

void sndElement::AlignToParent(sndWrapper* parent, sndAlign flags, int offset)
{
    int positionLeft = 0;
    int positionTop = 0;

    if (flags & LEFT)
    {
        positionLeft = AlignHorizontalLeft(parent, offset);
        alignedHorizontal_ = LEFT;
    }
    else if (flags & CENTER_HORIZONTAL)
    {
        positionLeft = AlignHorizontalCenter(parent, GetOuterWidth(), offset);
        alignedHorizontal_ = CENTER_HORIZONTAL;
    }
    else if (flags & RIGHT)
    {
        positionLeft = AlignHorizontalRight(parent, GetOuterWidth(), offset);
        alignedHorizontal_ = RIGHT;
    }

    if (flags & TOP)
    {
        positionTop = AlignVerticalTop(parent, offset);
        alignedVertical_ = TOP;
    }
    else if (flags & CENTER_VERTICAL)
    {
        positionTop = AlignVerticalCenter(parent, GetOuterHeight(), offset);
        alignedVertical_ = CENTER_VERTICAL;
    }
    else if (flags & BOTTOM)
    {
        positionTop = AlignVerticalBottom(parent, GetOuterHeight(), offset);
        alignedVertical_ = BOTTOM;
    }

    if (positionLeft < 0 || positionTop < 0) {
        throw std::invalid_argument("Negative value. Check if parent size is big enough!");
    }

    MoveOuterLeft(positionLeft);
    MoveOuterTop(positionTop);
}

void sndElement::AttachToLeft(sndElement* parent)
{
    MoveOuterRight(parent->GetOuterLeft());
}

void sndElement::AttachToTop(sndElement* parent)
{
    MoveOuterBottom(parent->GetOuterTop());
}

void sndElement::AttachToRight(sndElement* parent)
{
    MoveOuterLeft(parent->GetOuterRight());
}

void sndElement::AttachToBottom(sndElement* parent)
{
    MoveOuterTop(parent->GetOuterBottom());
}

void sndElement::AttachToTopAndAlign(sndElement* parent)
{
    parent_ = parent;

    if (alignedVertical_ == CENTER_VERTICAL)
    {
        sndElement* nextParent = parent;

        do
        {
            nextParent->MoveOuterTop(nextParent->GetOuterTop() + GetOuterHeight() / 2);
            nextParent = nextParent->parent_;
        } while (nextParent != nullptr);
    }

    sndElement::AttachToTop(parent);

    if (parent->GetOuterWidth() < GetOuterWidth())
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

void sndElement::AttachToBottomAndAlign(sndElement* parent)
{
    parent_ = parent;

    if (alignedVertical_ == CENTER_VERTICAL)
    {
        sndElement* nextParent = parent;

        do
        {
            nextParent->MoveOuterBottom(nextParent->GetOuterBottom() - GetOuterHeight() / 2);
            nextParent = nextParent->parent_;
        } while (nextParent != nullptr);
    }

    sndElement::AttachToBottom(parent);

    if (parent->GetOuterWidth() < GetOuterWidth())
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
//-------------------------------------

// sndButton
//-------------------------------------
sndButton::sndButton(const char* label)
    : sndElement(label)
{
}

sndButton::sndButton(const char* label, int fontSize, std::function<void()> fn, int left, int top, int right, int bottom)
    : sndElement(label, fontSize, left, top, right, bottom)
{
    SetAction(fn);
}

sndButton::sndButton(const char* label, int fontSize, std::function<void()> fn, sndWrapper* parent, sndAlign flags, int offset)
    : sndElement(label, fontSize, 0, 0, static_cast<int>(1.5 * MeasureTextEx(GetFontDefault(), label, fontSize, 0).x), static_cast<int>(2 * MeasureTextEx(GetFontDefault(), label, fontSize, 0).y))
{
    SetAction(fn);

    AlignToParent(parent, flags, offset);
}

sndButton::~sndButton() {};

void sndButton::Render()
{
    sndWrapper::Render();

    if (GuiButton(
            (Rectangle){
                static_cast<float>(GetInnerLeft()),
                static_cast<float>(GetInnerTop()),
                static_cast<float>(GetInnerWidth()),
                static_cast<float>(GetInnerHeight())},
            label_))
    {
        GetAction()();
    };
}

std::function<void()> sndButton::GetAction()
{
    return action_;
}

void sndButton::SetAction(std::function<void()> action)
{
    action_ = action;
}
//-------------------------------------

// sndSeparator
//-------------------------------------
sndSeparator::sndSeparator(const char* label, int left, int right, sndWrapper* parent, sndAlign flags, int offset)
    : sndElement(label, 0, left, 0, right, 0)
{
    AlignToParent(parent, flags, offset);
}

sndSeparator::~sndSeparator() {};

void sndSeparator::Render()
{
    sndWrapper::Render();

    GuiLine(
        (Rectangle){
            static_cast<float>(GetInnerLeft()),
            static_cast<float>(GetOuterTop()), 
            static_cast<float>(GetInnerRight() - GetInnerLeft()), 
            static_cast<float>(GetOuterTop() + (GetOuterBottom() - GetOuterTop()) / 2)},
label_);
}
//-------------------------------------

// sndVSpacer
//-------------------------------------
sndVSpacer::sndVSpacer(const char* label, int vSpace, sndWrapper* parent, sndAlign flags, int offset)
    : sndElement(label, 0, 0, 0, 0, vSpace)
{
    AlignToParent(parent, flags, offset);
}

sndVSpacer::~sndVSpacer() {};

void sndVSpacer::Render()
{
    sndWrapper::Render();
}
//-------------------------------------

// sndHSpacer
//-------------------------------------
sndHSpacer::sndHSpacer(const char* label, int hSpace, sndWrapper* parent, sndAlign flags, int offset)
    : sndElement(label, 0, 0, 0, hSpace, 0)
{
    AlignToParent(parent, flags, offset);
}

sndHSpacer::~sndHSpacer() {};

void sndHSpacer::Render()
{
    sndWrapper::Render();
}
//-------------------------------------

// sndLabel
//-------------------------------------
sndLabel::sndLabel(const char* label, int fontSize, sndWrapper* parent, sndAlign flags, int offset)
    : sndElement(label, fontSize, 0, 0, MeasureTextEx(GetFontDefault(), label, fontSize, 0).x, static_cast<int>(2 * MeasureTextEx(GetFontDefault(), label, fontSize, 0).y))
{
    AlignToParent(parent, flags, offset);
}

sndLabel::~sndLabel() {};

void sndLabel::Render()
{
    sndWrapper::Render();

    GuiLabel(
        (Rectangle){
            static_cast<float>(GetInnerLeft()),
            static_cast<float>(GetInnerTop()),
            static_cast<float>(GetInnerWidth()),
            static_cast<float>(GetInnerHeight())},
        label_);
}
//-------------------------------------

// sndText
//-------------------------------------
sndText::sndText(const char* label, int fontSize, sndWrapper* parent, sndAlign flags, int offset)
    : sndElement(label, fontSize, 0, 0, MeasureTextEx(GetFontDefault(), label, fontSize, 0).x, MeasureTextEx(GetFontDefault(), label, fontSize, 0).y)

{
    fontSize_ = fontSize;

    AlignToParent(parent, flags, offset);
}

sndText::~sndText() {};

void sndText::Render()
{
    sndWrapper::Render();

    DrawText(TextFormat(label_), GetInnerLeft(), GetInnerTop(), fontSize_, global.GetForeground());
}
//-------------------------------------

// sndCheckBox
//-------------------------------------
sndCheckBox::sndCheckBox(const char* label, int fontSize, sndWrapper* parent, sndAlign flags, int offset)
    : sndElement(label, fontSize, 0, 0, MeasureTextEx(GetFontDefault(), label, fontSize, 0).x, MeasureTextEx(GetFontDefault(), label, fontSize, 0).y)

{
    //fontSize_ = fontSize;

    AlignToParent(parent, flags, offset);
}

sndCheckBox::~sndCheckBox() {}

void sndCheckBox::Render()
{
    sndWrapper::Render();

    GuiCheckBox(
        (Rectangle){
            static_cast<float>(GetInnerLeft()),
            static_cast<float>(GetInnerTop()),
            static_cast<float>(fontSize_),
            static_cast<float>(fontSize_)},
        label_,
        &config.fadingAgents);
}
//-------------------------------------

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
