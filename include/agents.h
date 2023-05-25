#ifndef AGENTS_H
#define AGENTS_H

#include <vector>

class cAgent {
public:
  cAgent(int rowY, int colX);
  ~cAgent();

private:
  int mPosY;
  int mPosX;
  bool mStatusIs;
  bool mStatusNext;
  bool mStatusChanging;
  bool mCheckStatus;
  int mAdjacentsActive;
  int mVitality;

public:
  void setStatusIs( bool arg );
  bool getStatusIs();

  void setStatusNext( bool arg );
  bool getStatusNext();

  void setStatusChanging( bool arg );
  bool getStatusChanging();

  void setCheckStatus( bool arg );
  bool getCheckStatus();

  void setVitality( int arg );
  int getVitality();
  void decreaseVitality();

  int countAdjacents( std::vector<std::vector<cAgent>> &agents);
  void pingAdjacents(std::vector<std::vector<cAgent>> &agents);
};

#endif