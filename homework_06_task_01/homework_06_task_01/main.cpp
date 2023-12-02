//
//  main.cpp
//  homework_06_task_01
//
//  Created by tkvitko on 29.11.2023.
//

#include <iostream>
#include "math.hpp"

int main(int argc, const char * argv[]) {
    while (true) {

        double num1 = 0;
        double num2 = 0;
        int operation_number = 0;
        
        std::cout << "Введите первое число: ";
        std::cin >> num1;
        std::cout << "Введите второе число: ";
        std::cin >> num2;
        std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
        std::cin >> operation_number;

        switch (operation_number) {
            case 1:
                std::cout << "num1 + num2 = " << add(num1, num2) << std::endl;
                break;
            case 2:
                std::cout << "num1 - num2 = " << subtract(num1, num2) << std::endl;
                break;
            case 3:
                std::cout << "num1 * num2 = " << multiply(num1, num2) << std::endl;
                break;
            case 4:
                std::cout << "num1 / num2 = " << divide(num1, num2) << std::endl;
                break;
            case 5:
                std::cout << "num1 ^ num2 = " << sqrt(num1, num2) << std::endl;
                break;
        }
    };
    
    return 0;
}
