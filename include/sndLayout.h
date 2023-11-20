#ifndef LAYOUT_H_202311201531
#define LAYOUT_H_202311201531

#include <raylib.h>
#include <functional>
#include <memory>
#include <string>
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
namespace sxd
{
    typedef enum Align
    {
        NONE = 0x00,
        LEFT = 0x01,
        CENTER_HORIZONTAL = 0x02,
        RIGHT = 0x04,
        TOP = 0x08,
        CENTER_VERTICAL = 0x10,
        BOTTOM = 0x20
    } Align;

    class Wrapper
    {
    public:
        Wrapper(const char* label);
        Wrapper(int left, int top, int right, int bottom);
        Wrapper(const char* label, int left, int top, int right, int bottom);
        virtual ~Wrapper();

        virtual void Render();
        void AddWrapper(std::shared_ptr<Wrapper> wrapper);
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
        std::string label_{};

        int outerLeft_ = 0;
        int outerTop_ = 0;
        int outerRight_ = 0;
        int outerBottom_ = 0;
        int outerWidth_ = 0;
        int outerHeight_ = 0;

        int margin_{3};
        int border_{1};
        int padding_{2};

        int frameWeight_ = margin_ + border_ + padding_;

        Color frameColor_ = BLANK;

        int innerLeft_ = outerLeft_ + frameWeight_;
        int innerTop_ = outerTop_ + frameWeight_;
        int innerRight_ = outerRight_ - frameWeight_;
        int innerBottom_ = outerBottom_ - frameWeight_;
        int innerWidth_ = innerRight_ - innerLeft_;
        int innerHeight_ = innerBottom_ - innerTop_;

        std::vector<std::shared_ptr<Wrapper>> wrappers_;

        Align alignedHorizontal_ = NONE;
        Align alignedVertical_ = NONE;

        void UpdateFrame();

        void SetFrameWeight(int frameWeight);
        void SetFrameColor(Color frameColor);
    };

    class Element : public Wrapper
    {
    public:
        Element(const char* label);
        Element(const char* label, int fontSize, int left, int top, int right, int bottom);
        virtual ~Element();

        void AlignToParent(Wrapper* element, Align flags, int offset);

        void AttachToLeft(Element* parent);
        void AttachToTop(Element* parent);
        void AttachToRight(Element* parent);
        void AttachToBottom(Element* parent);

        void AttachToTopAndAlign(Element* parent);
        void AttachToBottomAndAlign(Element* parent);

    protected:
        int fontSize_;
        Element* parent_ = nullptr;
    };

    class Button : public Element
    {
    public:
        Button(const char* label);
        Button(const char* label, int fontSize, std::function<bool()> inputs, std::function<void()> action, int left, int top, int right, int bottom);
        Button(const char* label, int fontSize, std::function<bool()> inputs, std::function<void()> action, Wrapper* parent, Align flags, int offset);
        ~Button();

        void Render();

        std::function<bool()> GetInputs();
        void SetInputs(std::function<bool()> inputs);
        std::function<void()> GetAction();
        void SetAction(std::function<void()> action);

    private:
        std::function<bool()> inputs_;
        std::function<void()> action_;
    };

    class Separator : public Element
    {
    public:
        Separator(const char* label, int left, int right, Wrapper* parent, Align flags, int offset);
        ~Separator();

        void Render();
    };

    class Spacer : public Element
    {
    public:
        Spacer(const char* label, int vSpace, int hSpace, Wrapper* parent, Align flags, int offset);
        ~Spacer();

        void Render();
    };

    class Label : public Element
    {
    public:
        Label(const char* label, int fontSize, Wrapper* parent, Align flags, int offset);
        ~Label();

        void Render();
    };

    class Text : public Element
    {
    public:
        Text(const char* label, int fontSize, Wrapper* parent, Align flags, int offset);
        ~Text();

        void Render();

    private:
    };

    class CheckBox : public Element
    {
    public:
        CheckBox(const char* label, int fontSize, bool* value, Wrapper* parent, Align flags, int offset);
        ~CheckBox();

        void Render();

    private:
        bool* value_;
    };

    class Spinner : public Element
    {
    public:
        Spinner(const char* label, int fontSize, int* value, int minValue, int maxValue, bool editMode, Wrapper* parent, Align flags, int offset);
        ~Spinner();

        void Render();

    private:
        int* value_;
        int minValue_;
        int maxValue_;
        bool editMode_;
    };

    int AlignHorizontalLeft(Wrapper* parent, int offset);
    int AlignHorizontalCenter(Wrapper* parent, int objectWidth, int offset);
    int AlignHorizontalRight(Wrapper* parent, int objectWidth, int offset);
    int AlignVerticalTop(Wrapper* parent, int offset);
    int AlignVerticalCenter(Wrapper* parent, int objectHeight, int offset);
    int AlignVerticalBottom(Wrapper* parent, int objectHeight, int offset);
} // namespace sxd

#endif