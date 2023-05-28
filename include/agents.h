#ifndef AGENTS_H
#define AGENTS_H

#include <vector>

class cAgent {
private:
  int mPosY;
  int mPosX;

public:
  cAgent(int rowY, int colX);
  ~cAgent();

  bool mStatusIs;
  bool mStatusChanging;
  bool mCheckStatus;
  int mVitality;

  void decreaseVitality();

private:
  bool mStatusNext;
  int mAdjacentAgentsActive;

public:
  void setStatusNext( bool arg );
  bool getStatusNext();

  int countAdjacentAgents( std::vector<std::vector<cAgent>>& agents);
  void pingAdjacentAgents(std::vector<std::vector<cAgent>>& agents);
};

#endif