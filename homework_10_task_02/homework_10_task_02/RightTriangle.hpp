//
//  RightTriangle.hpp
//  homework_06_task_03
//
//  Created by tkvitko on 03.12.2023.
//

#ifndef RightTriangle_hpp
#define RightTriangle_hpp

#include <stdio.h>
#include "Triangle.hpp"

class RightTriangle : public Triangle {
    // прямоугольный треугольник
public:
    RightTriangle(int a_, int b_, int c_, int A_, int B_);
    };

#endif /* RightTriangle_hpp */
