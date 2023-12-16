//
//  Parallelogram.cpp
//  homework_06_task_03
//
//  Created by tkvitko on 03.12.2023.
//

#include "Parallelogram.hpp"

Parallelogram::Parallelogram(int a_, int b_, int A_, int B_) : Quadrilateral(a_, b_, a_, b_, A_, B_, A_, B_) {
    name = "Параллелограмм";
}
