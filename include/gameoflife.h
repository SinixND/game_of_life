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

  vvAgents mGrid;

  void InitializeGameOfLife();

  void ProcessGameOfLife();
  int CountAdjacentAgents();

  void UpdateGameOfLife();

public:
  vvAgents GetGameState();
  vvAgents GetNextGameState();
};

#endif