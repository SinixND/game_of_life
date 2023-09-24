#include "sndLayout.h"

#define DEBUG

#include <vector>
#include <raylib.h>
#include <raygui.h>

#include "sndGlobals.h"

/* LAYOUT BOX STRUCTURE

margin    m m m m m m m m m m m m m m m m
          m m m m m m m m m m m m m m m m
border    m m B B B B B B B B B B B B m m
          m m B B B B B B B B B B B B m m
padding   m m B B p p p p p p p p B B m m
          m m B B p p p p p p p p B B m m
content   m m B B p p CONTENT p p B B m m
          m m B B p p CONTENT p p B B m m
content   m m B B p p CONTENT p p B B m m
          m m B B p p p p p p p p B B m m
padding   m m B B p p p p p p p p B B m m
          m m B B B B B B B B B B B B m m
border    m m B B B B B B B B B B B B m m
          m m m m m m m m m m m m m m m m
margin    m m m m m m m m m m m m m m m m

*/

void Wrapper::AddButton(const char* text, float textSize)
{
    int textWidth = MeasureText(text, textSize);
    if ( GuiButton(
            (Rectangle){
                static_cast<float>(AlignHorizontalRight(this, textWidth, 0)),
                static_cast<float>(AlignVerticalCenter(this, global.guiButtonBaseHeight, 0)),
                static_cast<float>(textWidth),
                static_cast<float>(global.guiButtonBaseHeight)},
            text) )
    {
        global.ToggleDarkMode();
    };
};

void Wrapper::Render()
{
    Rectangle marginRect{
        static_cast<float>(GetMarginLeft()), 
        static_cast<float>(GetMarginTop()), 
        static_cast<float>(GetMarginWidth()), 
        static_cast<float>(GetMarginHeight())};
    DrawRectangleLinesEx(marginRect, GetMargin(), margin);

    Rectangle borderRect{
        static_cast<float>(GetBorderLeft()), 
        static_cast<float>(GetBorderTop()), 
        static_cast<float>(GetBorderWidth()), 
        static_cast<float>(GetBorderHeight())};
    DrawRectangleLinesEx(borderRect, GetBorder(), border);

    Rectangle paddingRect{
        static_cast<float>(GetPaddingLeft()), 
        static_cast<float>(GetPaddingTop()), 
        static_cast<float>(GetPaddingWidth()), 
        static_cast<float>(GetPaddingHeight())};
    DrawRectangleLinesEx(paddingRect, GetPadding(), padding);

    if (wrapper_.size() == 0)
    {
        return;
    }

    for (auto wrapper : wrapper_)
    {
        wrapper.Render();
    }
};

void Wrapper::AddWrapper(Wrapper wrapper)
{
    wrapper_.push_back(wrapper);
};

int& Wrapper::GetMarginLeft() { return margin_left_; };
int& Wrapper::GetMarginTop() { return margin_top_; };
int& Wrapper::GetMarginRight() { return margin_right_; };
int& Wrapper::GetMarginBottom() { return margin_bottom_; };
int& Wrapper::GetMarginWidth() { return margin_width_; };
int& Wrapper::GetMarginHeight() { return margin_height_; };
int Wrapper::GetMargin() { return margin_; };
void Wrapper::SetMargin(int& margin)
{
    margin_ = margin;

    UpdateBorder();
};

int& Wrapper::GetBorderLeft() { return border_left_; };
int& Wrapper::GetBorderTop() { return border_top_; };
int& Wrapper::GetBorderRight() { return border_right_; };
int& Wrapper::GetBorderBottom() { return border_bottom_; };
int& Wrapper::GetBorderWidth() { return border_width_; };
int& Wrapper::GetBorderHeight() { return border_height_; };
int Wrapper::GetBorder() { return border_; };
void Wrapper::SetBorder(int& border)
{
    border_ = border;

    UpdatePadding();
};

int& Wrapper::GetPaddingLeft() { return padding_left_; };
int& Wrapper::GetPaddingTop() { return padding_top_; };
int& Wrapper::GetPaddingRight() { return padding_right_; };
int& Wrapper::GetPaddingBottom() { return padding_bottom_; };
int& Wrapper::GetPaddingWidth() { return padding_width_; };
int& Wrapper::GetPaddingHeight() { return padding_height_; };
int Wrapper::GetPadding() { return padding_; };
void Wrapper::SetPadding(int& padding)
{
    padding_ = padding;

    UpdateContent();
};

int Wrapper::GetFrameWeight() { return frameWeight_; };

int& Wrapper::GetContentLeft() { return content_left_; };
int& Wrapper::GetContentTop() { return content_top_; };
int& Wrapper::GetContentRight() { return content_right_; };
int& Wrapper::GetContentBottom() { return content_bottom_; };
int& Wrapper::GetContentWidth() { return content_width_; };
int& Wrapper::GetContentHeight() { return content_height_; };

int Wrapper::AlignHorizontalLeft(Wrapper* parent, int offset)
{
    return parent->GetContentLeft() + offset;
};

int Wrapper::AlignHorizontalCenter(Wrapper* parent, int objectWidth, int offset)
{
    return parent->GetContentLeft() + ((parent->GetContentWidth() - objectWidth) / 2) + offset;
};

int Wrapper::AlignHorizontalRight(Wrapper* parent, int objectWidth, int offset)
{
    return parent->GetContentLeft() + parent->GetContentWidth() - objectWidth - offset;
};

int Wrapper::AlignVerticalTop(Wrapper* parent, int offset)
{
    return parent->GetContentTop() + offset;
};

int Wrapper::AlignVerticalCenter(Wrapper* parent, int objectHeight, int offset)
{
    return parent->GetContentTop() + ((parent->GetContentHeight() - objectHeight) / 2) + offset;
};

int Wrapper::AlignVerticalBottom(Wrapper* parent, int objectHeight, int offset)
{
    return parent->GetContentTop() + (parent->GetContentHeight() - objectHeight - offset);
};

void Wrapper::UpdateBorder()
{
    border_left_ = GetMarginLeft() + margin_;
    border_top_ = GetMarginTop() + margin_;
    border_right_ = GetMarginRight() - margin_;
    border_bottom_ = GetMarginBottom() - margin_;
    border_width_ = border_right_ - border_left_;
    border_height_ = border_bottom_ - border_top_;

    UpdatePadding();
};

void Wrapper::UpdatePadding()
{
    padding_left_ = GetMarginLeft() + margin_ + border_;
    padding_top_ = GetMarginTop() + margin_ + border_;
    padding_right_ = GetMarginRight() - (margin_ + border_);
    padding_bottom_ = GetMarginBottom() - (margin_ + border_);
    padding_width_ = padding_right_ - padding_left_;
    padding_height_ = padding_bottom_ - padding_top_;

    UpdateContent();
};

void Wrapper::UpdateContent()
{
    content_left_ = GetMarginLeft() + margin_ + border_ + padding_;
    content_top_ = GetMarginTop() + margin_ + border_ + padding_;
    content_right_ = GetMarginRight() - (margin_ + border_ + padding_);
    content_bottom_ = GetMarginBottom() - (margin_ + border_ + padding_);
    content_width_ = content_right_ - content_left_;
    content_height_ = content_bottom_ - content_top_;

    UpdateFrameWeight();
};

void Wrapper::UpdateFrameWeight()
{
    frameWeight_ = margin_ + border_ + padding_;
};
