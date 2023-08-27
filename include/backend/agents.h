#ifndef AGENTS_H
#define AGENTS_H

#include <vector>

class Agent
{
public:
    Agent(int rowY, int colX);

    void SetRowY(int posY);
    int GetRowY();
    
    void SetColX(int posX);
    int GetColX();
    
    void SetStatusCurrent(bool statusCurrent);
    bool GetStatusCurrent();
    
    void SetStatusNext(bool statusNext);
    bool GetStatusNext();
    
    void SetStatusOutdated(bool statusOutdated);
    bool GetStatusOutdated();
    
    void RefreshVitality();
    void DecreaseVitality();
    void EreaseVitality();
    int GetVitality();
    void SetMaxVitality(int maxVitality);
    int GetMaxVitality();

private:
    int rowY_;
    int colX_;
    bool statusCurrent_;
    bool statusNext_;
    bool statusOutdated_;
    int maxVitality_;
    int vitality_;
};

#endif