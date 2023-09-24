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
    template <typename T>
    Wrapper(T&& x, T&& y, T&& width, T&& height)
        : margin_x_(x)
        , margin_y_(y)
        , margin_width_(width)
        , margin_height_(height)
    {
        UpdateBorder();
    };

    void Render()
    {
        DrawRectangleLinesEx((Rectangle){GetMarginX(), GetMarginY(), GetMarginWidth(), GetMarginHeight()}, margin_, BLUE);
        DrawRectangleLinesEx((Rectangle){border_x_, border_y_, border_width_, border_height_}, border_, GRAY);
        DrawRectangleLinesEx((Rectangle){padding_x_, padding_y_, padding_width_, padding_height_}, padding_, GREEN);
    };

    float& GetMarginX() { return margin_x_; };
    float& GetMarginY() { return margin_y_; };
    float& GetMarginWidth() { return margin_width_; };
    float& GetMarginHeight() { return margin_height_; };
    float GetMargin() { return margin_; };
    void SetMargin(float& margin)
    {
        margin_ = margin;

        UpdateBorder();
    };

    float& GetBorderX() { return border_x_; };
    float& GetBorderY() { return border_y_; };
    float& GetBorderWidth() { return border_width_; };
    float& GetBorderHeight() { return border_height_; };
    float GetBorder() { return border_; };
    void SetBorder(float& border)
    {
        border_ = border;

        UpdatePadding();
    };

    float& GetPaddingX() { return padding_x_; };
    float& GetPaddingY() { return padding_y_; };
    float& GetPaddingWidth() { return padding_width_; };
    float& GetPaddingHeight() { return padding_height_; };
    float GetPadding() { return padding_; };
    void SetPadding(float& padding)
    {
        padding_ = padding;

        UpdateContent();
    };

    float& GetContentX() { return content_x_; };
    float& GetContentY() { return content_y_; };
    float& GetContentWidth() { return content_width_; };
    float& GetContentHeight() { return content_height_; };

protected:
    float margin_ = 2;
    float border_ = 5;
    float padding_ = 2;

    float margin_x_;
    float margin_y_;
    float margin_width_;
    float margin_height_;

    float border_x_;
    float border_y_;
    float border_width_;
    float border_height_;

    float padding_x_;
    float padding_y_;
    float padding_width_;
    float padding_height_;

    float content_x_;
    float content_y_;
    float content_width_;
    float content_height_;

    void UpdateBorder()
    {
        border_x_ = GetMarginX() + margin_;
        border_y_ = GetMarginY() + margin_;
        border_width_ = GetMarginWidth() - 2 * margin_;
        border_height_ = GetMarginHeight() - 2 * margin_;

        UpdatePadding();
    };

    void UpdatePadding()
    {
        padding_x_ = GetMarginX() + margin_ + border_;
        padding_y_ = GetMarginY() + margin_ + border_;
        padding_width_ = GetMarginWidth() - 2 * (margin_ + border_);
        padding_height_ = GetMarginHeight() - 2 * (margin_ + border_);

        UpdateContent();
    };

    void UpdateContent()
    {
        content_x_ = GetMarginX() + margin_ + border_ + padding_;
        content_y_ = GetMarginY() + margin_ + border_ + padding_;
        content_width_ = GetMarginWidth() - 2 * (margin_ + border_ + padding_);
        content_height_ = GetMarginHeight() - 2 * (margin_ + border_ + padding_);
    };
};
#endif
