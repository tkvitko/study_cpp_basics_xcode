//
//  main.cpp
//  homework_11_task_02
//
//  Created by tkvitko on 16.12.2023.
//

#include <iostream>
#include "Leaver.hpp"

int main(int argc, const char * argv[]) {
    std::string name;
    std::cout << "Введите имя: ";
    std::cin >> name;
    
    Leaver leaver = Leaver();
    leaver.leave(name);
    return 0;
}
