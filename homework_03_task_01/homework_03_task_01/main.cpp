#include <iostream>
#include <string>

class Calculator {
private:
    double num1;
    double num2;

public:

    double add() {
        return this->num1 + this->num2;
    };

    double multiply() {
        return this->num1 * this->num2;
    };

    double subtract_1_2() {
        return this->num1 - this->num2;
    };

    double subtract_2_1() {
        return this->num2 - this->num1;
    };

    double divide_1_2() {
        return this->num1 / this->num2;
    };

    double divide_2_1() {
        return this->num2 / this->num1;
    };

    bool set_num1(double num1) {
        if (num1 != 0) {
            this->num1 = num1;
            return true;
        } else {return false;};
    };

    bool set_num2(double num2) {
        if (num2 != 0) {
            this->num2 = num2;
            return true;
        } else {return false;};
    };
};

int main(){

    while (true) {

        Calculator calculator;
        double user_num1 = 0;
        double user_num2 = 0;

        while (!calculator.set_num1(user_num1)){
            std::cout << "Введите num1: ";
            std::cin >> user_num1;
            if (user_num1 == 0) {std::cout << "Невеный ввод!" << std::endl;}
        };
        
        while (!calculator.set_num2(user_num2)){
            std::cout << "Введите num2: ";
            std::cin >> user_num2;
            if (user_num2 == 0) {std::cout << "Невеный ввод!" << std::endl;}
        };

        std::cout << "num1 + num2 = " << calculator.add() << std::endl;
        std::cout << "num1 - num2 = " << calculator.subtract_1_2() << std::endl;
        std::cout << "num2 - num1 = " << calculator.subtract_2_1() << std::endl;
        std::cout << "num1 * num2 = " << calculator.multiply() << std::endl;
        std::cout << "num1 / num2 = " << calculator.divide_1_2() << std::endl;
        std::cout << "num2 / num1 = " << calculator.divide_2_1() << std::endl;
    }
}
