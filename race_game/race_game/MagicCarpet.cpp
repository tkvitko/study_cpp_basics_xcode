//
//  MagicCarpet.cpp
//  race_game
//
//  Created by tkvitko on 19.12.2023.
//

#include "MagicCarpet.hpp"

MagicCarpet::MagicCarpet() : AirVehicle(10) {
    name = "Ковер_самолет";
};

float MagicCarpet::get_time_for_distance (int distance) {
    float time = distance / speed;
    if (distance < 1000) {
        return time;
    } else if (distance < 5000) {
        return time * 0.97f;
    } else if (distance < 10000) {
        return time * 0.9f;
    } else {
        return time * 0.95f;
    }
}
