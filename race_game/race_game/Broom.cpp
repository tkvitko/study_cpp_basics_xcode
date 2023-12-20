//
//  Broom.cpp
//  race_game
//
//  Created by tkvitko on 19.12.2023.
//

#include "Broom.hpp"

Broom::Broom() : AirVehicle(20) {
    name = "Метла";
};

float Broom::get_time_for_distance (int distance) {
    return (1 - (distance/1000)/100.0) * distance / speed;
}
