// SNDLayout - A header only library to enable responsive layouts based on raylib and raygui

// sndLayout.h

#ifndef SNDLAYOUT_H
#define SNDLAYOUT_H

#include <raylib.h>

class Frame
{
public:
    Frame(float x, float y, float width, float height)
    {
        anchor_ = {x, y};
        dimensions_ = {width, height};
        frame_ = {anchor_.x, anchor_.y, width, height};
        content_ = {frame_.x, frame_.y, frame_.width, frame_.height};
    };

    void SetMargin(int margin)
    {
        margin_ = margin;
        frame_.x = margin_;
        frame_.y = margin_;
        frame_.width -= 2 * (float)margin_;
        frame_.height -= 2 * (float)margin_;
    };

    int GetMargin() { return margin_; };

    void SetBorder(int border)
    {
        border_ = border;
    };

    int GetBorder() { return border_; };

    void SetPadding(int padding) { padding_ = padding; };
    int GetPadding() { return padding_; };

    void RenderFrame()
    {
        if (border_ > 0)
        {
            DrawRectangleLinesEx(frame_, border_, GRAY);
        }
    }

private:
    Vector2 anchor_ = {0, 0};
    Vector2 dimensions_ = {0, 0};
    Rectangle frame_ = {0, 0, 0, 0};
    Rectangle content_ = {0, 0, 0, 0};
    int margin_ = 0;
    int border_ = 0;
    int padding_ = 0;
};
#endif
