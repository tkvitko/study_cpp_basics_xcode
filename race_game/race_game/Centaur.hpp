//
//  Centaur.hpp
//  race_game
//
//  Created by tkvitko on 19.12.2023.
//

#ifndef Centaur_hpp
#define Centaur_hpp

#include <stdio.h>
#include "LandVehicle.hpp"

class Centaur : public LandVehicle {
    // Кентавр
public:
    Centaur() : LandVehicle(15, 8, 2, 0, 0) {
        name = "Кентавр";
    }
};

#endif /* Centaur_hpp */
