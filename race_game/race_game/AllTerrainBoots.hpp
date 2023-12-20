//
//  AllTerrainBoots.hpp
//  race_game
//
//  Created by tkvitko on 19.12.2023.
//

#ifndef AllTerrainBoots_hpp
#define AllTerrainBoots_hpp

#include <stdio.h>
#include "LandVehicle.hpp"

class AllTerrainBoots : public LandVehicle {
    // Ботинки-вездеходы
public:
    AllTerrainBoots() : LandVehicle(6, 60, 5, 10, 0) {
        name = "Ботинки вездеходы";
    }
};

#endif /* AllTerrainBoots_hpp */
