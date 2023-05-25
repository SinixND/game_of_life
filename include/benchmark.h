#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <chrono>
#include <string>
#include <vector>

extern bool benchmarkFound;

class cBenchmark{
public:

  cBenchmark(std::string ID);

  std::string mID = "";
  std::chrono::steady_clock::time_point mStartTime;
  std::chrono::steady_clock::time_point mStopTime;
  std::chrono::duration<double> mLatestTime;

  double mIterations;
  std::chrono::duration<double> mAvgTime;
};


extern std::vector<cBenchmark> benchmarks;

void benchmarkStart(std::string ID);
void benchmarkStop(std::string ID);
void benchmarkShow();

#endif