//
//  main.cpp
//  homework_06_02
//
//  Created by tkvitko on 29.11.2023.
//

#include <iostream>
#include "Counter.hpp"

int main(int argc, const char * argv[]) {
    bool create_with_user_value;
    std::string user_answer;
    
    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> user_answer;
    if (user_answer == "да") {
        create_with_user_value = true;
    } else {
        create_with_user_value = false;
    };

    int initial_value = 1;
    if (create_with_user_value) {
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> initial_value;
    };
    
    Counter counter = Counter(initial_value);
    char command = '\0';
    while (command != 'x') {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command;
        switch (command) {
            case '+':
                counter.increment();
                break;
            case '-':
                counter.decrement();
                break;
            case '=':
                std::cout << counter.get_current_value() << std::endl;
                break;
            default:
                break;
        };
    };
    std::cout << "До свидания!" << std::endl;
}
