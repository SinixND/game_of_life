#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <chrono>
typedef std::chrono::steady_clock::time_point chrono_timePoint;
typedef std::chrono::duration<double> chrono_timeDurationDouble;
#include <string>
#include <vector>

extern bool benchmarkFound;

class cBenchmark{
public:

  cBenchmark(std::string ID);

  std::string mID = "";
  chrono_timePoint mStartTime;
  chrono_timePoint mStopTime;
  chrono_timeDurationDouble mLatestTime;

  double mIterations;
  chrono_timeDurationDouble mAvgTime;
};


extern std::vector<cBenchmark> benchmarks;

void StartBenchmark(std::string ID);
void StopBenchmark(std::string ID);
void ShowBenchmark();

#endif
