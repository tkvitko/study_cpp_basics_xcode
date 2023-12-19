//
//  MagicCarpet.hpp
//  race_game
//
//  Created by tkvitko on 19.12.2023.
//

#ifndef MagicCarpet_hpp
#define MagicCarpet_hpp

#include <stdio.h>
#include "AirVehicle.hpp"

class MagicCarpet : public AirVehicle {
    // Ковер самолет
public:
    MagicCarpet() : AirVehicle(10) {
        name = "Ковер_самолет";
    };
    float get_time_for_distance (int distance) override {
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
};

#endif /* MagicCarpet_hpp */
