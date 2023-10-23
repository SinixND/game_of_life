#ifndef SNDLAYOUT_H
#define SNDLAYOUT_H

#include <raylib.h>
#include <vector>

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

    void Append(sndWrapper& element, sndAlign flags, int offset);
    void Render();
    void AddWrapper(sndWrapper wrapper);
    void ClearWrappers();
    void AddButton(const char* text, void (*function)(), int x, int y, sndAlign flags, int offset);

    int GetOuterLeft();
    void SetOuterLeft(int outerLeft);
    int GetOuterTop();
    void SetOuterTop(int outerTop);
    int GetOuterRight();
    void SetOuterRight(int outerRight);
    int GetOuterBottom();
    void SetOuterBottom(int outerBottom);
    int GetOuterWidth();
    void SetOuterWidth(int outerWidth);
    int GetOuterHeight();
    void SetOuterHeight(int outerHeight);

    int GetMargin();
    void SetMargin(int setMargin);
    int GetBorder();
    void SetBorder(int setBorder);
    int GetPadding();
    void SetPadding(int setPadding);
    
    int GetFrameWeight();
    void SetFrameWeight(int frameWeight);
    Color GetFrameColor();
    void SetFrameColor(Color frameColor);

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

    int margin_ = 0;
    int border_ = 0;
    int padding_ = 0;
    int frameWeight_ = 0;
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

};

class sndButton : public sndWrapper
{
public:
    void SetText(const char* text);
    const char* GetText();
    std::function<void> GetFunction();
    void SetFunction(void (*function)());

private:
    const char* text_;
    std::function<void> function_;
};

int AlignHorizontalLeft(sndWrapper* parent, int offset);
int AlignHorizontalCenter(sndWrapper* parent, int objectWidth, int offset);
int AlignHorizontalRight(sndWrapper* parent, int objectWidth, int offset);
int AlignVerticalTop(sndWrapper* parent, int offset);
int AlignVerticalCenter(sndWrapper* parent, int objectHeight, int offset);
int AlignVerticalBottom(sndWrapper* parent, int objectHeight, int offset);

#endif
