#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <vector>

#include "agents.h"

typedef std::vector<std::vector<cAgent>> vvAgents;

class cGameOfLife {
public:
  cGameOfLife(int rowsY, int colsX);

private:
  vvAgents mGrid;

  int mRowsY;
  int mColsX;

public:
  void InitializeGameOfLife();
  void ProcessGameOfLife();
  void UpdateGameOfLife();
  vvAgents GetGameState();
};

#endif