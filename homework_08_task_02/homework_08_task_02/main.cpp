//
//  main.cpp
//  homework_06_task_03
//
//  Created by tkvitko on 03.12.2023.
//

#include "Figure.h"
#include "Triangle.hpp"
#include "RightTriangle.hpp"
#include "IsoscelesTriangle.hpp"
#include "EquilateralTriangle.hpp"
#include "Quardilateral.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Parallelogram.hpp"
#include "Rhombus.hpp"



int main(int argc, const char * argv[]) {

    Triangle triangle = Triangle(10, 20, 30, 50, 60, 70);
    Figure* ptr_triangle = &triangle;
    ptr_triangle->print_info();
    
    RightTriangle right_triangle = RightTriangle(10, 20, 30, 50, 60);
    Figure* ptr_right_triangle = &right_triangle;
    ptr_right_triangle->print_info();
    
    IsoscelesTriangle isosceles_triangle = IsoscelesTriangle(10, 20, 50, 60);
    Figure* ptr_isosceles_triangle = &isosceles_triangle;
    ptr_isosceles_triangle->print_info();
    
    EquilateralTriangle equilateral_triangle = EquilateralTriangle(30);
    Figure* ptr_equilateral_triangle = &equilateral_triangle;
    ptr_equilateral_triangle->print_info();
    
    Quadrilateral quadrilateral = Quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    Figure* ptr_quadrilateral = &quadrilateral;
    ptr_quadrilateral->print_info();
    
    Rectangle rectangle = Rectangle(10, 20);
    Figure* ptr_rectangle = &rectangle;
    ptr_rectangle->print_info();
    
    Square square = Square(20);
    Figure* ptr_square = &square;
    ptr_square->print_info();
    
    Parallelogram parallelogram = Parallelogram(20, 30, 30, 40);
    Figure* ptr_parallelogram = &parallelogram;
    ptr_parallelogram->print_info();
    
    Rhombus rhombus = Rhombus(30, 30, 40);
    Figure* ptr_rhombus = &rhombus;
    ptr_rhombus->print_info();

    return 0;
}
