//
//  IsoscelesTriangle.hpp
//  homework_06_task_03
//
//  Created by tkvitko on 03.12.2023.
//

#ifndef IsoscelesTriangle_hpp
#define IsoscelesTriangle_hpp

#include <stdio.h>
#include "Triangle.hpp"

class IsoscelesTriangle : public Triangle {
    // равнобедренный треугольник
public:
    IsoscelesTriangle(int a_, int b_, int A_, int B_);
};

#endif /* IsoscelesTriangle_hpp */
