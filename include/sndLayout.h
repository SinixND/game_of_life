// SNDLayout - A header only library to enable responsive layouts based on raylib and raygui

// sndLayout.h

#ifndef SNDLAYOUT_H
#define SNDLAYOUT_H

#include <raylib.h>
#include <iostream>

/* LAYOUT BOX STRUCTURE

margin    m m m m m m m m m m  
border    m B B B B B B B B m  
padding   m B p p p p p p B m  
content   m B p"Content"p B m  
padding   m B p p p p p p B m  
border    m B B B B B B B B m  
margin    m m m m m m m m m m  

*/

class Box
{
public:
    template <typename T>
    Box(T&& x, T&& y, T&& width, T&& height)
    {
        x_ = x;
        y_ = y;
        width_ = width;
        height_ = height;

        border_x_ = x;
        border_y_ = y;
        border_width_ = width;
        border_height_ = height;
    };

    float x_;
    float y_;
    float width_;
    float height_;

    float GetMargin() { return margin_; };
    void SetMargin(float margin)
    {
        margin_ = margin;

        UpdateBorder();
        UpdateContent();
    };

    float GetBorder() { return border_; };
    void SetBorder(float border)
    {
        border_ = border;

        UpdateBorder();
        UpdateContent();
    };

    float GetPadding() { return padding_; };
    void SetPadding(float padding)
    {
        padding_ = padding;

        UpdateBorder();
        UpdateContent();
    };

    void Render()
    {
        DrawRectangleLinesEx((Rectangle){GetMarginX(), GetMarginY(), GetMarginWidth(), GetMarginHeight()}, 1, BLUE);
        DrawRectangleLinesEx((Rectangle){border_x_, border_y_, border_width_, border_height_}, 1, GRAY);
    };

protected:
    float margin_ = 0;

    float border_x_;
    float border_y_;
    float border_width_;
    float border_height_;

    float border_ = 0;
    float padding_ = 0;

    virtual float& GetMarginX() = 0;
    virtual float& GetMarginY() = 0;
    virtual float& GetMarginWidth() = 0;
    virtual float& GetMarginHeight() = 0;

    void UpdateBorder()
    {
        border_x_ = GetMarginX() + margin_;
        border_y_ = GetMarginY() + margin_;
        border_width_ = GetMarginWidth() - 2 * margin_;
        border_height_ = GetMarginHeight() - 2 * margin_;
    };

    void UpdateContent()
    {
        x_ = GetMarginX() + margin_ + border_ + padding_;
        y_ = GetMarginY() + margin_ + border_ + padding_;
        width_ = GetMarginWidth() - 2 * (margin_ + border_ + padding_);
        height_ = GetMarginHeight() - 2 * (margin_ + border_ + padding_);
    };
};

class WrapperStatic : public Box
{
public:
    WrapperStatic(float x, float y, float width, float height) : Box(x, y, width, height)
        , margin_x_(x)
        , margin_y_(y)
        , margin_width_(width)
        , margin_height_(height)
    {
    };

protected:
    float margin_x_;
    float margin_y_;
    float margin_width_;
    float margin_height_;

    float& GetMarginX() override {return margin_x_;};
    float& GetMarginY() override {return margin_y_;};
    float& GetMarginWidth() override {return margin_width_;};
    float& GetMarginHeight() override {return margin_height_;};
};

class WrapperDynamic : public Box
{
public:
    WrapperDynamic(float& x, float& y, float& width, float& height) : Box(x, y, width, height)
        , margin_x_(x)
        , margin_y_(y)
        , margin_width_(width)
        , margin_height_(height)
    {
    };

protected:
    float& margin_x_;
    float& margin_y_;
    float& margin_width_;
    float& margin_height_;

    float& GetMarginX() override {return margin_x_;};
    float& GetMarginY() override {return margin_y_;};
    float& GetMarginWidth() override {return margin_width_;};
    float& GetMarginHeight() override {return margin_height_;};
};
#endif
