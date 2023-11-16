#include "sndGrid.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <thread>
#include <time.h>

#include "sndAgent.h"
#include "sndConfigs.h" // provide object "config" for configurable parameters
#include "sndBenchmark.h"

Grid::Grid(){};

Grid::Grid(int rowsY, int colsX)
    : rowsY_ {rowsY}
      , colsX_ {colsX}
{
    Reset();
}

std::vector<std::vector<int>> debugGrid =
{
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0},
    {0,0,1,0,0,0,0,1,1,1,0,0,1,1,0,0,0},
    {0,0,1,0,0,0,1,1,1,0,0,0,0,0,1,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0},
    {0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0},
    {0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0},
    {0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0},
    {0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0},
    {0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0},
    {0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

void Grid::Reset()
{
    srand(time(0));
    day_ = 0;
    grid_.clear();
    previousGrid_.clear();

    // INITIALIZE GRID OF AGENTS
    //---------------------------------
    if (config.debugMode == true)
    {
        int debugRowsY = debugGrid.size();
        int debugColsX = debugGrid[0].size();

        for (auto rowY = 0; rowY < rowsY_; ++rowY)
        {
            std::vector<Agent> newRow;
            grid_.push_back(newRow);

            for (auto colX = 0; colX < colsX_; ++colX)
            {
                // add new agent to grid
                grid_[rowY].push_back(Agent(rowY, colX));
                Agent& agent = grid_[rowY][colX];

                if (rowY < (debugRowsY - 1) && colX < (debugColsX - 1))
                {
                    agent.SetStatusCurrent(debugGrid[rowY][colX]);
                }
                else{
                    agent.SetStatusCurrent(false);
                }            
            }
        }
    }
    else
    {
        for (auto rowY = 0; rowY < rowsY_; ++rowY)
        {
            std::vector<Agent> newRow;
            grid_.push_back(newRow);

            for (auto colX = 0; colX < colsX_; ++colX)
            {
                // add new agent to grid
                grid_[rowY].push_back(Agent(rowY, colX));
                Agent& agent = grid_[rowY][colX];

                // randomize initial agent state
                if (((rand() % 100) * 0.01) <= (config.initialLifeDensity / (float)100.0))
                {
                    agent.SetStatusCurrent(true);
                }
            }
        }
    }
}

void Grid::Evolve()
{
    previousGrid_ = grid_;

    if (config.multiThread == true)
    {
        int nThreads = std::thread::hardware_concurrency();
        std::vector<std::thread> threads;
        int gridRows = grid_.size();

        int threadRange = gridRows / nThreads; // amount of rows processed by one thread
        int threadRangeExcess = gridRows % nThreads; // remaing rows

        int i = 0;
        int threadRangeBegin = 0; // including
        int threadRangeEnd = threadRange; // excluding

        while (i < nThreads)
        {
            if (i < (threadRangeExcess + 1)) ++threadRangeEnd; // distribute excessive rows onto first threads

            threads.push_back(std::thread(&Grid::PrepareNextMT, this, threadRangeBegin, threadRangeEnd));

            threadRangeBegin = threadRangeEnd;
            threadRangeEnd += threadRange;
            ++i;
        }

        for (auto& th : threads)
        {
            th.join();
        }
        threads.clear();
    }
    else
    {
        PrepareNext();
    }

    Update();
}

void Grid::PrepareNext()
{
    // DETERMINE NEXT AGENTS STATE
    //---------------------------------
    for (auto& row : grid_)
    {
        for (auto& agent : row)
        {
            // Default ruleset:
            // Adjacent alive agents count = 2 -> remain.
            // Adjacent alive agent count = 3 -> alive.
            // All other die.

            // skip iteration if statusOutdated is false
            if (agent.GetStatusOutdated() == false)
            {
                continue;
            }

            agent.SetStatusOutdated(false);

            switch (CountAdjacentAgents(agent))
            {
                case 2:
                    agent.SetStatusNext(agent.GetStatusCurrent());
                    break;

                case 3:
                    agent.SetStatusNext(true);
                    break;

                default:
                    agent.SetStatusNext(false);
                    break;
            }
        }
    }
}

void Grid::PrepareNextMT(int threadRangeBegin, int threadRangeEnd)
{
    // DETERMINE NEXT AGENTS STATE
    //---------------------------------
    for (int i = threadRangeBegin; i < threadRangeEnd; ++i)
        //for (auto& row : grid_)
    {
        auto& row = grid_[i];
        for (auto& agent : row)
        {
            // Default ruleset:
            // Adjacent alive agents count = 2 -> remain.
            // Adjacent alive agent count = 3 -> alive.
            // All other die.

            switch (CountAdjacentAgents(agent))
            {
                case 2:
                    agent.SetStatusNext(agent.GetStatusCurrent());
                    break;

                case 3:
                    agent.SetStatusNext(true);
                    break;

                default:
                    agent.SetStatusNext(false);
                    break;
            }
        }
    }
}

int Grid::CountAdjacentAgents(Agent& agent)
{
    int cnt = 0;
    for (auto dy : {-1, 0, 1})
    {
        for (auto dx : {-1, 0, 1})
        {
            // set adjacent position, wrapping around matrix
            int posY = ((agent.GetRowY() + dy) + grid_.size()) % grid_.size();
            int posX = ((agent.GetColX() + dx) + grid_[posY].size()) % grid_[posY].size();

            Agent& adjacentAgent = grid_[posY][posX];

            if ((dy != 0 || dx != 0) && adjacentAgent.GetStatusCurrent() == true)
            {
                cnt += 1;
            }
        }
    }
    return cnt;
}

void Grid::Clear()
{
    for (auto& row : grid_)
    {
        for (auto& agent : row)
        {
            agent.SetStatusCurrent(false);
            agent.SetStatusNext(false);
            agent.SetStatusOutdated(true);
            agent.EreaseVitality();
        }
    }
}

void Grid::Update()
{
    day_ += 1;

    // UPDATE AGENTS IN GRID
    //---------------------------------
    for (auto& row : grid_)
    {
        for (auto& agent : row)
        {
            if (agent.GetStatusCurrent() != agent.GetStatusNext() && config.multiThread == false)
            {
                NotifyAdjacentAgents(agent);
            }

            if (agent.GetStatusNext() == true)
            {
                agent.SetStatusCurrent(true);

                if (config.fadingAgents == true)
                {
                    agent.RefreshVitality();
                }
            }
            else
            {
                agent.SetStatusCurrent(false);
                agent.DecreaseVitality();
            }
        }
    }
}

void Grid::NotifyAdjacentAgents(Agent& agent)
{
    for (auto dx : {-1, 0, 1})
    {
        for (auto dy : {-1, 0, 1})
        {
            // wraps around matrix
            int posY = ((agent.GetRowY() + dy) + grid_.size()) % grid_.size();
            int posX = ((agent.GetColX() + dx) + grid_[posY].size()) % grid_[posY].size();

            Agent& adjacentAgent = grid_[posY][posX];
            adjacentAgent.SetStatusOutdated(true);
        }
    }
}

void Grid::SetGridSize(int colsX, int rowsY)
{
    colsX_ = colsX;
    rowsY_ = rowsY;
    Reset();
}

int Grid::GetDay()
{
    return day_;
}

void Grid::SetDay(int day)
{
    day_ = day;
}

std::vector<std::vector<Agent>>& Grid::GetGrid()
{
    return grid_;
}

void Grid::SetGrid(std::vector<std::vector<Agent>> grid)
{
    grid_ = grid;
}

std::vector<std::vector<Agent>> Grid::GetPreviousGrid()
{
    return previousGrid_;
}

void Grid::SetPreviousGrid(std::vector<std::vector<Agent>> grid)
{
    previousGrid_ = grid;
}
