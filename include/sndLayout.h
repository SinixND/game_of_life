#ifndef SNDLAYOUT_H
#define SNDLAYOUT_H

//#define DEBUGGING

#include <raylib.h>
#include <vector>

typedef enum AlignFlags
{
    LEFT                = 0x01,
    CENTER_HORIZONTAL   = 0x02,
    RIGHT               = 0x04,
    TOP                 = 0x08,
    CENTER_VERTICAL     = 0x16,
    BOTTOM              = 0x32
} AlignFlags;

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

    void AddButton(const char* text, float textSize, AlignFlags flags, int offset);
    void Render();
    void AddWrapper(Wrapper wrapper);

    int& GetMarginLeft();
    int& GetMarginTop();
    int& GetMarginRight();
    int& GetMarginBottom();
    int& GetMarginWidth();
    int& GetMarginHeight();
    int GetMargin();
    void SetMargin(int margin);

    int& GetBorderLeft();
    int& GetBorderTop();
    int& GetBorderRight();
    int& GetBorderBottom();
    int& GetBorderWidth();
    int& GetBorderHeight();
    int GetBorder();
    void SetBorder(int border);

    int& GetPaddingLeft();
    int& GetPaddingTop();
    int& GetPaddingRight();
    int& GetPaddingBottom();
    int& GetPaddingWidth();
    int& GetPaddingHeight();
    int GetPadding();
    void SetPadding(int padding);

    int GetFrameWeight();

    int& GetContentLeft();
    int& GetContentTop();
    int& GetContentRight();
    int& GetContentBottom();
    int& GetContentWidth();
    int& GetContentHeight();

private:
    int margin_ = 1;
    int border_ = 1;
    int padding_ = 1;
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

#ifndef DEBUGGING
    Color margin = BLANK;
    Color border = GRAY;
    Color padding = BLANK;
#endif

#ifdef DEBUGGING
    Color margin = BLUE;
    Color border = YELLOW;
    Color padding = GREEN;
#endif

    void UpdateBorder();
    void UpdatePadding();
    void UpdateContent();
    void UpdateFrameWeight();
};

int AlignHorizontalLeft(Wrapper* parent, int offset);
int AlignHorizontalCenter(Wrapper* parent, int objectWidth, int offset);
int AlignHorizontalRight(Wrapper* parent, int objectWidth, int offset);
int AlignVerticalTop(Wrapper* parent, int offset);
int AlignVerticalCenter(Wrapper* parent, int objectHeight, int offset);
int AlignVerticalBottom(Wrapper* parent, int objectHeight, int offset);

#endif
