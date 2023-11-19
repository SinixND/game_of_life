// sndBenchmark.h

#ifndef SNDBENCHMARK_H
#define SNDBENCHMARK_H

#define ACTIVATE_BENCHMARKING

#include <chrono>
typedef std::chrono::steady_clock::time_point chrono_timePoint;
typedef std::chrono::duration<double> chrono_timeDurationDouble;
#include <string>
#include <vector>

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

#endif // SNDBENCHMARK_H

// sndBenchmark.cpp
#if defined(BENCHMARK_IMPLEMENTATION)

#include <iostream>

    std::vector<Benchmark> benchmarks = {Benchmark("NULL")};

    Benchmark::Benchmark(std::string id)
        : id_{id}
        , iterations_{0}
    {
    }

    void StartBenchmark(std::string id)
    {
#ifdef ACTIVATE_BENCHMARKING
        for (auto& benchmark : benchmarks)
        {
            if (benchmark.id_ == id)
            {
                benchmark.startTime_ = std::chrono::steady_clock::now();
                return;
            }
        }

        benchmarks.push_back(Benchmark(id));
        benchmarks.back().startTime_ = std::chrono::steady_clock::now();
#endif
    }

    void StopBenchmark(std::string id)
    {
#ifdef ACTIVATE_BENCHMARKING
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
#endif
    }

    void ShowBenchmarks()
    {
#ifdef ACTIVATE_BENCHMARKING
        for (auto& benchmark : benchmarks)
        {
            if (benchmark.id_ == "NULL")
            {
                continue;
            }

            std::cout << benchmark.id_ << " (Lst|Avg|Itr): " << benchmark.latestTime_.count() << " ns | " << benchmark.avgTime_.count() << " ns | " << benchmark.iterations_ << "\n";
        }
        if (benchmarks.size() > 1)
            std::cout << "\n";
#endif
    }
} // namespace sxd

#endif