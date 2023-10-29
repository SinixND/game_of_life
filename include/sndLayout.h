#ifndef SNDLAYOUT_H
#define SNDLAYOUT_H

#include <raylib.h>
#include <vector>
#include <functional>
#include <memory>

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
    NONE = 0x00,
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
    sndWrapper();
    sndWrapper(const char* label);
    sndWrapper(const char* label, int left, int top, int right, int bottom);
    ~sndWrapper();

    virtual void Render();
    void AddWrapper(std::shared_ptr<sndWrapper> wrapper);
    void ClearWrappers();
    void AdjustPosition(std::shared_ptr<sndWrapper> element, sndAlign flags, int offset);

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

protected:
    int outerLeft_ = 0;
    int outerTop_ = 0;
    int outerRight_ = 0;
    int outerBottom_ = 0;
    int outerWidth_ = 0;
    int outerHeight_ = 0;

    int margin_{1};
    int border_{0};
    int padding_{1};

    int frameWeight_{0};

    Color frameColor_ = BLANK; 

    int innerLeft_ = outerLeft_ + frameWeight_;
    int innerTop_ = outerTop_ + frameWeight_;
    int innerRight_ = outerRight_ - frameWeight_;
    int innerBottom_ = outerBottom_ - frameWeight_;
    int innerWidth_ = innerRight_ - innerLeft_;
    int innerHeight_ = innerBottom_ - innerTop_;

    std::vector<std::shared_ptr<sndWrapper>> wrappers_;
    
    const char* label_;

    sndAlign alignedHorizontal = NONE;
    sndAlign alignedVertical = NONE;

    void Update();

    void SetFrameWeight(int frameWeight);
    void SetFrameColor(Color frameColor);
};

class sndButton : public sndWrapper
{
public:
    sndButton();
    sndButton(const char* label);
    sndButton(const char* label, std::function<void()> fn, std::shared_ptr<sndWrapper> parent, sndAlign flags, int offset);
    sndButton(const char* label, std::function<void()> fn, int left, int top, int right, int bottom);
    ~sndButton();

    void Render();

    void SetLabel(const char* label);
    const char* GetLabel();
    std::function<void()> GetAction();
    void SetAction(std::function<void()> action);

    void AttachToLeft(std::shared_ptr<sndButton> parent);
    void AttachToTop(std::shared_ptr<sndButton> parent);
    void AttachToRight(std::shared_ptr<sndButton> parent);
    void AttachToBottom(std::shared_ptr<sndButton> parent);

private:
    std::function<void()> action_;
    sndButton* parent_ = nullptr;
};

int AlignHorizontalLeft(sndWrapper* parent, int offset);
int AlignHorizontalCenter(sndWrapper* parent, int objectWidth, int offset);
int AlignHorizontalRight(sndWrapper* parent, int objectWidth, int offset);
int AlignVerticalTop(sndWrapper* parent, int offset);
int AlignVerticalCenter(sndWrapper* parent, int objectHeight, int offset);
int AlignVerticalBottom(sndWrapper* parent, int objectHeight, int offset);

#endif
