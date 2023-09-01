#ifndef GRID_H
#define GRID_H

#include <vector>

#include "sndAgent.h"

class Grid
{
public:
    Grid(int rowsY, int colsX);

    std::vector<bool> gridState_;
    std::vector<std::vector<bool>> gridStates_;

    void Evolve();
    void Reset();
    void Clear();

    int CountAdjacentAgents(Agent& agent);
    void PrepareNext();

    void NotifyAdjacentAgents(Agent& agent);
    void Update();

    int GetDay();
    void SetDay(int day);
    std::vector<std::vector<Agent>>& GetGrid();

private:
    int rowsY_;
    int colsX_;
    int day_;

    std::vector<std::vector<Agent>> grid_;
};

#endif