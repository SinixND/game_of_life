#ifndef AGENTS_H
#define AGENTS_H

#include <vector>

class cAgent
{
public:
    cAgent(int rowY, int colX);

    int posY_;
    int posX_;
    bool statusIs_;
    bool statusChanging_;
    bool checkStatus_;
    int vitality_;

    void DecreaseVitality();

private:
    bool statusNext_;
    int adjacentAgentsActive_;

public:
    void SetStatusNext(bool status);
    bool GetStatusNext();
};

#endif