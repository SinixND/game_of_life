#include "agents.h"

#include <vector>
#include <iostream>

cAgent::cAgent(int rowY, int colX) 
  : posY_{rowY}
  , posX_{colX}
{
  statusIs_ = false;
  statusNext_ = false;
  statusChanging_ = true;
  checkStatus_ = true;
  adjacentAgentsActive_ = 0;
  vitality_ = 0;
}

void cAgent::SetStatusNext(bool arg) {
  statusNext_ = arg;
  if (statusIs_ != statusNext_) {
    statusChanging_  = true;
  } else {
    statusChanging_ = false;
  }
}
bool cAgent::GetStatusNext() {
  return statusNext_;
}

void cAgent::DecreaseVitality() {
  if (vitality_ > 0) {
    vitality_ -= 1;
  }
}