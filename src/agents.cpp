#include "agents.h"

#include <vector>

cAgent::cAgent()
{
  mStatusIs = false;
  mStatusNext = false;
  mStatusChanging = true;
  mAdjacentsActive = 0;
  mVitality = 0;
};

cAgent::~cAgent(){};

void cAgent::setStatusIs(bool arg)
{
  mStatusIs = arg;
  //if (arg)
  //{
    //mVitality = 5;
  //}
};

bool cAgent::getStatusIs()
{
  return mStatusIs;
};

void cAgent::setStatusNext(bool arg)
{
  mStatusNext = arg;
};

bool cAgent::getStatusNext()
{
  return mStatusNext;
};

void cAgent::setStatusChanging( bool arg )
{
  mStatusChanging = arg;
};

bool cAgent::getStatusChanging()
{
  return mStatusChanging;
};

void cAgent::setVitality( int arg )
{
  mVitality = arg;
};

int cAgent::getVitality()
{
  return mVitality;
};

void cAgent::decreaseVitality()
{
  if (mVitality > 0)
  {
    mVitality -= 1;
  }
};

int countAdjacents(std::vector<std::vector<cAgent>> &agents, const int colX, const int rowY)
{
  int cnt = 0;
  for (int dx : {-1, 0, 1})
  {
    for (int dy : {-1, 0, 1})
    {
      int posX = ((colX + dx) + agents[rowY].size()) % agents[rowY].size();
      int posY = ((rowY + dy) + agents.size()) % agents.size();
      if (dx != 0 || dy != 0)
      {
        // if (agents[y][x].getStatusIs() == true) { agents[posY][posX].setAdjacents(getAdjacents() + 1) };
        if (agents[posY][posX].getStatusIs() == true)
        {
          cnt += 1;
        }
      }
    }
  }
  return cnt;
};