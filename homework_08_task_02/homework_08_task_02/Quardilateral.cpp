//
//  Quardilateral.cpp
//  homework_06_task_03
//
//  Created by tkvitko on 03.12.2023.
//

#include <iostream>
#include "Quardilateral.hpp"
#include "Triangle.hpp"

Quadrilateral::Quadrilateral(int a_, int b_, int c_, int d_, int A_, int B_, int C_, int D_) : Triangle(a_, b_, c_, A_, B_, C_) {
    name = "Четырехугольник";
    sides_count = 4;
    d = d_;
    D = D_;
};

void Quadrilateral::print_info() {
    std::cout << this->name << ":\n" << "Стороны: a=" << this->a << " b=" << this->b << " c=" << this->c << " d=" << this->d << "\nУглы: A=" << this->A << " B=" << this->B << " C=" << this->C << " D=" << this->D << "\n\n";
}
