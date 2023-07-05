#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <chrono>
typedef std::chrono::steady_clock::time_point chrono_timePoint;
typedef std::chrono::duration<double> chrono_timeDurationDouble;
#include <string>
#include <vector>

class cBenchmark
{
public:
    cBenchmark(std::string id);

    std::string id_ = "";
    chrono_timePoint startTime_;
    chrono_timePoint stopTime_;
    chrono_timeDurationDouble latestTime_;

    double iterations_;
    chrono_timeDurationDouble avgTime_;
};

extern std::vector<cBenchmark> benchmarks;

void StartBenchmark(std::string id);
void StopBenchmark(std::string id);
cBenchmark& selectBenchmark(std::string id);
void ShowBenchmarks();

#endif
