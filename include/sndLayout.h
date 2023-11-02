#ifndef SNDLAYOUT_H
#define SNDLAYOUT_H

#include <raylib.h>
#include <vector>
#include <functional>
#include <memory>
#include <stdarg.h>

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
    sndWrapper(const char* label);
    sndWrapper(int left, int top, int right, int bottom);
    sndWrapper(const char* label, int left, int top, int right, int bottom);
    virtual ~sndWrapper();

    virtual void Render();
    void AddWrapper(std::shared_ptr<sndWrapper> wrapper);
    void ClearWrappers();

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
    int GetOuterHeight();

    int GetMargin();
    void SetMargin(int marginWeight);
    int GetBorder();
    void SetBorder(int borderWeight);
    int GetPadding();
    void SetPadding(int paddingWeight);
    
    int GetFrameWeight();
    Color GetFrameColor();

    int GetInnerLeft();
    int GetInnerTop();
    int GetInnerRight();
    int GetInnerBottom();
    int GetInnerWidth();
    int GetInnerHeight();

protected:
    const char* label_{};

    int outerLeft_ = 0;
    int outerTop_ = 0;
    int outerRight_ = 0;
    int outerBottom_ = 0;
    int outerWidth_ = 0;
    int outerHeight_ = 0;

    int margin_{1};
    int border_{1};
    int padding_{1};

    int frameWeight_ = margin_ + border_ + padding_;

    Color frameColor_ = BLANK; 

    int innerLeft_ = outerLeft_ + frameWeight_;
    int innerTop_ = outerTop_ + frameWeight_;
    int innerRight_ = outerRight_ - frameWeight_;
    int innerBottom_ = outerBottom_ - frameWeight_;
    int innerWidth_ = innerRight_ - innerLeft_;
    int innerHeight_ = innerBottom_ - innerTop_;

    std::vector<std::shared_ptr<sndWrapper>> wrappers_;
    
    sndAlign alignedHorizontal_ = NONE;
    sndAlign alignedVertical_ = NONE;

    void UpdateFrame();

    void SetFrameWeight(int frameWeight);
    void SetFrameColor(Color frameColor);
};

class sndElement : public sndWrapper
{
public:
    sndElement(const char* label);
    sndElement(const char* label, int fontSize, int left, int top, int right, int bottom);
    virtual ~sndElement();

    void AlignToParent(sndWrapper* element, sndAlign flags, int offset);

    void AttachToLeft(sndElement* parent);
    void AttachToTop(sndElement* parent);
    void AttachToRight(sndElement* parent);
    void AttachToBottom(sndElement* parent);

    void AttachToTopAndAlign(sndElement* parent);
    void AttachToBottomAndAlign(sndElement* parent);

protected:
    int fontSize_;
    sndElement* parent_ = nullptr;
};

class sndButton : public sndElement
{
public:
    sndButton(const char* label);
    sndButton(const char* label, int fontSize, std::function<void()> fn, int left, int top, int right, int bottom);
    sndButton(const char* label, int fontSize, std::function<void()> fn, sndWrapper* parent, sndAlign flags, int offset);
    ~sndButton();

    void Render();

    std::function<void()> GetAction();
    void SetAction(std::function<void()> action);

private:
    std::function<void()> action_;
};

class sndSeparator : public sndElement
{
public:
    sndSeparator(const char* label, int left, int right, sndWrapper* parent, sndAlign flags, int offset);
    ~sndSeparator();

    void Render();
};

class sndVSpacer : public sndElement
{
public:
    sndVSpacer(const char* label, int vSpace, sndWrapper* parent, sndAlign flags, int offset);
    ~sndVSpacer();

    void Render();
};

class sndHSpacer : public sndElement
{
public:
    sndHSpacer(const char* label, int hSpace, sndWrapper* parent, sndAlign flags, int offset);
    ~sndHSpacer();

    void Render();
};

class sndLabel : public sndElement
{
public:
    sndLabel(const char* label, int fontSize, sndWrapper* parent, sndAlign flags, int offset);
    ~sndLabel();

    void Render();
};

class sndText : public sndElement
{
public:
    sndText(const char* label, int fontSize, sndWrapper* parent, sndAlign flags, int offset);
    ~sndText();

    void Render();

private:
};

class sndCheckBox : public sndElement
{
public:
    sndCheckBox(const char* label, int fontSize, sndWrapper* parent, sndAlign flags, int offset);
    ~sndCheckBox();

    void Render();

private:
};

int AlignHorizontalLeft(sndWrapper* parent, int offset);
int AlignHorizontalCenter(sndWrapper* parent, int objectWidth, int offset);
int AlignHorizontalRight(sndWrapper* parent, int objectWidth, int offset);
int AlignVerticalTop(sndWrapper* parent, int offset);
int AlignVerticalCenter(sndWrapper* parent, int objectHeight, int offset);
int AlignVerticalBottom(sndWrapper* parent, int objectHeight, int offset);

#endif