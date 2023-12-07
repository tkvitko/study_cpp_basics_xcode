//
//  Figure.h
//  homework_06_task_03
//
//  Created by tkvitko on 03.12.2023.
//

#ifndef Figure_h
#define Figure_h
#include <iostream>

class Figure {
    
protected:
    int sides_count = 0;
    std::string name = "Фигура";
    
public:
    virtual void print_info() {
        std::cout << this->name << ":\n";
    };
    virtual bool is_right() {
        return true;
    };
};

#endif /* Figure_h */
