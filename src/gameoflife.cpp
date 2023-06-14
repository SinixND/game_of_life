#include "gameoflife.h"

#include <iostream>
#include <vector>
#include <cstdlib>

#include "configs.h" // provide object "config" for configurable parameters
#include "agents.h"

typedef std::vector<cAgent> vAgents;

cGameOfLife::cGameOfLife(int rowsY, int colsX){
  mRowsY = rowsY;
  mColsX = colsX;

  ResetGameOfLife();
};

void cGameOfLife::ResetGameOfLife() {
  mDay = 0;
  mGrid.clear();
  mGridState.clear();
  mGridStates.clear();

  // INITIALIZE AGENTS
  //---------------------------------
  for (auto rowY = 0; rowY < mRowsY; ++rowY) {
    vAgents newRow;
    mGrid.push_back(newRow);

    for (auto colX = 0; colX < mColsX; ++colX) {
      mGrid[rowY].push_back(cAgent(rowY, colX));

      cAgent& agent = mGrid[rowY][colX];

      if (((rand() % 100) * 0.01) <= config.lifeDensity) {
        agent.mStatusIs = true; // make alive
        mGridState.push_back(true);
      } else {
        mGridState.push_back(false);
      }
    }
  }
  mGridStates.push_back(mGridState);
  mGridState.clear();
}

int cGameOfLife::CountAdjacentAgents(cAgent& agent){
  int cnt = 0;
  for (auto dy : {-1, 0, 1}) {
    for (auto dx : {-1, 0, 1}) {
      // wraps around matrix
      int posY = ((agent.mPosY + dy) + mGrid.size()) % mGrid.size();
      int posX = ((agent.mPosX + dx) + mGrid[posY].size()) % mGrid[posY].size();

      cAgent& adjacentAgent = mGrid[posY][posX];

      if ((dy != 0 || dx != 0) && adjacentAgent.mStatusIs == true) {
        cnt += 1;
      }
    }
  }
  return cnt;
};

void cGameOfLife::ProcessGameOfLife(){
  // DETERMINE NEXT AGENTS STATE
  //---------------------------------
  for (auto& row : mGrid) {
    for (auto& agent : row) {
      // Default Ruleset:
      // AdjacentAgent count = 2 -> remain.
      // AdjacentAgent count = 3 -> alive.
      // All other die.

      if (agent.mCheckStatus == false)
      {
        continue;
      }
      agent.mCheckStatus = false;

      switch (CountAdjacentAgents(agent)){
      case 2:
        agent.SetStatusNext(agent.mStatusIs);
        break;
      
      case 3:
        agent.SetStatusNext(true);
        break;
      
      default:
        agent.SetStatusNext(false);
        break;
      }
    }
  }
};

void cGameOfLife::PingAdjacentAgents(cAgent& agent){
  for (auto dx : {-1, 0, 1}) {
    for (auto dy : {-1, 0, 1}) {
      // wraps around matrix
      int posY = ((agent.mPosY + dy) + mGrid.size()) % mGrid.size();
      int posX = ((agent.mPosX + dx) + mGrid[posY].size()) % mGrid[posY].size();

      cAgent& adjacentAgent = mGrid[posY][posX];
      adjacentAgent.mCheckStatus = true;
    }
  }
};

void cGameOfLife::UpdateGameOfLife(){
  mDay += 1;

  // UPDATE AGENTS
  //---------------------------------
  for (auto& row : mGrid) {
    for (auto& agent : row) {
      if (agent.mStatusChanging == true) {
        PingAdjacentAgents(agent);

        if (agent.GetStatusNext() == true) {
          agent.mStatusIs = true;

          if (config.fadingAgents == true) {
            agent.mVitality = 4;
          }
        } else {
          agent.mStatusIs = false;
        }
      }

      if (agent.mStatusIs == true) {
        mGridState.push_back(true);
      } else {
        mGridState.push_back(false);
        agent.DecreaseVitality();
      }
    }
  }
  mGridStates.push_back(mGridState);
  mGridState.clear();
};

void cGameOfLife::EvolveGrid(){
  ProcessGameOfLife();
  UpdateGameOfLife();
};


vvAgents& cGameOfLife::GetGrid(){ return mGrid; };

int cGameOfLife::GetDay(){ return mDay; };