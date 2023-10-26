#include "sndLayout.h"

#define DEBUGGING

#include "sndGlobals.h"
#include <functional>
#include <raygui.h>
#include <raylib.h>
#include <vector>
#include <memory>

sndWrapper::sndWrapper()
{
    Update();
};

sndWrapper::sndWrapper(char* name)
{
    name_ = name;
    Update();
};

sndWrapper::sndWrapper(char* name, int left, int top, int right, int bottom)
{
    name_ = name;
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

void sndWrapper::Append(std::shared_ptr<sndWrapper> element, sndAlign flags, int offset)
{
    int positionLeft = 0;
    int positionTop = 0;

    if (flags & LEFT)
    {
        positionLeft = AlignHorizontalLeft(this, offset);
    }
    else if (flags & CENTER_HORIZONTAL)
    {
        positionLeft = AlignHorizontalCenter(this, element->GetOuterWidth(), offset);
    }
    else if (flags & RIGHT)
    {
        positionLeft = AlignHorizontalRight(this, element->GetOuterWidth(), offset);
    }

    if (flags & TOP)
    {
        positionTop = AlignVerticalTop(this, offset);
    }
    else if (flags & CENTER_VERTICAL)
    {
        positionTop = AlignVerticalCenter(this, element->GetOuterHeight(), offset);
    }
    else if (flags & BOTTOM)
    {
        positionTop = AlignVerticalBottom(this, element->GetOuterHeight(), offset);
    };

    element->MoveOuterLeft(positionLeft);
    element->MoveOuterTop(positionTop);

    //this->AddWrapper(element);
    wrappers_.push_back(element);
}

void sndWrapper::AddButton(const char* text, std::function<void()> fn, sndAlign flags, int offset)
{
    std::shared_ptr<sndButton> button(new sndButton("button", 0, 0, MeasureText(text, global.textSizeDefault), global.textSizeDefault));

    button->SetText(text);
    button->SetFunction(fn);

    Append(button, flags, offset);
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

sndButton::sndButton()
    : sndWrapper(){};

sndButton::sndButton(char* name)
    : sndWrapper(name)
{
    name_ = name;
};

sndButton::sndButton(char* name, int left, int top, int right, int bottom)
    : sndWrapper(name, left, top, right, bottom)
{
    name_ = name;
};

void sndButton::Render()
{
    sndWrapper::Render();

    if (GuiButton(
            (Rectangle){
                static_cast<float>(GetOuterLeft()),
                static_cast<float>(GetOuterTop()),
                static_cast<float>(GetOuterWidth()),
                static_cast<float>(GetOuterHeight())},
            GetText()))
    {
        GetFunction()();
    };
}

// SETTERS AND GETTERS
//-------------------------------------

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

    std::shared_ptr<sndWrapper> margin(new sndWrapper(
        "margin",
        this->GetOuterLeft(),
        this->GetOuterTop(),
        this->GetOuterRight(),
        this->GetOuterBottom()));
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

    std::shared_ptr<sndWrapper> border(new sndWrapper(
        "border",
        this->GetOuterLeft() + this->GetMargin(),
        this->GetOuterTop() + this->GetMargin(),
        this->GetOuterRight() - this->GetMargin(),
        this->GetOuterBottom() - this->GetMargin()));
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

    std::shared_ptr<sndWrapper> padding(new sndWrapper(
        "padding",
        this->GetOuterLeft() + this->GetMargin() + this->GetBorder(),
        this->GetOuterTop() + this->GetMargin() + this->GetBorder(),
        this->GetOuterRight() - this->GetMargin() - this->GetBorder(),
        this->GetOuterBottom() - this->GetMargin() - this->GetBorder()));
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

void sndButton::SetText(const char* text)
{
    text_ = text;
}

const char* sndButton::GetText()
{
    return text_;
}

void sndButton::SetFunction(std::function<void()> fn)
{
    fn_ = fn;
}

std::function<void()> sndButton::GetFunction()
{
    return fn_;
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
