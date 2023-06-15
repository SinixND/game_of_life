#include "gameoflife.h"

#include <iostream>
#include <vector>
#include <cstdlib>

#include "configs.h" // provide object "config" for configurable parameters
#include "agents.h"

typedef std::vector<cAgent> vAgents;

cGameOfLife::cGameOfLife(int rowsY, int colsX)
  : rowsY_{rowsY}
  , colsX_{colsX}
{
  ResetGameOfLife();
};

void cGameOfLife::ResetGameOfLife() {
  day_ = 0;
  grid_.clear();
  gridState_.clear();
  gridStates_.clear();

  // INITIALIZE AGENTS
  //---------------------------------
  for (auto rowY = 0; rowY < rowsY_; ++rowY) {
    vAgents newRow;
    grid_.push_back(newRow);

    for (auto colX = 0; colX < colsX_; ++colX) {
      grid_[rowY].push_back(cAgent(rowY, colX));

      cAgent& agent = grid_[rowY][colX];

      if (((rand() % 100) * 0.01) <= config.lifeDensity) {
        agent.statusIs_ = true; // make alive
        gridState_.push_back(true);
      } else {
        gridState_.push_back(false);
      }
    }
  }
  gridStates_.push_back(gridState_);
  gridState_.clear();
}

int cGameOfLife::CountAdjacentAgents(cAgent& agent){
  int cnt = 0;
  for (auto dy : {-1, 0, 1}) {
    for (auto dx : {-1, 0, 1}) {
      // wraps around matrix
      int posY = ((agent.posY_ + dy) + grid_.size()) % grid_.size();
      int posX = ((agent.posX_ + dx) + grid_[posY].size()) % grid_[posY].size();

      cAgent& adjacentAgent = grid_[posY][posX];

      if ((dy != 0 || dx != 0) && adjacentAgent.statusIs_ == true) {
        cnt += 1;
      }
    }
  }
  return cnt;
};

void cGameOfLife::ProcessGameOfLife(){
  // DETERMINE NEXT AGENTS STATE
  //---------------------------------
  for (auto& row : grid_) {
    for (auto& agent : row) {
      // Default Ruleset:
      // AdjacentAgent count = 2 -> remain.
      // AdjacentAgent count = 3 -> alive.
      // All other die.

      if (agent.checkStatus_ == false)
      {
        continue;
      }
      agent.checkStatus_ = false;

      switch (CountAdjacentAgents(agent)){
      case 2:
        agent.SetStatusNext(agent.statusIs_);
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
      int posY = ((agent.posY_ + dy) + grid_.size()) % grid_.size();
      int posX = ((agent.posX_ + dx) + grid_[posY].size()) % grid_[posY].size();

      cAgent& adjacentAgent = grid_[posY][posX];
      adjacentAgent.checkStatus_ = true;
    }
  }
};

void cGameOfLife::UpdateGameOfLife(){
  day_ += 1;

  // UPDATE AGENTS
  //---------------------------------
  for (auto& row : grid_) {
    for (auto& agent : row) {
      if (agent.statusChanging_ == true) {
        PingAdjacentAgents(agent);

        if (agent.GetStatusNext() == true) {
          agent.statusIs_ = true;

          if (config.fadingAgents == true) {
            agent.vitality_ = 4;
          }
        } else {
          agent.statusIs_ = false;
        }
      }

      if (agent.statusIs_ == true) {
        gridState_.push_back(true);
      } else {
        gridState_.push_back(false);
        agent.DecreaseVitality();
      }
    }
  }
  gridStates_.push_back(gridState_);
  gridState_.clear();
};

void cGameOfLife::EvolveGrid(){
  ProcessGameOfLife();
  UpdateGameOfLife();
};


vvAgents& cGameOfLife::GetGrid(){ return grid_; };

int cGameOfLife::GetDay(){ return day_; };