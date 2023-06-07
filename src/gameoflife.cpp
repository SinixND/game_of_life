#include "gameoflife.h"

#include <vector>

#include "agents.h"
#include "configs.h" // provide object "config" for configurable parameters

typedef std::vector<cAgent> vAgents;

cGameOfLife::cGameOfLife(int rowsY, int colsX){
  mRowsY = rowsY;
  mColsX = colsX;

  mGrid = InitialiseGameOfLife();
};

void cGameOfLife::InitializeGameOfLife() {
  // INITIALIZE AGENTS
  //---------------------------------
  for (auto rowY = 0; rowY < rowsY; ++rowY) {
    vAgents newRow;
    mGrid.push_back(newRow);

    for (auto colX = 0; colX < colsX; ++colX) {
      mGrid[rowY].push_back(cAgent(rowY, colX));

      cAgent& agent = mGrid[rowY][colX];

      if (((rand() % 100) * 0.01) <= config.lifeDensity) {
        agent.mStatusIs = true; // make alive
      }
    }
  }
}

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

      switch (agent.CountAdjacentAgents()){
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

int CountAdjacentAgents(){
  int cnt = 0;
  for (auto dy : {-1, 0, 1}) {
    for (auto dx : {-1, 0, 1}) {
      // wraps around matrix
      int posY = ((mPosY + dy) + mGrid.size()) % mGrid.size();
      int posX = ((mPosX + dx) + mGrid[mPosY].size()) % mGrid[mPosY].size();

      cAgent& adjacentAgent = agents[posY][posX];

      if ((dy != 0 || dx != 0) && adjacentAgent.mStatusIs == true) {
        cnt += 1;
      }
    }
  }
  return cnt;
};

void cGameOfLife::UpdateGameOfLife(){
  day += 1;

  // remember last 3 agents states for game end condition
  mGridState2 = mGridState1;
  mGridState1 = mGridState0;
  mGridState0.clear();

  // UPDATE AGENTS
  //---------------------------------
  for (auto& row : mGrid) {
    for (auto& agent : row) {
      if (agent.mStatusChanging == true) {
        agent.PingAdjacentAgents(mGrid);

        if (agent.GetStatusNext() == true) {
          agent.mStatusIs = true;

          if (config.decayAgents == true) {
            agent.mVitality = 4;
          }
        } else {
          agent.mStatusIs = false;
        }
      }

      if (agent.mStatusIs == true) {
        agentsState0.push_back(true);
      } else {
        agentsState0.push_back(false);
        agent.DecreaseVitality();
      }
    }
  }
};

vvAgents cGameOfLife::GetNextGameState(){ return mGrid; };