//
//  Vehicle.cpp
//  race_game
//
//  Created by tkvitko on 19.12.2023.
//

#include "Vehicle.hpp"

Vehicle::Vehicle() {};
Vehicle::Vehicle(int speed_) {
    speed = speed_;
};
std::string Vehicle::get_name() {
    return this->name;
};
