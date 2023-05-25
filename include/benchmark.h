#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <string>
#include <vector>

extern bool bmkFound;

class bmk{
public:

  bmk(std::string &ID);

  std::string mID;
  std::chrono::steady_clock::time_point mStartTime;
  std::chrono::steady_clock::time_point mStopTime;
  std::chrono::duration<double> mTime;

  std::chrono::duration<double> mFastest;
  std::chrono::duration<double> mSlowest;
  double mPrecision;
  std::chrono::duration<double> mAvgTime;
}

extern std::vector<bmk> bmks;

void startBmk(std::vector<bmk> &bmks, std::string &ID);
void stopBmk(std::vector<bmk> &bmks, std::string &ID);

#endif

/*
#include <string>
#include <iostream>
#include <vector>
#include <chrono>


class cBmk{
public:

  cBmk(std::string ID);

  std::string mID = "";
  std::chrono::steady_clock::time_point mStartTime;
  std::chrono::steady_clock::time_point mStopTime;
  std::chrono::duration<double> mTime;

  std::chrono::duration<double> mFastest;
  std::chrono::duration<double> mSlowest;
  double mPrecision;
  std::chrono::duration<double> mAvgTime;
};

std::vector<cBmk> bmks;


bool bmkFound = false;

cBmk::cBmk(std::string ID) {
  mID = ID;
  mPrecision = 0;
};

void startBmk(std::vector<cBmk> &bmks, std::string ID) {
  bmkFound = false;
bmks.push_back(cBmk("null"));
  for (auto &bmk : bmks) {
    if (bmk.mID == ID) {
      bmkFound = true;
      break;
    } 

    if (bmkFound == false) {
      bmks.push_back(cBmk(ID));
    }
  }

  for (auto &bmk : bmks) {
    if (bmk.mID == ID) {
      bmk.mStartTime = std::chrono::steady_clock::now();
    }
  }
}

void stopBmk(std::vector<cBmk> &bmks, std::string ID) {
  for (auto bmk : bmks) {
    if (bmk.mID == ID) {
      bmk.mStopTime = std::chrono::steady_clock::now();
      bmk.mTime = std::chrono::duration_cast<std::chrono::nanoseconds>(bmk.mStopTime - bmk.mStartTime);
      if (bmk.mTime > bmk.mSlowest) {
        bmk.mSlowest = bmk.mTime;
      }
      
      if (bmk.mTime < bmk.mFastest) {
        bmk.mFastest = bmk.mTime;
      }

      bmk.mPrecision += 1;
      bmk.mAvgTime = (bmk.mAvgTime + bmk.mTime) / bmk.mPrecision;
      //std::cout << 'Last | Slowest | Avg | Fastest\n';
      std::cout << bmk.mID << ": " << bmk.mTime.count() << " | " << bmk.mSlowest.count() << " | " << bmk.mAvgTime.count() << " | " << bmk.mFastest.count() << '\n';
    break;
    }
  }
}

    int main()
    {
        for (int i = 0; i < 100; ++i) {
            
        startBmk(bmks, "One");
        stopBmk(bmks, "One");
        startBmk(bmks, "Two");
        stopBmk(bmks, "Two");
        }
        
        return 0;
    }
*/