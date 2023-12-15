//
//  IsoscelesTriangle.cpp
//  homework_06_task_03
//
//  Created by tkvitko on 03.12.2023.
//

#include "IsoscelesTriangle.hpp"

IsoscelesTriangle::IsoscelesTriangle(int a_, int b_, int A_, int B_) : Triangle(a_, b_, a_, A_, B_, A_) {
    name = "Равнобедренный треугольник";
}
