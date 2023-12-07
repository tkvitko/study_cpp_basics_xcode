//
//  Triangle.cpp
//  homework_06_task_03
//
//  Created by tkvitko on 03.12.2023.
//

#include <iostream>
#include <string>
#include "Triangle.hpp"
#include "FigureCharacteristicsException.hpp"

Triangle::Triangle(int a_, int b_, int c_, int A_, int B_, int C_) {
    
    bool is_right = this->is_right();
    if (is_right) {
        name = "Треугольник";
        sides_count = 3;
        a = a_;
        b = b_;
        c = c_;
        A = A_;
        B = B_;
        C = C_;
    } else {
        throw BadDimention();
    }
};

void Triangle::print_info() {
    std::cout << this->name << ":\n" << "Стороны: a=" << this->a << " b=" << this->b << " c=" << this->c << "\nУглы: A=" << this->A << " B=" << this->B << " C=" << this->C << "\n\n";
};


bool Triangle::is_right() {
    if (this->A + this->B + this->C == 180) {
        return true;
    }
    return false;
}