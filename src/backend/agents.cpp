#include "agents.h"

#include <iostream>
#include <vector>

Agent::Agent(int rowY, int colX)
    : posY_(rowY)
    , posX_(colX)
{
    statusCurrent_ = false;
    statusNext_ = false;
    statusOutdated_ = true;
    vitality_ = 0;
    maxVitality_ = 3;
}

void Agent::SetPosY(int posY){ posY_ = posY; }
int Agent::GetPosY(){ return posY_; };

void Agent::SetPosX(int posX){ posX_ = posX; }
int Agent::GetPosX(){ return posX_; };

void Agent::SetStatusCurrent(bool statusCurrent){ statusCurrent_ = statusCurrent; };
bool Agent::GetStatusCurrent(){ return statusCurrent_; };

void Agent::SetStatusNext(bool statusNext){ statusNext_ = statusNext; };
bool Agent::GetStatusNext(){ return statusNext_; };

void Agent::SetStatusOutdated(bool statusOutdated){ statusOutdated_ = statusOutdated; };
bool Agent::GetStatusOutdated(){ return statusOutdated_; };

void Agent::RefreshVitality()
{
    // Max vitality. determines fractions of color shade
    vitality_ = maxVitality_;
}

void Agent::DecreaseVitality()
{
    if (vitality_ > 0)
    {
        vitality_ -= 1;
    }
}

int Agent::GetVitality()
{
    return vitality_;
}

int Agent::GetMaxVitality()
{
    return maxVitality_;
}