//
//  Eagle.cpp
//  race_game
//
//  Created by tkvitko on 19.12.2023.
//

#include "Eagle.hpp"

Eagle::Eagle() : AirVehicle(8) {
    name = "Орел";
};

float Eagle::get_time_for_distance (int distance) {
    return 0.94 * distance / speed;
}
