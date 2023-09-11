// SNDLayout - A header only library to enable responsive layouts based on raylib and raygui

// sndLayout.h

#ifndef SNDLAYOUT_H
#define SNDLAYOUT_H

#include <raylib.h>

class Frame
{
public:
    template < typename T > // for an arbitraty type
    Frame(T&& x, T&& y, T&& width, T&& height)
    {
        frame_ = {x, y, width, height};
        content_ = {x, y, width, height};
    };

    int& GetMargin() { return margin_; };
    template < typename T > // for an arbitraty type
    void SetMargin(T&& margin)
    {
        margin_ = margin;

        UpdateFrame();
        UpdateContent();
    };

    int& GetBorder() { return border_; };
    template < typename T > // for an arbitraty type
    void SetBorder(T&& border)
    {
        border_ = border;

        UpdateContent();
    };

    int& GetPadding() { return padding_; };
    template < typename T > // for an arbitraty type
    void SetPadding(T&& padding)
    {
        padding_ = padding;
        UpdateContent();
    };

    Rectangle& GetContentRectangle() { return content_; };

    void RenderFrame()
    {
        if (border_ > 0)
        {
            DrawRectangleLinesEx(frame_, border_, GRAY);
        }
    }

protected:
    int margin_ = 0;
    int border_ = 0;
    int padding_ = 0;

    Rectangle frame_ = {0, 0, 0, 0};
    void UpdateFrame()
    {
        frame_.x = margin_;
        frame_.y = margin_;
        frame_.width -= 2 * (float)margin_;
        frame_.height -= 2 * (float)margin_;
    };

    Rectangle content_ = {0, 0, 0, 0};
    void UpdateContent()
    {
        content_.x = margin_ + border_ + padding_;
        content_.y = margin_ + border_ + padding_;
        content_.width -= 2 * (float)(margin_ + border_ + padding_);
        content_.height -= 2 * (float)(margin_ + border_ + padding_);
    };
};

class Panel : public Frame
{
public:
    Panel(Rectangle& parent)
        : Frame(parent.x, parent.y, parent.width, parent.height){};

    void RenderFrame()
    {
        UpdateContent();
        if (border_ > 0)
        {
            DrawRectangleLinesEx(frame_, border_, RED);
        }
    };
};
#endif
