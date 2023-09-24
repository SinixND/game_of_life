// SNDLayout - A header only library to enable responsive layouts based on raylib and raygui

#ifndef SNDLAYOUT_H
#define SNDLAYOUT_H

// sndLayout.h

#define DEBUG

#include <vector>

#include <raylib.h>
#include <raygui.h>

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

    void AddButton(Wrapper parent, const char* text, float textSize)
    {
        int textWidth = MeasureText(text, textSize);
        if (GuiButton(
                (Rectangle){
                    static_cast<float>(AlignHorizontalRight(parent, textWidth, 0)),
                    static_cast<float>(AlignVerticalCenter(parent, global.guiButtonBaseHeight, 0)),
                    static_cast<float>(textWidth),
                    static_cast<float>(global.guiButtonBaseHeight)},
                text))
        {
            global.ToggleDarkMode();
        };
    };

    void Render()
    {
        Rectangle marginRect{static_cast<float>(GetMarginLeft()), static_cast<float>(GetMarginTop()), static_cast<float>(GetMarginWidth()), static_cast<float>(GetMarginHeight())};
        DrawRectangleLinesEx(marginRect, GetMargin(), margin);

        Rectangle borderRect{static_cast<float>(GetBorderLeft()), static_cast<float>(GetBorderTop()), static_cast<float>(GetBorderWidth()), static_cast<float>(GetBorderHeight())};
        DrawRectangleLinesEx(borderRect, GetBorder(), border);

        Rectangle paddingRect{static_cast<float>(GetPaddingLeft()), static_cast<float>(GetPaddingTop()), static_cast<float>(GetPaddingWidth()), static_cast<float>(GetPaddingHeight())};
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

    void AddWrapper(Wrapper wrapper)
    {
        wrapper_.push_back(wrapper);
    };

    int& GetMarginLeft() { return margin_left_; };
    int& GetMarginTop() { return margin_top_; };
    int& GetMarginRight() { return margin_right_; };
    int& GetMarginBottom() { return margin_bottom_; };
    int& GetMarginWidth() { return margin_width_; };
    int& GetMarginHeight() { return margin_height_; };
    int GetMargin() { return margin_; };
    void SetMargin(int& margin)
    {
        margin_ = margin;

        UpdateBorder();
    };

    int& GetBorderLeft() { return border_left_; };
    int& GetBorderTop() { return border_top_; };
    int& GetBorderRight() { return border_right_; };
    int& GetBorderBottom() { return border_bottom_; };
    int& GetBorderWidth() { return border_width_; };
    int& GetBorderHeight() { return border_height_; };
    int GetBorder() { return border_; };
    void SetBorder(int& border)
    {
        border_ = border;

        UpdatePadding();
    };

    int& GetPaddingLeft() { return padding_left_; };
    int& GetPaddingTop() { return padding_top_; };
    int& GetPaddingRight() { return padding_right_; };
    int& GetPaddingBottom() { return padding_bottom_; };
    int& GetPaddingWidth() { return padding_width_; };
    int& GetPaddingHeight() { return padding_height_; };
    int GetPadding() { return padding_; };
    void SetPadding(int& padding)
    {
        padding_ = padding;

        UpdateContent();
    };

    int GetFrameWeight() { return frameWeight_; };

    int& GetContentLeft() { return content_left_; };
    int& GetContentTop() { return content_top_; };
    int& GetContentRight() { return content_right_; };
    int& GetContentBottom() { return content_bottom_; };
    int& GetContentWidth() { return content_width_; };
    int& GetContentHeight() { return content_height_; };

protected:
    int margin_ = 2;
    int border_ = 2;
    int padding_ = 2;
    int frameWeight_ = margin_ + border_ + padding_;

    int margin_left_;
    int margin_top_;
    int margin_right_;
    int margin_bottom_;
    int margin_width_ = margin_right_ - margin_left_;
    int margin_height_ = margin_bottom_ - margin_top_;

    int border_left_;
    int border_top_;
    int border_right_;
    int border_bottom_;
    int border_width_ = border_right_ - border_left_;
    int border_height_ = border_bottom_ - border_top_;

    int padding_left_;
    int padding_top_;
    int padding_right_;
    int padding_bottom_;
    int padding_width_ = padding_right_ - padding_left_;
    int padding_height_ = padding_bottom_ - padding_top_;

    int content_left_;
    int content_top_;
    int content_right_;
    int content_bottom_;
    int content_width_ = content_right_ - content_left_;
    int content_height_ = content_bottom_ - content_top_;

    std::vector<Wrapper> wrapper_;

#ifndef DEBUG
    Color margin = BLANK;
    Color border = GRAY;
    Color padding = BLANK;
#endif

#ifdef DEBUG
    Color margin = BLUE;
    Color border = YELLOW;
    Color padding = GREEN;
#endif

    int AlignHorizontalLeft(Wrapper parent, int offset)
    {
        return parent.GetContentLeft() + offset;
    };

    int AlignHorizontalCenter(Wrapper parent, int objectWidth, int offset)
    {
        return parent.GetContentLeft() + ((parent.GetContentWidth() - objectWidth) / 2) + offset;
    };

    int AlignHorizontalRight(Wrapper parent, int objectWidth, int offset)
    {
        return parent.GetContentLeft() + parent.GetContentWidth() - objectWidth - offset;
    };

    int AlignVerticalTop(Wrapper parent, int offset)
    {
        return parent.GetContentTop() + offset;
    };

    int AlignVerticalCenter(Wrapper parent, int objectHeight, int offset)
    {
        return parent.GetContentTop() + ((parent.GetContentHeight() - objectHeight) / 2) + offset;
    };

    int AlignVerticalBottom(Wrapper parent, int objectHeight, int offset)
    {
        return parent.GetContentTop() + (parent.GetContentHeight() - objectHeight - offset);
    };

    void UpdateBorder()
    {
        border_left_ = GetMarginLeft() + margin_;
        border_top_ = GetMarginTop() + margin_;
        border_right_ = GetMarginRight() -  margin_;
        border_bottom_ = GetMarginBottom() -  margin_;
        border_width_ = border_right_ - border_left_;
        border_height_ = border_bottom_ - border_top_;

        UpdatePadding();
    };

    void UpdatePadding()
    {
        padding_left_ = GetMarginLeft() + margin_ + border_;
        padding_top_ = GetMarginTop() + margin_ + border_;
        padding_right_ = GetMarginRight() -  (margin_ + border_);
        padding_bottom_ = GetMarginBottom() -  (margin_ + border_);
        padding_width_ = padding_right_ - padding_left_;
        padding_height_ = padding_bottom_ - padding_top_;

        UpdateContent();
    };

    void UpdateContent()
    {
        content_left_ = GetMarginLeft() + margin_ + border_ + padding_;
        content_top_ = GetMarginTop() + margin_ + border_ + padding_;
        content_right_ = GetMarginRight() -  (margin_ + border_ + padding_);
        content_bottom_ = GetMarginBottom() -  (margin_ + border_ + padding_);
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
