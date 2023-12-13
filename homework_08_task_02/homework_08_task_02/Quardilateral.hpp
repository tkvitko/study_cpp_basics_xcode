//
//  Quardilateral.hpp
//  homework_06_task_03
//
//  Created by tkvitko on 03.12.2023.
//

#ifndef Quardilateral_hpp
#define Quardilateral_hpp

#include <stdio.h>
#include "Triangle.hpp"

class Quadrilateral : public Figure  {
    
protected:
    int a, b, c, d;
    int A, B, C, D;
    
public:
    Quadrilateral(int a_, int b_, int c_, int d_, int A_, int B_, int C_, int D_);
    void print_info();
    bool is_right();
};

#endif /* Quardilateral_hpp */
