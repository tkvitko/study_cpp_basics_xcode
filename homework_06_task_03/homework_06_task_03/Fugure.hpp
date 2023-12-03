//
//  Fugure.hpp
//  homework_06_task_03
//
//  Created by tkvitko on 03.12.2023.
//

#ifndef Fugure_hpp
#define Fugure_hpp

#include <stdio.h>
#include <iostream>
#include <string>

class Figure {
    
protected:
    int sides_count = 0;
    std::string name = "Фигура";
    
public:
    virtual void print_info() {
        std::cout << this->name << ":\n";
    };
};
#endif /* Fugure_hpp */
