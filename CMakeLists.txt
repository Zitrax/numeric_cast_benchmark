project(Cast CXX)

cmake_minimum_required(VERSION 3.25)

find_package(benchmark CONFIG REQUIRED)
find_package(Boost REQUIRED)

add_executable(cast cast.cpp)

target_link_libraries(cast PRIVATE Boost::boost)
target_link_libraries(cast PRIVATE benchmark::benchmark benchmark::benchmark_main)
