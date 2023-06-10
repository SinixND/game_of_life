#ifndef AGENTS_H
#define AGENTS_H

#include <vector>

class cAgent {
public:
  cAgent(int rowY, int colX);

  int mPosY;
  int mPosX;
  bool mStatusIs;
  bool mStatusChanging;
  bool mCheckStatus;
  int mVitality;

  void DecreaseVitality();

private:
  bool mStatusNext;
  int mAdjacentAgentsActive;

public:
  void SetStatusNext( bool arg );
  bool GetStatusNext();
};

#endif