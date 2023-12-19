//
//  Broom.hpp
//  race_game
//
//  Created by tkvitko on 19.12.2023.
//

#ifndef Broom_hpp
#define Broom_hpp

#include <stdio.h>
#include "AirVehicle.hpp"

class Broom : public AirVehicle {
    // Метла
public:
    Broom() : AirVehicle(20) {
        name = "Метла";
    };
    float get_time_for_distance (int distance) override {
        return (1 - (distance/1000)/100.0) * distance / speed;
    }
};

#endif /* Broom_hpp */
