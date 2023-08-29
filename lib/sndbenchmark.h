// sndbenchmark.h

#ifndef SNDBENCHMARK_H
#define SNDBENCHMARK_H

#include <chrono>
typedef std::chrono::steady_clock::time_point chrono_timePoint;
typedef std::chrono::duration<double> chrono_timeDurationDouble;
#include <string>
#include <vector>

class Benchmark
{
public:
    Benchmark(std::string id);

    std::string id_ = "";
    chrono_timePoint startTime_;
    chrono_timePoint stopTime_;
    chrono_timeDurationDouble latestTime_;

    double iterations_;
    chrono_timeDurationDouble avgTime_;
};

extern std::vector<Benchmark> benchmarks;

void StartBenchmark(std::string id);
void StopBenchmark(std::string id);
Benchmark& selectBenchmark(std::string id);
void ShowBenchmarks();


// sndbenchmark.cpp

#include <iostream>

std::vector<Benchmark> benchmarks = {Benchmark("NULL")};

Benchmark::Benchmark(std::string id)
    : id_(id)
    , iterations_(0)
{
}

void StartBenchmark(std::string id)
{
    benchmarks.push_back(Benchmark(id));

    benchmarks.back().startTime_ = std::chrono::steady_clock::now();
}


void StopBenchmark(std::string id)
{
    for (auto& benchmark : benchmarks)
    {
        if (benchmark.id_ != id)
        {
            continue;
        }

        benchmark.stopTime_ = std::chrono::steady_clock::now();
        benchmark.latestTime_ = std::chrono::duration_cast<std::chrono::nanoseconds>(benchmark.stopTime_ - benchmark.startTime_);

        benchmark.iterations_ += 1;
        // new_average = (old_average * (n-1) + new_value) / n
        benchmark.avgTime_ = (benchmark.avgTime_ * (benchmark.iterations_ - 1) + benchmark.latestTime_) / benchmark.iterations_;
        return;
    }
}

void ShowBenchmarks()
{
    for (auto& benchmark : benchmarks)
    {
        if (benchmark.id_ == "NULL")
        {
            continue;
        }

        std::cout << benchmark.id_ << " (Lst|Avg|Itr): " << benchmark.latestTime_.count() << " ns | " << benchmark.avgTime_.count() << " ns | " << benchmark.iterations_ << "\n";
    }
    std::cout << "\n";
}

#endif
