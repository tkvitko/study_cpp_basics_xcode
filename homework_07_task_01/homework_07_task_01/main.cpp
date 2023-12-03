//
//  main.cpp
//  homework_07_task_01
//
//  Created by tkvitko on 02.12.2023.
//

#define MODE 0
    
#include <iostream>

#if MODE == 1
int add(int num1, int num2) {
    return num1 + num2;
}
#endif

int main(int argc, const char * argv[]) {
    
#ifndef MODE
#error "Should define MODE"
#endif
    
#if MODE == 0
    std::cout << "Работаю в режиме тренировки" << std::endl;
    
# elif MODE == 1
    int user_num1 = 0, user_num2 = 0;
    std::cout << "Работаю в боевом режиме" << std::endl;
    std::cout << "Введите число 1: " << std::endl;
    std::cin >> user_num1;
    std::cout << "Введите число 2: " << std::endl;
    std::cin >> user_num2;
    std::cout << "Результат сложения: " << add(user_num1, user_num2) << std::endl;

# else
    std::cout << "Неизвестный режим. Завершение работы" << std::endl;
    
# endif
    
    return 0;
}
