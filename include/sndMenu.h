#include "sndScreen.h"

#include "sndLayout.h"

class Menu : public Screen
{
public:
    Frame main_;

    void Run();

private:
    void Process();
    void Update();
    void Render();
};