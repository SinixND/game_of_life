#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <vector>

#include "agents.h"

typedef std::vector<std::vector<cAgent>> vvAgents;

class cGameOfLife {
public:
  cGameOfLife(int rowsY, int colsX);

  std::vector<bool> mGridState;
  std::vector<std::vector<bool>> mGridStates;

  void EvolveGrid();
  void ResetGameOfLife();

private:
  int mRowsY;
  int mColsX;
  int mDay;

  vvAgents mGrid;

  int CountAdjacentAgents(cAgent& agent);
  void ProcessGameOfLife();

  void PingAdjacentAgents(cAgent& agent);
  void UpdateGameOfLife();

public:
  int GetDay();
  vvAgents& GetGrid();
};

#endif