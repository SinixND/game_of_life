#include "sndGrid.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <thread>
#include <time.h>
#include <cmath>
#include "sndAgent.h"
#include "sndConfigs.h" // provide object "config" for configurable parameters

Grid::Grid(){};

Grid::Grid(int rowsY, int colsX)
    : rowsY_(rowsY)
    , colsX_(colsX)
{
    Reset();
}

void Grid::Reset()
{
    srand(time(0));
    day_ = 0;
    grid_.clear();
    gridState_.clear();
    gridStates_.clear();

    // INITIALIZE GRID OF AGENTS
    //---------------------------------
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
                agent.SetStatusCurrent(true); // make alive
                gridState_.push_back(true);
            }
            else
            {
                gridState_.push_back(false);
            }
        }
    }
    gridStates_.push_back(gridState_);
    gridState_.clear();
}

void Grid::Evolve()
{

    if (config.multiThread == true)
    {
        int nThreads = std::thread::hardware_concurrency();
        std::vector<std::thread> threads;
        int gridRows = grid_.size();
        float interval = gridRows / static_cast<float>(nThreads);

        for (int i = 0; i < nThreads; ++i)
        {
            int begin = round(i * interval);
            int end = round((i + 1) * interval) - 1;
            if (end > gridRows) end = gridRows;
            std::thread thread(&Grid::PrepareNextMT, this, begin, end);
            threads.push_back(std::move(thread));
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
            // Default Ruleset:
            // AdjacentAgent count = 2 -> remain.
            // AdjacentAgent count = 3 -> alive.
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

void Grid::PrepareNextMT(int begin, int end)
{
    // DETERMINE NEXT AGENTS STATE
    //---------------------------------
    for (int i = begin; i < end; ++i)
    //for (auto& row : grid_)
    {
        auto& row = grid_[i];
        for (auto& agent : row)
        {
            // Default Ruleset:
            // AdjacentAgent count = 2 -> remain.
            // AdjacentAgent count = 3 -> alive.
            // All other die.

            // skip iteration if statusOutdated is false
//            if (agent.GetStatusOutdated() == false)
//            {
//                continue;
//            }

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

            if (adjacentAgent.GetStatusCurrent() == true && (dy != 0 || dx != 0))
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
//            if (agent.GetStatusCurrent() != agent.GetStatusNext())
//            {
//                NotifyAdjacentAgents(agent);
//            }
//
            if (agent.GetStatusNext() == true)
            {
                agent.SetStatusCurrent(true);
                gridState_.push_back(true);

                if (config.fadingAgents == true)
                {
                    agent.RefreshVitality();
                }
            }
            else
            {
                agent.SetStatusCurrent(false);
                gridState_.push_back(false);
                agent.DecreaseVitality();
            }
        }
    }
    gridStates_.push_back(gridState_);
    gridState_.clear();
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
