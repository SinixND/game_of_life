#ifndef AGENTS_H
#define AGENTS_H

#include <vector>

class cAgent
{
public:
  // constructor
  cAgent();
  // destructor
  ~cAgent();

  void setStatusIs( bool arg );
  bool getStatusIs();

  void setStatusNext( bool arg );
  bool getStatusNext();

  void setStatusChanging( bool arg );
  bool getStatusChanging();

  void setVitality( int arg );
  int getVitality();
  void decreaseVitality();

private:
  bool mStatusIs;
  bool mStatusNext;
  bool mStatusChanging;
  int mAdjacentsActive;
  int mVitality;
};

int countAdjacents( std::vector<std::vector<cAgent>> &environment, const int colX, const int rowY );

#endif