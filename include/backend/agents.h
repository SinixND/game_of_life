#ifndef AGENTS_H
#define AGENTS_H

#include <vector>

class Agent
{
public:
    Agent(int rowY, int colX);

    void SetPosY(int posY);
    int GetPosY();
    
    void SetPosX(int posX);
    int GetPosX();
    
    void SetStatusCurrent(bool statusCurrent);
    bool GetStatusCurrent();
    
    void SetStatusNext(bool statusNext);
    bool GetStatusNext();
    
    void SetStatusOutdated(bool statusOutdated);
    bool GetStatusOutdated();
    
    void RefreshVitality();
    void DecreaseVitality();
    int GetVitality();
    int GetMaxVitality();

private:
    int posY_;
    int posX_;
    bool statusCurrent_;
    bool statusNext_;
    bool statusOutdated_;
    int maxVitality_;
    int vitality_;
};

#endif