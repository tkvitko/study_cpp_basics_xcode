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
    name = "Треугольник";
    sides_count = 3;
    a = a_;
    b = b_;
    c = c_;
    A = A_;
    B = B_;
    C = C_;
    
    bool is_right = this->is_right();
    if (!is_right) {
        throw BadDimention("Ошибка создания фигуры. Причина: сумма углов не равна 180");
    }
};

void Triangle::print_info() {
    std::cout << this->name << " (стороны " << this->a << ", " << this->b << ", " << this->c << "; углы " << this->A << ", " << this->B << ", " << this->C << ") создан\n";
};


bool Triangle::is_right() {
    if (this->A + this->B + this->C == 180) {
        return true;
    }
    return false;
}
