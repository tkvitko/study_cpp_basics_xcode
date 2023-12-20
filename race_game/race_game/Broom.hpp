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
    Broom();
    float get_time_for_distance (int distance) override;
};

#endif /* Broom_hpp */
