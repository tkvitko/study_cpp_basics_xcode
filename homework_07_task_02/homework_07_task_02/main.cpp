//
//  main.cpp
//  homework_07_task_02
//
//  Created by tkvitko on 02.12.2023.
//

# define SUB(a, b) ((a) - (b))
#include <iostream>

int main(int argc, const char * argv[]) {
    
    int a = 6;
    int b = 5;
    int c = 2;
    std::cout << SUB(a, b) << std::endl;
    std::cout << SUB(a, b) * c << std::endl;
    std::cout << SUB(a, b + c) * c << std::endl;
    return 0;
}
