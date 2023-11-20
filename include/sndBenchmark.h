// sndBenchmark.h

#ifndef SNDBENCHMARK_H_202311201531
#define SNDBENCHMARK_H_202311201531

#include <chrono>
#include <string>
#include <vector>

typedef std::chrono::steady_clock::time_point chrono_timePoint;
typedef std::chrono::duration<double> chrono_timeDurationDouble;

namespace sxd
{
    class Benchmark
    {
    public:
        Benchmark(std::string id);

        std::string id_;
        chrono_timePoint startTime_;
        chrono_timePoint stopTime_;
        chrono_timeDurationDouble latestTime_;

        double iterations_;
        chrono_timeDurationDouble avgTime_;
    };

    extern std::vector<Benchmark> benchmarks;

    void StartBenchmark(std::string id);
    void StopBenchmark(std::string id);
    void ShowBenchmarks();
} // namespace sxd

#endif // SNDBENCHMARK_H_202311201531

// sndBenchmark.cpp
#if defined(BENCHMARK_IMPLEMENTATION)

#include <iostream>

std::vector<sxd::Benchmark> sxd::benchmarks = {sxd::Benchmark("NULL")};

sxd::Benchmark::Benchmark(std::string id)
    : id_{id}
    , iterations_{0}
{
}

void sxd::StartBenchmark(std::string id)
{
    for (auto& benchmark : benchmarks)
    {
        if (benchmark.id_ == id)
        {
            benchmark.startTime_ = std::chrono::steady_clock::now();
            return;
        }
    }

    benchmarks.push_back(sxd::Benchmark(id));
    benchmarks.back().startTime_ = std::chrono::steady_clock::now();
}

void sxd::StopBenchmark(std::string id)
{
    for (auto& benchmark : benchmarks)
    {
        if (benchmark.id_ != id) { continue; }

        benchmark.stopTime_ = std::chrono::steady_clock::now();
        benchmark.latestTime_ = std::chrono::duration_cast<std::chrono::nanoseconds>(benchmark.stopTime_ - benchmark.startTime_);

        benchmark.iterations_ += 1;
        benchmark.avgTime_ = (benchmark.avgTime_ * (benchmark.iterations_ - 1) + benchmark.latestTime_) / benchmark.iterations_;
        return;
    }
}

void sxd::ShowBenchmarks()
{
    for (auto& benchmark : benchmarks)
    {
        if (benchmark.id_ == "NULL") { continue; }

        std::cout << benchmark.id_ << " (Lst|Avg|Itr): " << benchmark.latestTime_.count() << " ns | " << benchmark.avgTime_.count() << " ns | " << benchmark.iterations_ << "\n";
    }
    if (benchmarks.size() > 1)
        std::cout << "\n";
}

#endif