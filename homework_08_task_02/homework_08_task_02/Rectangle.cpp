//
//  Rectangle.cpp
//  homework_06_task_03
//
//  Created by tkvitko on 03.12.2023.
//

#include "Rectangle.hpp"

Rectangle::Rectangle(int a_, int b_) : Quadrilateral(a_, b_, a_, b_, 90, 90, 90, 90) {
    name = "Прямоугольник";
}
