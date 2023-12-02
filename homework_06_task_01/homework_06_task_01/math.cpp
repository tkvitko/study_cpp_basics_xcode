//
//  math.cpp
//  homework_06_task_01
//
//  Created by tkvitko on 29.11.2023.
//

#include "math.hpp"

double add(double num1, double num2) {
    return num1 + num2;
};

double multiply(double num1, double num2) {
    return num1 * num2;
};

double subtract(double num1, double num2) {
    return num1 - num2;
};

double divide(double num1, double num2) {
    return num1 / num2;
};

double sqrt(double num1, int num2) {
    double res = num1;
    for (int i = 1; i < num2; ++i) {
        res *= num1;
    }
    return res;
};
