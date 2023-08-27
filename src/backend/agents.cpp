#include "agents.h"

#include <iostream>
#include <vector>

Agent::Agent(int rowY, int colX)
    : rowY_(rowY)
    , colX_(colX)
{
    statusCurrent_ = false;
    statusNext_ = false;
    statusOutdated_ = true;
    vitality_ = 0;
    maxVitality_ = 4;
}

void Agent::SetRowY(int posY){ rowY_ = posY; }
int Agent::GetRowY(){ return rowY_; };

void Agent::SetColX(int posX){ colX_ = posX; }
int Agent::GetColX(){ return colX_; };

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

void Agent::EreaseVitality()
{
    vitality_ = 0;
}

int Agent::GetVitality(){ return vitality_; }

void Agent::SetMaxVitality(int maxVitality){ maxVitality_ = maxVitality; }
int Agent::GetMaxVitality(){ return maxVitality_; }