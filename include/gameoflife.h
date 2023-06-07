#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <vector>

#include "agents.h"

typedef std::vector<std::vector<cAgent>> vvAgents;

class cGameOfLife {
public:
  cGameOfLife(int rowsY, int colsX);

private:
  int mRowsY;
  int mColsX;
  int mDay;

  std::vector<bool> mGridState;
  std::vector<std::vector<bool>> mGridStates;

  vvAgents mGrid;

  void InitializeGameOfLife();

  void ProcessGameOfLife();
  int CountAdjacentAgents(cAgent agent);

  void UpdateGameOfLife();

public:
  int GetDay();
  vvAgents GetGameState();
  vvAgents GetNextGameState();
};

#endif