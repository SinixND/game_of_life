#include "agents.h"

#include <vector>
#include <iostream>

cAgent::cAgent(int rowY, int colX) {
  mPosY = rowY;
  mPosX = colX;
  mStatusIs = false;
  mStatusNext = false;
  mStatusChanging = true;
  mCheckStatus = true;
  mAdjacentAgentsActive = 0;
  mVitality = 0;
}

void cAgent::SetStatusNext(bool arg) {
  mStatusNext = arg;
  if (mStatusIs != mStatusNext) {
    mStatusChanging  = true;
  } else {
    mStatusChanging = false;
  }
}
bool cAgent::GetStatusNext() {
  return mStatusNext;
}

void cAgent::DecreaseVitality() {
  if (mVitality > 0) {
    mVitality -= 1;
  }
}