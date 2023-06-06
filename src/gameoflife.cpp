#include "gameoflife.h"

void cGameOfLife::InitialiseGameOfLife() {
  // INITIALISE AGENTS
  //---------------------------------
  for (auto rowY = 0; rowY < rowsY; ++rowY) {
    std::vector<cAgent> row;
    grid.push_back(row);

    for (auto colX = 0; colX < colsX; ++colX) {
      grid[rowY].push_back(cAgent(rowY, colX));

      cAgent& agent = grid[rowY][colX];

      if (((rand() % 100) * 0.01) <= config.lifeDensity) {
        agent.mStatusIs = true; // make alive
      }
    }
  }
}