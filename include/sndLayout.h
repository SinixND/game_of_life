// SNDLayout - A header only library to enable responsive layouts based on raylib and raygui

// sndLayout.h

#ifndef SNDLAYOUT_H
#define SNDLAYOUT_H

#include <raylib.h>

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
    template <typename T>
    Box(T&& x, T&& y, T&& width, T&& height)
        : margin_x_(x)
        , margin_y_(y)
        , margin_width_(width)
        , margin_height_(height)
    {
    };

    float GetMargin() { return margin_; };
    void SetMargin(float margin)
    {
        margin_ = margin;

        UpdateContent();
    };

    float GetBorder() { return border_; };
    void SetBorder(float border)
    {
        border_ = border;

        UpdateContent();
    };

    float GetPadding() { return padding_; };
    void SetPadding(float padding)
    {
        padding_ = padding;
        UpdateContent();
    };

    //Rectangle GetContentRectangle()
    //{
        //return (Rectangle){x_, y_, width_, height_};
    //};

    void RenderBox()
    {
        if (border_ > 0)
        {
            DrawRectangleLinesEx((Rectangle){margin_x_, margin_y_, margin_width_, margin_height_}, border_, GRAY);
        };
    };

//protected:
    float& margin_x_;
    float& margin_y_;
    float& margin_width_;
    float& margin_height_;

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


    void UpdateBorder()
    {
        border_x_ = margin_;
        border_y_ = margin_;
        border_width_ -= 2 * margin_;
        border_height_ -= 2 * margin_;
    };

    void UpdateContent()
    {
        x_ = margin_ + border_ + padding_;
        y_ = margin_ + border_ + padding_;
        width_ -= 2 * (margin_ + border_ + padding_);
        height_ -= 2 * (margin_ + border_ + padding_);
    };
};
#endif
