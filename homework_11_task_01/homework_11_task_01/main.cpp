//
//  main.cpp
//  homework_11_task_01
//
//  Created by tkvitko on 16.12.2023.
//

#include <iostream>
#include <string>
#include "Greeter.hpp"

int main(int argc, const char * argv[]) {
    
    std::string name;
    std::cout << "Введите имя: ";
    std::cin >> name;
    
    Greeter greeter = Greeter();
    greeter.greet(name);
    return 0;
}
