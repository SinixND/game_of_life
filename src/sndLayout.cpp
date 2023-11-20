#include "sndLayout.h"

#include "sndConfigs.h"
#include "sndGlobals.h"
#include <raylib.h>
#include <raygui.h>
#include <string>
#include <functional>
#include <iostream>
#include <memory>
#include <vector>

//#define DEBUGGING

int controlWidth = 100;
int controlGap = 20;

// sxd::Wrapper
//-------------------------------------
sxd::Wrapper::Wrapper(const char* label)
{
    label_ = label;

    SetMargin(margin_);
    SetBorder(border_);
    SetPadding(padding_);

    UpdateFrame();
}

sxd::Wrapper::Wrapper(int left, int top, int right, int bottom)
{
    ResizeOuterLeft(left);
    ResizeOuterTop(top);
    ResizeOuterRight(right);
    ResizeOuterBottom(bottom);

    UpdateFrame();
}

sxd::Wrapper::Wrapper(const char* label, int left, int top, int right, int bottom)
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
}

sxd::Wrapper::~Wrapper(){}

void sxd::Wrapper::Render()
{
    Rectangle frameRect{
        static_cast<float>(GetOuterLeft()),
        static_cast<float>(GetOuterTop()),
        static_cast<float>(GetOuterWidth()),
        static_cast<float>(GetOuterHeight())};

    DrawRectangleLinesEx(frameRect, this->GetFrameWeight(), this->GetFrameColor());

    for (auto wrapper : wrappers_)
    {
        wrapper->Render();
    }
}

void sxd::Wrapper::AddWrapper(std::shared_ptr<sxd::Wrapper> wrapper)
{
    wrappers_.push_back(wrapper);
}

void sxd::Wrapper::ClearWrappers()
{
    wrappers_.clear();
}

void sxd::Wrapper::UpdateFrame()
{
    for (auto wrapper : wrappers_)
    {
        if (strcmp(wrapper->label_.c_str(), "Margin") == 0)
        {
            wrapper->MoveOuterLeft(GetOuterLeft());
            wrapper->MoveOuterTop(GetOuterTop());
            wrapper->ResizeOuterRight(GetOuterRight());
            wrapper->ResizeOuterBottom(GetOuterBottom());
        }

        else if (strcmp(wrapper->label_.c_str(), "Border") == 0)
        {
            wrapper->MoveOuterLeft(GetOuterLeft() + margin_);
            wrapper->MoveOuterTop(GetOuterTop() + margin_);
            wrapper->ResizeOuterRight(GetOuterRight() - margin_);
            wrapper->ResizeOuterBottom(GetOuterBottom() - margin_);
        }

        else if (strcmp(wrapper->label_.c_str(), "Padding") == 0)
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

int sxd::Wrapper::GetOuterLeft() { return outerLeft_; }
void sxd::Wrapper::ResizeOuterLeft(int outerLeft)
{
    outerLeft_ = outerLeft;
    outerWidth_ = outerRight_ - outerLeft_;
    UpdateFrame();
}

void sxd::Wrapper::MoveOuterLeft(int outerLeft)
{
    outerLeft_ = outerLeft;
    outerRight_ = outerLeft_ + outerWidth_;
    UpdateFrame();
}

int sxd::Wrapper::GetOuterTop() { return outerTop_; }
void sxd::Wrapper::ResizeOuterTop(int outerTop)
{
    outerTop_ = outerTop;
    outerHeight_ = outerBottom_ - outerTop_;
    UpdateFrame();
}

void sxd::Wrapper::MoveOuterTop(int outerTop)
{
    outerTop_ = outerTop;
    outerBottom_ = outerTop_ + outerHeight_;
    UpdateFrame();
}

int sxd::Wrapper::GetOuterRight() { return outerRight_; }
void sxd::Wrapper::ResizeOuterRight(int outerRight)
{
    outerRight_ = outerRight;
    outerWidth_ = outerRight_ - outerLeft_;
    UpdateFrame();
}

void sxd::Wrapper::MoveOuterRight(int outerRight)
{
    outerRight_ = outerRight;
    outerLeft_ = outerRight_ - outerWidth_;
    UpdateFrame();
}

int sxd::Wrapper::GetOuterBottom() { return outerBottom_; }
void sxd::Wrapper::ResizeOuterBottom(int outerBottom)
{
    outerBottom_ = outerBottom;
    outerHeight_ = outerBottom_ - outerTop_;
    UpdateFrame();
}

void sxd::Wrapper::MoveOuterBottom(int outerBottom)
{
    outerBottom_ = outerBottom;
    outerTop_ = outerBottom_ - outerHeight_;
    UpdateFrame();
}

int sxd::Wrapper::GetOuterWidth() { return outerWidth_; }
int sxd::Wrapper::GetOuterHeight() { return outerHeight_; }

int sxd::Wrapper::GetMargin() { return margin_; }
void sxd::Wrapper::SetMargin(int marginWeight)
{
    margin_ = marginWeight;

    if (marginWeight == 0) return;

    auto margin = std::make_shared<sxd::Wrapper>(
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
        if (strcmp(wrappers_[i]->label_.c_str(), "Margin") == 0)
        {
            wrappers_.erase(wrappers_.begin() + i);
        }
    }

    AddWrapper(margin);

    UpdateFrame();
}

int sxd::Wrapper::GetBorder() { return border_; }
void sxd::Wrapper::SetBorder(int borderWeight)
{
    border_ = borderWeight;

    if (borderWeight == 0) return;

    auto border = std::make_shared<sxd::Wrapper>(
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
        if (strcmp(wrappers_[i]->label_.c_str(), "Border") == 0)
        {
            wrappers_.erase(wrappers_.begin() + i);
        }
    }

    AddWrapper(border);
    UpdateFrame();
}

int sxd::Wrapper::GetPadding() { return padding_; }
void sxd::Wrapper::SetPadding(int paddingWeight)
{
    padding_ = paddingWeight;

    if (paddingWeight == 0) return;

    auto padding = std::make_shared<sxd::Wrapper>(
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
        if (strcmp(wrappers_[i]->label_.c_str(), "Padding") == 0)
        {
            wrappers_.erase(wrappers_.begin() + i);
        }
    }

    AddWrapper(padding);
    UpdateFrame();
}

int sxd::Wrapper::GetFrameWeight() { return frameWeight_; }
void sxd::Wrapper::SetFrameWeight(int frameWeight) { frameWeight_ = frameWeight; }
Color sxd::Wrapper::GetFrameColor() { return frameColor_; }
void sxd::Wrapper::SetFrameColor(Color frameColor) { frameColor_ = frameColor; }

int sxd::Wrapper::GetInnerLeft() { return innerLeft_; }
int sxd::Wrapper::GetInnerTop() { return innerTop_; }
int sxd::Wrapper::GetInnerRight() { return innerRight_; }
int sxd::Wrapper::GetInnerBottom() { return innerBottom_; }
int sxd::Wrapper::GetInnerWidth() { return innerWidth_; }
int sxd::Wrapper::GetInnerHeight() { return innerHeight_; }
//-------------------------------------

// sxd::Element
//-------------------------------------
sxd::Element::Element(const char* label)
    : sxd::Wrapper {label}
{
}

sxd::Element::Element(const char* label, int fontSize, int left, int top, int right, int bottom)
    : sxd::Wrapper {label, left, top, right, bottom}
{
    fontSize_ = fontSize;
}

sxd::Element::~Element(){}

void sxd::Element::AlignToParent(sxd::Wrapper* parent, sxd::Align flags, int offset)
{
    int positionLeft = 0;
    int positionTop = 0;

    if (flags & sxd::LEFT)
    {
        positionLeft = sxd::AlignHorizontalLeft(parent, offset);
        alignedHorizontal_ = sxd::LEFT;
    }
    else if (flags & sxd::CENTER_HORIZONTAL)
    {
        positionLeft = sxd::AlignHorizontalCenter(parent, GetOuterWidth(), offset);
        alignedHorizontal_ = sxd::CENTER_HORIZONTAL;
    }
    else if (flags & sxd::RIGHT)
    {
        positionLeft = sxd::AlignHorizontalRight(parent, GetOuterWidth(), offset);
        alignedHorizontal_ = sxd::RIGHT;
    }

    if (flags & sxd::TOP)
    {
        positionTop = sxd::AlignVerticalTop(parent, offset);
        alignedVertical_ = sxd::TOP;
    }
    else if (flags & sxd::CENTER_VERTICAL)
    {
        positionTop = sxd::AlignVerticalCenter(parent, GetOuterHeight(), offset);
        alignedVertical_ = sxd::CENTER_VERTICAL;
    }
    else if (flags & sxd::BOTTOM)
    {
        positionTop = sxd::AlignVerticalBottom(parent, GetOuterHeight(), offset);
        alignedVertical_ = sxd::BOTTOM;
    }

    if (positionLeft < 0 || positionTop < 0)
    {
        throw std::invalid_argument("Check if parent size is big enough!");
    }

    MoveOuterLeft(positionLeft);
    MoveOuterTop(positionTop);
}

void sxd::Element::AttachToLeft(sxd::Element* parent)
{
    MoveOuterRight(parent->GetOuterLeft());
}

void sxd::Element::AttachToTop(sxd::Element* parent)
{
    MoveOuterBottom(parent->GetOuterTop());
}

void sxd::Element::AttachToRight(sxd::Element* parent)
{
    MoveOuterLeft(parent->GetOuterRight());
}

void sxd::Element::AttachToBottom(sxd::Element* parent)
{
    MoveOuterTop(parent->GetOuterBottom());
}

void sxd::Element::AttachToTopAndAlign(sxd::Element* parent)
{
    parent_ = parent;

    if (alignedVertical_ == sxd::CENTER_VERTICAL)
    {
        sxd::Element* nextParent = parent;

        do
        {
            nextParent->MoveOuterTop(nextParent->GetOuterTop() + GetOuterHeight() / 2);
            nextParent = nextParent->parent_;
        } while (nextParent != nullptr);
    }

    sxd::Element::AttachToTop(parent);

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

void sxd::Element::AttachToBottomAndAlign(sxd::Element* parent)
{
    parent_ = parent;

    if (alignedVertical_ == sxd::CENTER_VERTICAL)
    {
        sxd::Element* nextParent = parent;

        do
        {
            nextParent->MoveOuterBottom(nextParent->GetOuterBottom() - GetOuterHeight() / 2);
            nextParent = nextParent->parent_;
        } while (nextParent != nullptr);
    }

    sxd::Element::AttachToBottom(parent);

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

// sxd::Button
//-------------------------------------
sxd::Button::Button(const char* label)
    : sxd::Element {label}
{
}

sxd::Button::Button(const char* label, int fontSize, std::function<bool()> inputs, std::function<void()> action, int left, int top, int right, int bottom)
    : sxd::Element {label, fontSize, left, top, right, bottom}
{
    SetInputs(inputs);
    SetAction(action);
}

sxd::Button::Button(const char* label, int fontSize, std::function<bool()> inputs, std::function<void()> action, sxd::Wrapper* parent, sxd::Align flags, int offset)
    : sxd::Element {label, fontSize, 0, 0, static_cast<int>(1.5 * MeasureText(label, fontSize)), 2 * fontSize}
{
    if (label[0] == '#') 
    {
        ResizeOuterRight(3 * fontSize_);
        ResizeOuterBottom(3 * fontSize_);
    }

    SetInputs(inputs);
    SetAction(action);

    AlignToParent(parent, flags, offset);
}

sxd::Button::~Button(){}

void sxd::Button::Render()
{
    sxd::Wrapper::Render();

    if (GetInputs()() || GuiButton(
                             Rectangle{
                                 static_cast<float>(GetInnerLeft()),
                                 static_cast<float>(GetInnerTop()),
                                 static_cast<float>(GetInnerWidth()),
                                 static_cast<float>(GetInnerHeight())},
                             label_.c_str()))
    {
        GetAction()();
    };
}

std::function<bool()> sxd::Button::GetInputs()
{
    return inputs_;
}

void sxd::Button::SetInputs(std::function<bool()> inputs)
{
    inputs_ = inputs;
}

std::function<void()> sxd::Button::GetAction()
{
    return action_;
}

void sxd::Button::SetAction(std::function<void()> action)
{
    action_ = action;
}
//-------------------------------------

// sxd::Separator
//-------------------------------------
sxd::Separator::Separator(const char* label, int left, int right, sxd::Wrapper* parent, sxd::Align flags, int offset)
    : sxd::Element {label, 0, left, 0, right, 2 * GuiGetStyle(DEFAULT, TEXT_SIZE)}
{
    AlignToParent(parent, flags, offset);
}

sxd::Separator::~Separator(){}

void sxd::Separator::Render()
{
    sxd::Wrapper::Render();

    GuiLine(
        Rectangle{
            static_cast<float>(GetInnerLeft()),
            static_cast<float>(GetInnerTop()),
            static_cast<float>(GetInnerWidth()),
            static_cast<float>(GetInnerHeight())},
        label_.c_str());
}
//-------------------------------------

// sxd::Spacer
//-------------------------------------
sxd::Spacer::Spacer(const char* label, int vSpace, int hSpace, sxd::Wrapper* parent, sxd::Align flags, int offset)
    : sxd::Element {label, 0, 0, 0, hSpace, vSpace}
{
    AlignToParent(parent, flags, offset);
}

sxd::Spacer::~Spacer(){}

void sxd::Spacer::Render()
{
    sxd::Wrapper::Render();
}
//-------------------------------------

// sxd::Label
//-------------------------------------
sxd::Label::Label(const char* label, int fontSize, sxd::Wrapper* parent, sxd::Align flags, int offset)
    : sxd::Element {label, fontSize, 0, 0, static_cast<int>(1.5 * MeasureText(label, fontSize)), 2 * fontSize}
{
    AlignToParent(parent, flags, offset);
}

sxd::Label::~Label(){}

void sxd::Label::Render()
{
    sxd::Wrapper::Render();

    GuiLabel(
        Rectangle{
            static_cast<float>(GetInnerLeft()),
            static_cast<float>(GetInnerTop()),
            static_cast<float>(GetInnerWidth()),
            static_cast<float>(GetInnerHeight())},
        label_.c_str());
}
//-------------------------------------

// sxd::Text
//-------------------------------------
sxd::Text::Text(const char* label, int fontSize, sxd::Wrapper* parent, sxd::Align flags, int offset)
    : sxd::Element {label, fontSize, 0, 0, MeasureText(label, fontSize), fontSize}

{
    fontSize_ = fontSize;

    AlignToParent(parent, flags, offset);
}

sxd::Text::~Text(){}

void sxd::Text::Render()
{
    sxd::Wrapper::Render();

    DrawText(TextFormat(label_.c_str()), GetInnerLeft(), GetInnerTop(), fontSize_, global.GetForeground());
}
//-------------------------------------

// sxd::CheckBox
//-------------------------------------
sxd::CheckBox::CheckBox(const char* label, int fontSize, bool* value, sxd::Wrapper* parent, sxd::Align flags, int offset)
    : sxd::Element {label, fontSize, 0, 0, controlWidth + controlGap + MeasureText(label, fontSize), (2 * fontSize)}

{
    fontSize_ = fontSize;
    value_ = value;

    AlignToParent(parent, flags, offset);
}

sxd::CheckBox::~CheckBox() {}

void sxd::CheckBox::Render()
{
    sxd::Wrapper::Render();

    GuiCheckBox(
        Rectangle{
            static_cast<float>(GetInnerLeft() + ((controlWidth - fontSize_) / 2)),
            static_cast<float>(GetInnerTop() + ((GetInnerHeight() - fontSize_) / 2)),
            static_cast<float>(fontSize_),
            static_cast<float>(fontSize_)},
        NULL,
        value_);

    GuiLabel(
        Rectangle{
            static_cast<float>(GetInnerLeft() + controlWidth + controlGap),
            static_cast<float>(GetInnerTop()),
            static_cast<float>(GetInnerLeft() + MeasureText(label_.c_str(), fontSize_)),
            static_cast<float>(GetInnerHeight())},
        label_.c_str());
}
//-------------------------------------

// sxd::Spinner
//-------------------------------------
sxd::Spinner::Spinner(const char* label, int fontSize, int* value, int minValue, int maxValue, bool editMode, sxd::Wrapper* parent, sxd::Align flags, int offset)
    : sxd::Element {label, fontSize, 0, 0, controlWidth + controlGap + MeasureText(label, fontSize), 2 * fontSize}
{
    value_ = value;
    minValue_ = minValue;
    maxValue_ = maxValue;
    editMode_ = editMode;

    AlignToParent(parent, flags, offset);
}

sxd::Spinner::~Spinner(){}

void sxd::Spinner::Render()
{
    sxd::Wrapper::Render();

    GuiSpinner(
        Rectangle{
            static_cast<float>(GetInnerLeft()),
            static_cast<float>(GetInnerTop()),
            static_cast<float>(controlWidth),
            static_cast<float>(GetInnerHeight())},
        NULL, 
        value_, 
        minValue_, 
        maxValue_, 
        editMode_);

    GuiLabel(
        Rectangle{
            static_cast<float>(GetInnerLeft() + controlWidth + controlGap),
            static_cast<float>(GetInnerTop()),
            static_cast<float>(GetInnerWidth()),
            static_cast<float>(GetInnerHeight())},
        label_.c_str());
}
//-------------------------------------

int sxd::AlignHorizontalLeft(sxd::Wrapper* parent, int offset)
{
    return parent->GetInnerLeft() + offset;
}

int sxd::AlignHorizontalCenter(sxd::Wrapper* parent, int objectWidth, int offset)
{
    return parent->GetInnerLeft() + ((parent->GetInnerWidth() - objectWidth) / 2) + offset;
}

int sxd::AlignHorizontalRight(sxd::Wrapper* parent, int objectWidth, int offset)
{
    return parent->GetInnerLeft() + parent->GetInnerWidth() - objectWidth - offset;
}

int sxd::AlignVerticalTop(sxd::Wrapper* parent, int offset)
{
    return parent->GetInnerTop() + offset;
}

int sxd::AlignVerticalCenter(sxd::Wrapper* parent, int objectHeight, int offset)
{
    return parent->GetInnerTop() + ((parent->GetInnerHeight() - objectHeight) / 2) + offset;
}

int sxd::AlignVerticalBottom(sxd::Wrapper* parent, int objectHeight, int offset)
{
    return parent->GetInnerTop() + (parent->GetInnerHeight() - objectHeight - offset);
}
