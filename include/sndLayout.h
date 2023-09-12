// SNDLayout - A header only library to enable responsive layouts based on raylib and raygui

// sndLayout.h

#ifndef SNDLAYOUT_H
#define SNDLAYOUT_H

#include <raylib.h>

/* LAYOUT BOX STRUCTURE

margin   # # # # # # # # # # # #
margin  #                     #
border  #   - - - - - - - -   #
padding #   -             -   #
content #   -  "Content"  -   #
padding #   -             -   #
border  #   - - - - - - - -   #
margin  #                     #
margin   # # # # # # # # # # # #
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

    int GetMargin() { return margin_; };
    void SetMargin(int margin)
    {
        margin_ = margin;

        UpdateContent();
    };

    int GetBorder() { return border_; };
    void SetBorder(int border)
    {
        border_ = border;

        UpdateContent();
    };

    int GetPadding() { return padding_; };
    void SetPadding(int padding)
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
            DrawRectangleLinesEx((Rectangle){static_cast<float>(margin_x_), static_cast<float>(margin_y_), static_cast<float>(margin_width_), static_cast<float>(margin_height_)}, border_, GRAY);
        };
    };

//protected:
    int& margin_x_;
    int& margin_y_;
    int& margin_width_;
    int& margin_height_;

    int margin_ = 0;

    int border_x_;
    int border_y_;
    int border_width_;
    int border_height_;

    int border_ = 0;
    int padding_ = 0;

    int x_;
    int y_;
    int width_;
    int height_;


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
