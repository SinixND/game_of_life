// SNDLayout - A header only library to enable responsive layouts based on raylib and raygui

// sndLayout.h

#ifndef SNDLAYOUT_H
#define SNDLAYOUT_H

#include <raylib.h>
#include <iostream>

/* LAYOUT BOX STRUCTURE

margin    m m m m m m m m m m  
border    m b b b b b b b b m  
padding   m b p p p p p p b m  
content   m b p"Content"p b m  
padding   m b p p p p p p b m  
border    m b b b b b b b b m  
margin    m m m m m m m m m m  

*/

class Box
{
public:
//protected:
    float margin_ = 0;

    float border_x_;
    float border_y_;
    float border_width_;
    float border_height_;

    float border_ = 0;
    float padding_ = 0;

    float x_;
    float y_;
    float width_;
    float height_;
};

class WrapperStatic : public Box
{
public:
    WrapperStatic(float x, float y, float width, float height)
        : margin_x_(x)
        , margin_y_(y)
        , margin_width_(width)
        , margin_height_(height)
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
        DrawRectangleLinesEx((Rectangle){margin_x_, margin_y_, margin_width_, margin_height_}, 1, BLUE);
        DrawRectangleLinesEx((Rectangle){border_x_, border_y_, border_width_, border_height_}, 1, GRAY);
    };

//protected:
    float margin_x_;
    float margin_y_;
    float margin_width_;
    float margin_height_;

    void UpdateBorder()
    {
        border_x_ = margin_x_ + margin_;
        border_y_ = margin_y_ + margin_;
        border_width_ = margin_width_ - 2 * margin_;
        border_height_ = margin_height_ - 2 * margin_;
    };

    void UpdateContent()
    {
        x_ = margin_x_ + margin_ + border_ + padding_;
        y_ = margin_y_ + margin_ + border_ + padding_;
        width_ = margin_width_ - 2 * (margin_ + border_ + padding_);
        height_ = margin_height_ - 2 * (margin_ + border_ + padding_);
    };
};

class WrapperDynamic : public Box
{
public:
    WrapperDynamic(float& x, float& y, float& width, float& height)
        : margin_x_(x)
        , margin_y_(y)
        , margin_width_(width)
        , margin_height_(height)
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
        DrawRectangleLinesEx((Rectangle){margin_x_, margin_y_, margin_width_, margin_height_}, 1, GREEN);
        DrawRectangleLinesEx((Rectangle){border_x_, border_y_, border_width_, border_height_}, 1, GRAY);
    };

//protected:
    float& margin_x_;
    float& margin_y_;
    float& margin_width_;
    float& margin_height_;

    void UpdateBorder()
    {
        border_x_ = margin_x_ + margin_;
        border_y_ = margin_y_ + margin_;
        border_width_ = margin_width_ - 2 * margin_;
        border_height_ = margin_height_ - 2 * margin_;
    };

    void UpdateContent()
    {
        x_ = margin_x_ + margin_ + border_ + padding_;
        y_ = margin_y_ + margin_ + border_ + padding_;
        width_ = margin_width_ - 2 * (margin_ + border_ + padding_);
        height_ = margin_height_ - 2 * (margin_ + border_ + padding_);
    };
};
#endif
