#include "gameoflife.h"

#include <vector>

#include "agents.h"
#include "configs.h" // provide object "config" for configurable parameters

typedef std::vector<cAgent> vAgents;
//typedef std::vector<std::vector<cAgent>> vvAgents;

cGameOfLife::cGameOfLife(int rowsY, int colsX){
  mRowsY = rowsY;
  mColsX = colsX;
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
  for (auto& row : agents) {
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

      switch (agent.CountAdjacentAgents(agents)){
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

void cGameOfLife::UpdateGameOfLife(){
  day += 1;

  // remember last 3 agents states for game end condition
  agentsState2 = agentsState1;
  agentsState1 = agentsState0;
  agentsState0.clear();

  // UPDATE AGENTS
  //---------------------------------
  for (auto& row : agents) {
    for (auto& agent : row) {
      if (agent.mStatusChanging == true) {
        agent.PingAdjacentAgents(agents);

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

vvAgents cGameOfLife::GetGameState(){
};