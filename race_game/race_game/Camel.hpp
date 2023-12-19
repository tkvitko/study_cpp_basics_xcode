//
//  Camel.hpp
//  race_game
//
//  Created by tkvitko on 19.12.2023.
//

#ifndef Camel_hpp
#define Camel_hpp

#include <stdio.h>
#include "LandVehicle.hpp"

class Camel : public LandVehicle {
    // Верблюд
public:
    Camel() : LandVehicle(10, 30, 8, 5, 0) {
        name = "Вербюд";
    }
};

#endif /* Camel_hpp */
