//
//  Eagle.hpp
//  race_game
//
//  Created by tkvitko on 19.12.2023.
//

#ifndef Eagle_hpp
#define Eagle_hpp

#include <stdio.h>
#include "AirVehicle.hpp"

class Eagle : public AirVehicle {
    // Орел
public:
    Eagle() : AirVehicle(8) {
        name = "Орел";
    };
    float get_time_for_distance (int distance) override {
        return 0.94 * distance / speed;
    }
};

#endif /* Eagle_hpp */
