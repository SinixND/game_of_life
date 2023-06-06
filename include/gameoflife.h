#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <vector>

#include "agents.h"

class cGameOfLife {
public:
  cGameOfLife();

  std::vector<std::vector<cAgent>> grid;
  int rowsY;
  int colsX;


private:

public:
  void InitialiseGameOfLife();
  void ProcessGameOfLife();
  void UpdateGameOfLife();
};

#endif