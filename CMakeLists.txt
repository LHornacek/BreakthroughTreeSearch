cmake_minimum_required(VERSION 3.23)
project(BreakthroughTreeSearch)

set(CMAKE_CXX_STANDARD 20)

add_executable(BreakthroughTreeSearch Main.cpp Game.cpp Game.hpp Strategy.cpp Strategy.hpp ManualStrategy.cpp ManualStrategy.hpp MinimaxStrategy.cpp MinimaxStrategy.hpp RandomStrategy.cpp RandomStrategy.hpp StructDefinitions.hpp)
