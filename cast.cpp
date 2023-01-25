#include <boost/numeric/conversion/cast.hpp>
#include <benchmark/benchmark.h>

static void BM_NumericCast(benchmark::State& state) {
  uint8_t a;
  for (auto _ : state) {
    benchmark::DoNotOptimize(a = boost::numeric_cast<uint8_t>(100));
  }
}
BENCHMARK(BM_NumericCast);

static void BM_NumericCastOverflow(benchmark::State& state) {
  uint8_t a;
  for (auto _ : state) {
    try {
      benchmark::DoNotOptimize(a = boost::numeric_cast<uint8_t>(1000));
    } catch(...){}
  }
}
BENCHMARK(BM_NumericCastOverflow);

static void BM_StaticCast(benchmark::State& state) {
  uint8_t a;
  for (auto _ : state) {
    benchmark::DoNotOptimize(a = static_cast<uint8_t>(100));
  }
}
BENCHMARK(BM_StaticCast);

BENCHMARK_MAIN();
