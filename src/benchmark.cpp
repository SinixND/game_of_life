#include "benchmark.h"

#include <vector>
#include <string>
#include <chrono>
#include <iostream>

std::vector<cBenchmark> benchmarks = {cBenchmark("NULL")};
bool benchmarkFound = false;

cBenchmark::cBenchmark(std::string ID) {
  mID = ID;
  mIterations = 0;
}

void benchmarkStart(std::string ID) {
  benchmarkFound = false;

  for (auto& benchmark : benchmarks) {
    if (benchmark.mID == ID) {
      benchmarkFound = true;
      break;
    }
  }
  if (benchmarkFound == false) {
    benchmarks.push_back(cBenchmark(ID));
  }

  for (auto& benchmark : benchmarks) {
    if (benchmark.mID == ID) {
      benchmark.mStartTime = std::chrono::steady_clock::now();
      break;
    }
  }
}

void benchmarkStop(std::string ID) {
  for (auto& benchmark : benchmarks) {
    if (benchmark.mID == ID) {
      benchmark.mStopTime = std::chrono::steady_clock::now();
      benchmark.mLatestTime = std::chrono::duration_cast<std::chrono::nanoseconds>(benchmark.mStopTime - benchmark.mStartTime);

      benchmark.mIterations += 1;
      //new_average = (old_average * (n-1) + new_value) / n
      benchmark.mAvgTime = (benchmark.mAvgTime * (benchmark.mIterations - 1) + benchmark.mLatestTime) / benchmark.mIterations;
    break;
    }
  }
}

void benchmarkShow() {
  for (auto& benchmark : benchmarks) {
    if (benchmark.mID != "NULL") {
      std::cout << benchmark.mID << " (Lst|Avg|Itr): " << benchmark.mLatestTime.count() << " ns | " << benchmark.mAvgTime.count() << " ns | " << benchmark.mIterations << "\n";
    }
  }
  std::cout << "\n";
}
