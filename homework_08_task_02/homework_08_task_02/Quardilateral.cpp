//
//  Quardilateral.cpp
//  homework_06_task_03
//
//  Created by tkvitko on 03.12.2023.
//

#include <iostream>
#include "Quardilateral.hpp"
#include "FigureCharacteristicsException.hpp"

Quadrilateral::Quadrilateral(int a_, int b_, int c_, int d_, int A_, int B_, int C_, int D_) {
    name = "Четырехугольник";
    sides_count = 4;
    a = a_;
    b = b_;
    c = c_;
    A = A_;
    B = B_;
    C = C_;
    d = d_;
    D = D_;
    
    bool is_right = this->is_right();
    if (!is_right) {
        throw BadDimention("Ошибка создания фигуры. Причина: сумма углов не равна 360");
    }
};

void Quadrilateral::print_info() {
    std::cout << this->name << " (стороны " << this->a << ", " << this->b << ", " << this->c << ", " << this->d << "; углы " << this->A << ", " << this->B << ", " << this->C << ", " << this->D << ") создан\n";
}

bool Quadrilateral::is_right() {
    if (this->A + this->B + this->C + this->D == 360) {
        return true;
    }
    return false;
}
