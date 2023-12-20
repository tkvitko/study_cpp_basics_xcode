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
    MagicCarpet();
    float get_time_for_distance (int distance) override;
};

#endif /* MagicCarpet_hpp */
