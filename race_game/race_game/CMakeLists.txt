cmake_minimum_required(VERSION 3.22.0)
project(race)

set (SOURCES 
  AirVehicle.cpp
  FastCamel.cpp
  SurfaceType.cpp
  Eagle.cpp
  MagicCarpet.cpp
  AllTerrainBoots.cpp
  Camel.cpp
  Game.cpp
  UserDialog.cpp
  Exceptions.cpp
  Player.cpp
  Broom.cpp
  Centaur.cpp
  LandVehicle.cpp
  Vehicle.cpp
)

set (HEADERS 
  Broom.hpp
  Centaur.hpp
  LandVehicle.hpp
  Vehicle.hpp
  AirVehicle.hpp
  FastCamel.hpp
  SurfaceType.hpp
  Eagle.hpp
  MagicCarpet.hpp
  AllTerrainBoots.hpp
  Camel.hpp
  Game.hpp
  UserDialog.hpp
  Exceptions.hpp
  Player.hpp
)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(RaceLib SHARED ${SOURCES} ${HEADERS})
add_executable(race main.cpp)
target_compile_definitions(RaceLib PRIVATE RACELIB_EXPORTS)
target_link_libraries(race RaceLib)
