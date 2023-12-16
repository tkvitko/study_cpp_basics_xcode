cmake_minimum_required(VERSION 3.22.0)
project(race_game)
FILE(GLOB Sources *.cpp)
add_executable(race_game ${Sources})
