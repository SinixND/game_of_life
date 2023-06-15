#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <vector>

#include "agents.h"

typedef std::vector<std::vector<cAgent>> vvAgents;

class cGameOfLife
{
public:
  cGameOfLife(int rowsY, int colsX);

  std::vector<bool> gridState_;
  std::vector<std::vector<bool>> gridStates_;

  void EvolveGrid();
  void ResetGameOfLife();

private:
  int rowsY_;
  int colsX_;
  int day_;

  vvAgents grid_;

  int CountAdjacentAgents(cAgent &agent);
  void ProcessGameOfLife();

  void PingAdjacentAgents(cAgent &agent);
  void UpdateGameOfLife();

public:
  int GetDay();
  vvAgents &GetGrid();
};

#endif