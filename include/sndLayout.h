// SNDLayout - A header only library to enable responsive layouts based on raylib and raygui

#ifndef SNDLAYOUT_H
#define SNDLAYOUT_H

// sndLayout.h
#include <vector>

#include <raylib.h>

/* LAYOUT BOX STRUCTURE

margin    m m m m m m m m m m
border    m B B B B B B B B m
padding   m B p p p p p p B m
content   m B p"Content"p B m
padding   m B p p p p p p B m
border    m B B B B B B B B m
margin    m m m m m m m m m m

*/

class Wrapper
{
public:
    template <typename T1, typename T2, typename T3, typename T4>
    Wrapper(T1&& left, T2&& top, T3&& right, T4&& bottom)
        : margin_left_(left)
        , margin_top_(top)
        , margin_right_(right)
        , margin_bottom_(bottom)
        , border_left_(left)
        , border_top_(top)
        , border_right_(right)
        , border_bottom_(bottom)
        , padding_left_(left)
        , padding_top_(top)
        , padding_right_(right)
        , padding_bottom_(bottom)
        , content_left_(left)
        , content_top_(top)
        , content_right_(right)
        , content_bottom_(bottom)
    {
        UpdateBorder();
    };

    void Render()
    {
        DrawRectangleLinesEx((Rectangle){GetMarginLeft(), GetMarginTop(), GetMarginRight(), GetMarginBottom()}, margin_, BLUE);
        DrawRectangleLinesEx((Rectangle){border_left_, border_top_, border_right_, border_bottom_}, border_, GRAY);
        DrawRectangleLinesEx((Rectangle){padding_left_, padding_top_, padding_right_, padding_bottom_}, padding_, GREEN);
    };

    float& GetMarginLeft() { return margin_left_; };
    float& GetMarginTop() { return margin_top_; };
    float& GetMarginRight() { return margin_right_; };
    float& GetMarginBottom() { return margin_bottom_; };
    float& GetMarginWidth() { return margin_width_; };
    float& GetMarginHeight() { return margin_height_; };
    float GetMargin() { return margin_; };
    void SetMargin(float& margin)
    {
        margin_ = margin;

        UpdateBorder();
    };

    float& GetBorderLeft() { return border_left_; };
    float& GetBorderTop() { return border_top_; };
    float& GetBorderRight() { return border_right_; };
    float& GetBorderBottom() { return border_bottom_; };
    float& GetBorderWidth() { return border_width_; };
    float& GetBorderHeight() { return border_height_; };
    float GetBorder() { return border_; };
    void SetBorder(float& border)
    {
        border_ = border;

        UpdatePadding();
    };

    float& GetPaddingLeft() { return padding_left_; };
    float& GetPaddingTop() { return padding_top_; };
    float& GetPaddingRight() { return padding_right_; };
    float& GetPaddingBottom() { return padding_bottom_; };
    float& GetPaddingWidth() { return padding_width_; };
    float& GetPaddingHeight() { return padding_height_; };
    float GetPadding() { return padding_; };
    void SetPadding(float& padding)
    {
        padding_ = padding;

        UpdateContent();
    };

    float GetFrameWeight() { return frameWeight_; };

    float& GetContentLeft() { return content_left_; };
    float& GetContentTop() { return content_top_; };
    float& GetContentRight() { return content_right_; };
    float& GetContentBottom() { return content_bottom_; };
    float& GetContentWidth() { return content_width_; };
    float& GetContentHeight() { return content_height_; };

protected:
    float margin_ = 1;
    float border_ = 1;
    float padding_ = 1;
    float frameWeight_ = margin_ + border_ + padding_;

    float margin_left_;
    float margin_top_;
    float margin_right_;
    float margin_bottom_;
    float margin_width_ = margin_right_ - margin_left_;
    float margin_height_ = margin_bottom_ - margin_top_;

    float border_left_;
    float border_top_;
    float border_right_;
    float border_bottom_;
    float border_width_ = border_right_ - border_left_;
    float border_height_ = border_bottom_ - border_top_;

    float padding_left_;
    float padding_top_;
    float padding_right_;
    float padding_bottom_;
    float padding_width_ = padding_right_ - padding_left_;
    float padding_height_ = padding_bottom_ - padding_top_;

    float content_left_;
    float content_top_;
    float content_right_;
    float content_bottom_;
    float content_width_ = content_right_ - content_left_;
    float content_height_ = content_bottom_ - content_top_;

    void UpdateBorder()
    {
        border_left_ = GetMarginLeft() + margin_;
        border_top_ = GetMarginTop() + margin_;
        border_right_ = GetMarginRight() - 2 * margin_;
        border_bottom_ = GetMarginBottom() - 2 * margin_;
        border_width_ = border_right_ - border_left_;
        border_height_ = border_bottom_ - border_top_;

        UpdatePadding();
    };

    void UpdatePadding()
    {
        padding_left_ = GetMarginLeft() + margin_ + border_;
        padding_top_ = GetMarginTop() + margin_ + border_;
        padding_right_ = GetMarginRight() - 2 * (margin_ + border_);
        padding_bottom_ = GetMarginBottom() - 2 * (margin_ + border_);
        padding_width_ = padding_right_ - padding_left_;
        padding_height_ = padding_bottom_ - padding_top_;

        UpdateContent();
    };

    void UpdateContent()
    {
        content_left_ = GetMarginLeft() + margin_ + border_ + padding_;
        content_top_ = GetMarginTop() + margin_ + border_ + padding_;
        content_right_ = GetMarginRight() - 2 * (margin_ + border_ + padding_);
        content_bottom_ = GetMarginBottom() - 2 * (margin_ + border_ + padding_);
        content_width_ = content_right_ - content_left_;
        content_height_ = content_bottom_ - content_top_;

        UpdateFrameWeight();
    };

    void UpdateFrameWeight()
    {
        frameWeight_ =  margin_ + border_ + padding_;
    };

};
#endif
