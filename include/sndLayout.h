#ifndef SNDLAYOUT_H
#define SNDLAYOUT_H

#include <raylib.h>
#include <vector>
#include <functional>

/* LAYOUT BOX STRUCTURE

margin    m m m m m m m m m m   frame
border    m B B B B B B B B m   frame
padding   m B p p p p p p B m   frame
content   m B p CONTENT p B m 
padding   m B p p p p p p B m   frame
border    m B B B B B B B B m   frame
margin    m m m m m m m m m m   frame

*/

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
    //template <typename T1, typename T2, typename T3, typename T4>
    //sndWrapper(T1&& left, T2&& top, T3&& right, T4&& bottom)
    sndWrapper();
    sndWrapper(int left, int top, int right, int bottom);

    void Append(sndWrapper element, sndAlign flags, int offset);
    void Render();
    void AddWrapper(sndWrapper wrapper);
    void ClearWrappers();
    void AddButton(const char* text, std::function<void()> fn, sndAlign flags, int offset);

    int GetOuterLeft();
    void ResizeOuterLeft(int outerLeft);
    void MoveOuterLeft(int outerLeft);
    int GetOuterTop();
    void ResizeOuterTop(int outerTop);
    void MoveOuterTop(int outerTop);
    int GetOuterRight();
    void ResizeOuterRight(int outerRight);
    void MoveOuterRight(int outerRight);
    int GetOuterBottom();
    void ResizeOuterBottom(int outerBottom);
    void MoveOuterBottom(int outerBottom);
    int GetOuterWidth();
    void ResizeOuterWidth(int outerWidth);
    void MoveOuterWidth(int outerWidth);
    int GetOuterHeight();
    void ResizeOuterHeight(int outerHeight);
    void MoveOuterHeight(int outerHeight);

    int GetMargin();
    void SetMargin(int setMargin);
    int GetBorder();
    void SetBorder(int setBorder);
    int GetPadding();
    void SetPadding(int setPadding);
    
    int GetFrameWeight();
    Color GetFrameColor();

    int GetInnerLeft();
    int GetInnerTop();
    int GetInnerRight();
    int GetInnerBottom();
    int GetInnerWidth();
    int GetInnerHeight();

    std::vector<sndWrapper> GetWrappers();

private:
    int outerLeft_ = 0;
    int outerTop_ = 0;
    int outerRight_ = 0;
    int outerBottom_ = 0;
    int outerWidth_ = 0;
    int outerHeight_ = 0;

    int margin_{0};
    int border_{0};
    int padding_{0};
    int frameWeight_{0};
    //Color frameColor_ = BLANK; 
    Color frameColor_ = GRAY; 

    int innerLeft_ = outerLeft_ + frameWeight_;
    int innerTop_ = outerTop_ + frameWeight_;
    int innerRight_ = outerRight_ - frameWeight_;
    int innerBottom_ = outerBottom_ - frameWeight_;
    int innerWidth_ = innerRight_ - innerLeft_;
    int innerHeight_ = innerBottom_ - innerTop_;

    std::vector<sndWrapper> wrappers_;
    
    void Update();

    void SetFrameWeight(int frameWeight);
    void SetFrameColor(Color frameColor);
};

class sndButton : public sndWrapper
{
public:
    sndButton();
    sndButton(int left, int top, int right, int bottom);

    void Render();

    void SetText(const char* text);
    const char* GetText();
    std::function<void()> GetFunction();
    void SetFunction(std::function<void()> fn);

private:
    const char* text_;
    std::function<void()> fn_;
};

int AlignHorizontalLeft(sndWrapper* parent, int offset);
int AlignHorizontalCenter(sndWrapper* parent, int objectWidth, int offset);
int AlignHorizontalRight(sndWrapper* parent, int objectWidth, int offset);
int AlignVerticalTop(sndWrapper* parent, int offset);
int AlignVerticalCenter(sndWrapper* parent, int objectHeight, int offset);
int AlignVerticalBottom(sndWrapper* parent, int objectHeight, int offset);

#endif
