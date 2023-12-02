//
//  Counter.cpp
//  homework_06_02
//
//  Created by tkvitko on 29.11.2023.
//

#include "Counter.hpp"


Counter::Counter() {
    this->counter = 1;
};

Counter::Counter(int counter) {
    this->counter = counter;
};

void Counter::increment() {
    this->counter += 1;
};

void Counter::decrement() {
    this->counter -= 1;
};

int Counter::get_current_value() {
    return this->counter;
};
