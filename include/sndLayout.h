#ifndef SNDLAYOUT_H
#define SNDLAYOUT_H

// #define DEBUGGING

#include <raylib.h>
#include <vector>

typedef enum sndAlign
{
    LEFT = 0x01,
    CENTER_HORIZONTAL = 0x02,
    RIGHT = 0x04,
    TOP = 0x08,
    CENTER_VERTICAL = 0x10,
    BOTTOM = 0x20
} sndAlign;

class sndWrapper
{
public:
    template <typename T1, typename T2, typename T3, typename T4>
    sndWrapper(T1&& left, T2&& top, T3&& right, T4&& bottom)
    : outerLeft_(left)
    , outerTop_(top)
    , outerRight_(right)
    , outerBottom_(bottom)
    {
        Update();
    };

    void Append(sndWrapper& element, sndAlign flags, int offset);
    void Render();
    void AddWrapper(sndWrapper wrapper);

    int& GetOuterLeft();
    void SetOuterLeft(int& outerLeft);
    int& GetOuterTop();
    void SetOuterTop(int& outerTop);
    int& GetOuterRight();
    void SetOuterRight(int& outerRight);
    int& GetOuterBottom();
    void SetOuterBottom(int& outerBottom);
    int& GetOuterWidth();
    void SetOuterWidth(int& outerWidth);
    int& GetOuterHeight();
    void SetOuterHeight(int& outerHeight);

    int& GetFrameWeight();
    void SetFrameWeight(int& frameWeight);

    int& GetInnerLeft();
    void SetInnerLeft(int& innerLeft);
    int& GetInnerTop();
    void SetInnerTop(int& innerTop);
    int& GetInnerRight();
    void SetInnerRight(int& innerRight);
    int& GetInnerBottom();
    void SetInnerBottom(int& innerBottom);
    int& GetInnerWidth();
    void SetInnerWidth(int& innerWidth);
    int& GetInnerHeight();
    void SetInnerHeight(int& innerHeight);

private:
    int outerLeft_;
    int outerTop_;
    int outerRight_;
    int outerBottom_;
    int outerWidth_;
    int outerHeight_;

    int frameWeight_ = 1;

    int innerLeft_ = outerLeft_ + frameWeight_;
    int innerTop_ = outerTop_ + frameWeight_;
    int innerRight_ = outerRight_ - frameWeight_;
    int innerBottom_ = outerBottom_ - frameWeight_;
    int innerWidth_ = innerRight_ - innerLeft_;
    int innerHeight_ = innerBottom_ - innerTop_;
    
    std::vector<sndWrapper> wrapper_;

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

    void Update();

};

class sndButton : public sndWrapper
{
public:
    sndButton(const char* text, int fontSize)
        : sndWrapper(0, 0, MeasureText(text, fontSize), fontSize)
    {

    };
};

int AlignHorizontalLeft(sndWrapper* parent, int offset);
int AlignHorizontalCenter(sndWrapper* parent, int objectWidth, int offset);
int AlignHorizontalRight(sndWrapper* parent, int objectWidth, int offset);
int AlignVerticalTop(sndWrapper* parent, int offset);
int AlignVerticalCenter(sndWrapper* parent, int objectHeight, int offset);
int AlignVerticalBottom(sndWrapper* parent, int objectHeight, int offset);

#endif
