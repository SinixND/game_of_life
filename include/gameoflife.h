#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <vector>

#include "agents.h"

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

    std::vector<std::vector<cAgent>> grid_;

    int CountAdjacentAgents(cAgent& agent);
    void ProcessGameOfLife();

    void NotifyAdjacentAgents(cAgent& agent);
    void UpdateGameOfLife();

public:
    int GetDay();
    std::vector<std::vector<cAgent>>& GetGrid();
};

#endif