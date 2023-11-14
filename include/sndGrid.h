#ifndef GRID_H
#define GRID_H

#include <vector>
#include "sndAgent.h"

class Grid
{
public:
    Grid();
    Grid(int rowsY, int colsX);

    std::vector<bool> gridState_;
    std::vector<std::vector<bool>> gridStates_;

    void Reset();
    void Evolve();

    void PrepareNext(int begin, int end);
    int CountAdjacentAgents(Agent& agent);

    void Clear();

    void NotifyAdjacentAgents(Agent& agent);
    void Update();

    void SetGridSize(int colsX, int rowsY);

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
