#include "agents.h"

#include <vector>

cAgent::cAgent(int rowY, int colX) {
  mPosY = rowY;
  mPosX = colX;
  mStatusIs = false;
  mStatusNext = false;
  mStatusChanging = true;
  mCheckStatus = true;
  mAdjacentsActive = 0;
  mVitality = 0;
}

cAgent::~cAgent(){}

void cAgent::setStatusIs(bool arg) {
  mStatusIs = arg;
}

bool cAgent::getStatusIs() {
  return mStatusIs;
}

void cAgent::setStatusNext(bool arg) {
  mStatusNext = arg;
  if (mStatusIs != mStatusNext) {
    mStatusChanging  = true;
  } else {
    mStatusChanging = false;
  }
}

bool cAgent::getStatusNext() {
  return mStatusNext;
}

void cAgent::setStatusChanging(bool arg) {
  mStatusChanging = arg;
}

bool cAgent::getStatusChanging() {
  return mStatusChanging;
}

void cAgent::setCheckStatus( bool arg ) {
  mCheckStatus = arg;
}

bool cAgent::getCheckStatus() {
  return mCheckStatus;
}

void cAgent::setVitality(int arg) {
  mVitality = arg;
}

int cAgent::getVitality() {
  return mVitality;
}

void cAgent::decreaseVitality() {
  if (mVitality > 0) {
    mVitality -= 1;
  }
}

int cAgent::countAdjacents(std::vector<std::vector<cAgent>> &agents) {
  int cnt = 0;
  for (int dy : {-1, 0, 1}) {
    for (int dx : {-1, 0, 1}) {
      // wraps around matrix
      int posY = ((mPosY + dy) + agents.size()) % agents.size();
      int posX = ((mPosX + dx) + agents[mPosY].size()) % agents[mPosY].size();

      cAgent &adjacent = agents[posY][posX];

      if ((dy != 0 || dx != 0) && adjacent.getStatusIs() == true) {
        cnt += 1;
      }
    }
  }
  return cnt;
}

void cAgent::pingAdjacents(std::vector<std::vector<cAgent>> &agents) {
  for (int dx : {-1, 0, 1}) {
    for (int dy : {-1, 0, 1}) {
      int posX = ((mPosX + dx) + agents[mPosY].size()) % agents[mPosY].size();
      int posY = ((mPosY + dy) + agents.size()) % agents.size();

      cAgent &adjacent = agents[posY][posX];
      adjacent.setCheckStatus(true);
    }
  }
}