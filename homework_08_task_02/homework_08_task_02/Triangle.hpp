//
//  Triangle.hpp
//  homework_06_task_03
//
//  Created by tkvitko on 03.12.2023.
//

#ifndef Triangle_hpp
#define Triangle_hpp

#include <stdio.h>
#include "Figure.h"

class Triangle : public Figure {

protected:
    int a, b, c;
    int A, B, C;
    
public:
    Triangle(int a_, int b_, int c_, int A_, int B_, int C_);
    void print_info();
    bool is_right();
};

#endif /* Triangle_hpp */
