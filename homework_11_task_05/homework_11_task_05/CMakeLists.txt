cmake_minimum_required(VERSION 3.22.0)
project(geometry_dynamic)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(GeometryDynamicLib SHARED Figure.h Parallelogram.cpp Quardilateral.hpp Rhombus.cpp RightTriangle.hpp Triangle.cpp EquilateralTriangle.cpp IsoscelesTriangle.cpp Parallelogram.hpp Rectangle.cpp Rhombus.hpp Square.cpp Triangle.hpp EquilateralTriangle.hpp IsoscelesTriangle.hpp Quardilateral.cpp Rectangle.hpp RightTriangle.cpp Square.hpp)
add_executable(geometry_dynamic main.cpp)
target_link_libraries(geometry_dynamic GeometryDynamicLib)
