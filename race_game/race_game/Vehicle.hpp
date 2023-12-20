//
//  Vehicle.hpp
//  race_game
//
//  Created by tkvitko on 19.12.2023.
//

#ifndef Vehicle_hpp
#define Vehicle_hpp

#include <stdio.h>
#include <string>

class Vehicle {
    // Транспортное средство
protected:
    int speed;  // скорость
    std::string name;   // имя
public:
    Vehicle();
    Vehicle(int speed_);
    virtual float get_time_for_distance (int distance) {
        return 0.0f;
    };
    std::string get_name();
};

#endif /* Vehicle_hpp */
