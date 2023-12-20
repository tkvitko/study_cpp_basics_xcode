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
    Eagle();
    float get_time_for_distance (int distance) override;
};

#endif /* Eagle_hpp */
