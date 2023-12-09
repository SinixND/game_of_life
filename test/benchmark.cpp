#include <benchmark/benchmark.h>

#include "Agent.h"
#include "Configs.h"
#include "Globals.h"
#include "Grid.h"
#include "Scenes.h"
#include "sxdLayout.h"
#define RAYGUI_IMPLEMENTATION // only define once
#include "external/raygui.h"

// BENCHMARKS
static void BM_Evolve(benchmark::State& state)
{
    // Setup
    Grid grid(10, 10);
    grid.Reset();

    // Benchmark
    for (auto _ : state)
    {
        grid.Evolve();
    }
}

// Register function as benchmark
BENCHMARK(BM_Evolve);

// Run benchmarks
BENCHMARK_MAIN();
