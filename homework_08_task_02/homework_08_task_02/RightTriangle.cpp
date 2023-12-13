//
//  RightTriangle.cpp
//  homework_06_task_03
//
//  Created by tkvitko on 03.12.2023.
//

#include "RightTriangle.hpp"
#include "FigureCharacteristicsException.hpp"

RightTriangle::RightTriangle(int a_, int b_, int c_, int A_, int B_) : Triangle(a_, b_, c_, A_, B_, 90) {
    name = "Прямоугольный треугольник";
    bool is_right = this->is_right();
    if (!is_right) {
        throw BadDimention("Ошибка создания фигуры. Причина: сумма углов не равна 180");
    }
}
