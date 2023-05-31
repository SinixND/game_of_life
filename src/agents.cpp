#include "agents.h"

#include <vector>

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

cAgent::~cAgent(){}

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

int cAgent::CountAdjacentAgents(std::vector<std::vector<cAgent>>& agents) {
  int cnt = 0;
  for (int dy : {-1, 0, 1}) {
    for (int dx : {-1, 0, 1}) {
      // wraps around matrix
      int posY = ((mPosY + dy) + agents.size()) % agents.size();
      int posX = ((mPosX + dx) + agents[mPosY].size()) % agents[mPosY].size();

      cAgent& adjacentAgent = agents[posY][posX];

      if ((dy != 0 || dx != 0) && adjacentAgent.mStatusIs == true) {
        cnt += 1;
      }
    }
  }
  return cnt;
}

void cAgent::PingAdjacentAgents(std::vector<std::vector<cAgent>>& agents) {
  for (int dx : {-1, 0, 1}) {
    for (int dy : {-1, 0, 1}) {
      // wraps around matrix
      int posY = ((mPosY + dy) + agents.size()) % agents.size();
      int posX = ((mPosX + dx) + agents[mPosY].size()) % agents[mPosY].size();

      cAgent& adjacentAgent = agents[posY][posX];
      adjacentAgent.mCheckStatus = true;
    }
  }
}