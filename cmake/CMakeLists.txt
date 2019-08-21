cmake_minimum_required(VERSION 3.7)
project(trial.net CXX)

find_package(Boost 1.55.0 REQUIRED QUIET COMPONENTS system)

add_library(trial-net INTERFACE)
target_include_directories(trial-net INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/../include" ${Boost_INCLUDE_DIR})
target_link_libraries(trial-net INTERFACE ${Boost_SYSTEM_LIBRARY})
