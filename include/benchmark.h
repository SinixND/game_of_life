#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <chrono>
typedef std::chrono::steady_clock::time_point td_timePoint;
typedef std::chrono::duration<double> td_dblDuration;
#include <string>
#include <vector>

extern bool benchmarkFound;

class cBenchmark{
public:

  cBenchmark(std::string ID);

  std::string mID = "";
  td_timePoint mStartTime;
  td_timePoint mStopTime;
  td_dblDuration mLatestTime;

  double mIterations;
  td_dblDuration mAvgTime;
};


extern std::vector<cBenchmark> benchmarks;

void benchmarkStart(std::string ID);
void benchmarkStop(std::string ID);
void benchmarkShow();

#endif
