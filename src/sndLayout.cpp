#include "sndLayout.h"

#define DEBUG

#include <raygui.h>
#include <raylib.h>
#include <vector>

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

void sndWrapper::Append(sndElement& element, sndAlign flags, int offset)
{
    int positionLeft = 0;
    int positionTop = 0;

    if (flags & LEFT)
    {
        positionLeft = AlignHorizontalLeft(this, offset);
    }
    else if (flags & CENTER_HORIZONTAL)
    {
        positionLeft = AlignHorizontalCenter(this, element.GetWidth(), offset);
    }
    else if (flags & RIGHT)
    {
        positionLeft = AlignHorizontalRight(this, element.GetWidth(), offset);
    }

    if (flags & TOP)
    {
        positionTop = AlignVerticalTop(this, offset);
    }
    else if (flags & CENTER_VERTICAL)
    {
        positionTop = AlignVerticalCenter(this, element.GetHeight(), offset);
    }
    else if (flags & BOTTOM)
    {
        positionTop = AlignVerticalBottom(this, element.GetHeight(), offset);
    };

    element.SetLeft(positionLeft);
    element.SetTop(positionTop);
};

void sndWrapper::Render()
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

void sndWrapper::AddWrapper(sndWrapper wrapper)
{
    wrapper_.push_back(wrapper);
};

int& sndWrapper::GetMarginLeft() { return margin_left_; };
int& sndWrapper::GetMarginTop() { return margin_top_; };
int& sndWrapper::GetMarginRight() { return margin_right_; };
int& sndWrapper::GetMarginBottom() { return margin_bottom_; };
int& sndWrapper::GetMarginWidth() { return margin_width_; };
int& sndWrapper::GetMarginHeight() { return margin_height_; };
int sndWrapper::GetMargin() { return margin_; };
void sndWrapper::SetMargin(int margin)
{
    margin_ = margin;

    UpdateBorder();
};

int& sndWrapper::GetBorderLeft() { return border_left_; };
int& sndWrapper::GetBorderTop() { return border_top_; };
int& sndWrapper::GetBorderRight() { return border_right_; };
int& sndWrapper::GetBorderBottom() { return border_bottom_; };
int& sndWrapper::GetBorderWidth() { return border_width_; };
int& sndWrapper::GetBorderHeight() { return border_height_; };
int sndWrapper::GetBorder() { return border_; };
void sndWrapper::SetBorder(int border)
{
    border_ = border;

    UpdatePadding();
};

int& sndWrapper::GetPaddingLeft() { return padding_left_; };
int& sndWrapper::GetPaddingTop() { return padding_top_; };
int& sndWrapper::GetPaddingRight() { return padding_right_; };
int& sndWrapper::GetPaddingBottom() { return padding_bottom_; };
int& sndWrapper::GetPaddingWidth() { return padding_width_; };
int& sndWrapper::GetPaddingHeight() { return padding_height_; };
int sndWrapper::GetPadding() { return padding_; };
void sndWrapper::SetPadding(int padding)
{
    padding_ = padding;

    UpdateContent();
};

int sndWrapper::GetFrameWeight() { return frameWeight_; };

int& sndWrapper::GetContentLeft() { return content_left_; };
int& sndWrapper::GetContentTop() { return content_top_; };
int& sndWrapper::GetContentRight() { return content_right_; };
int& sndWrapper::GetContentBottom() { return content_bottom_; };
int& sndWrapper::GetContentWidth() { return content_width_; };
int& sndWrapper::GetContentHeight() { return content_height_; };

void sndWrapper::UpdateBorder()
{
    border_left_ = GetMarginLeft() + margin_;
    border_top_ = GetMarginTop() + margin_;
    border_right_ = GetMarginRight() - margin_;
    border_bottom_ = GetMarginBottom() - margin_;
    border_width_ = border_right_ - border_left_;
    border_height_ = border_bottom_ - border_top_;

    UpdatePadding();
};

void sndWrapper::UpdatePadding()
{
    padding_left_ = GetMarginLeft() + margin_ + border_;
    padding_top_ = GetMarginTop() + margin_ + border_;
    padding_right_ = GetMarginRight() - (margin_ + border_);
    padding_bottom_ = GetMarginBottom() - (margin_ + border_);
    padding_width_ = padding_right_ - padding_left_;
    padding_height_ = padding_bottom_ - padding_top_;

    UpdateContent();
};

void sndWrapper::UpdateContent()
{
    content_left_ = GetMarginLeft() + margin_ + border_ + padding_;
    content_top_ = GetMarginTop() + margin_ + border_ + padding_;
    content_right_ = GetMarginRight() - (margin_ + border_ + padding_);
    content_bottom_ = GetMarginBottom() - (margin_ + border_ + padding_);
    content_width_ = content_right_ - content_left_;
    content_height_ = content_bottom_ - content_top_;

    UpdateFrameWeight();
};

void sndWrapper::UpdateFrameWeight()
{
    frameWeight_ = margin_ + border_ + padding_;
};

int sndElement::GetLeft() { return left_; }
void sndElement::SetLeft(int left)
{
    left_ = left;
}

int sndElement::GetTop() { return top_; }
void sndElement::SetTop(int top)
{
    top_ = top;
}

int sndElement::GetRight() { return right_; }
void sndElement::SetRight(int right)
{
    right_ = right;
    width_ = right_ - left_;
}

int sndElement::GetBottom() { return bottom_; }
void sndElement::SetBottom(int bottom)
{
    bottom_ = bottom;
    height_ = bottom_ - top_;
}

int sndElement::GetWidth() { return width_; }
void sndElement::SetWidth(int width)
{
    width_ = width;
    right_ = left_ + width_;
}

int sndElement::GetHeight() { return height_; }
void sndElement::SetHeight(int height)
{
    height_ = height;
    bottom_ = top_ + height_;
}

sndButton::sndButton(const char* text, int fontSize)
{

};

int AlignHorizontalLeft(sndWrapper* parent, int offset)
{
    return parent->GetContentLeft() + offset;
};

int AlignHorizontalCenter(sndWrapper* parent, int objectWidth, int offset)
{
    return parent->GetContentLeft() + ((parent->GetContentWidth() - objectWidth) / 2) + offset;
};

int AlignHorizontalRight(sndWrapper* parent, int objectWidth, int offset)
{
    return parent->GetContentLeft() + parent->GetContentWidth() - objectWidth - offset;
};

int AlignVerticalTop(sndWrapper* parent, int offset)
{
    return parent->GetContentTop() + offset;
};

int AlignVerticalCenter(sndWrapper* parent, int objectHeight, int offset)
{
    return parent->GetContentTop() + ((parent->GetContentHeight() - objectHeight) / 2) + offset;
};

int AlignVerticalBottom(sndWrapper* parent, int objectHeight, int offset)
{
    return parent->GetContentTop() + (parent->GetContentHeight() - objectHeight - offset);
};