#include "benchmark.h"

#include <string>
#include <vector>
#include <chrono>

bool bmkFound = false;

bmk::bmk(std::string &ID) {
  mID = ID;
  mPrecision = 0;
}

void startBmk(std::vector<bmk> &bmks, std::string &ID) {
  bmkFound = false;

  for (auto &bmk : bmks) {
    if (bmk.mID == ID) {
      bmkFound = true;
      break;
    } 

    if (bmkFound == false) {
      bmks.push_back(bmk(ID));
    }
  }

  for (auto &bmk : bmks) {
    if (bmk.mID == ID) {
      bmk.mStartTime = std::chrono::steady_clock::now();
    }
  }
}

void stopBmk(std::vector<bmk> &bmks, std::string &ID) {
  for (auto &bmk : bmks) {
    if (bmk.mID == ID) {
      std::chrono::steady_clock::time_point bmk.mStopTime = std::chrono::steady_clock::now();
      std::chrono::duration<double> bmk.mTime = std::chrono::duration_cast<std::chrono::milliseconds>(bmk.mStopTime - bmk.mStartTime);
      if (bmk.mTime > bmk.mSlowest) {
        bmk.mSlowest = bmk.mTime;
      }
      
      if (bmk.mTime < bmk.mFastest) {
        bmk.mFastest = bmk.mTime;
      }

      bmk.mPrecision += 1;
      bmk.mAvgTime = (bmk.mAvgTime.count() + bmk.mTime.count()) / bmk.mPrecision;
      //std::cout << 'Last | Slowest | Avg | Fastest\n';
      std::cout << bmk.mTime.count() << bmk.mSlowest.count() << bmk.mAvgTime.count() << bmk.mFastest.count() << '\n';
    break;
    }
  }
}