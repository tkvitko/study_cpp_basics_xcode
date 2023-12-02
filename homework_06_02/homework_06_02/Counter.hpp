//
//  Counter.hpp
//  homework_06_02
//
//  Created by tkvitko on 29.11.2023.
//

#ifndef Counter_hpp
#define Counter_hpp

#include <stdio.h>
class Counter {
    
private:
    int counter;

public:
    Counter();
    Counter(int counter);
    void increment();
    void decrement();
    int get_current_value();
};

#endif /* Counter_hpp */
