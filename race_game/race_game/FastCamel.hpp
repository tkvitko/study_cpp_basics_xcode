//
//  FastCamel.hpp
//  race_game
//
//  Created by tkvitko on 19.12.2023.
//

#ifndef FastCamel_hpp
#define FastCamel_hpp

#include <stdio.h>
#include "LandVehicle.hpp"

class FastCamel : public LandVehicle {
    // Верблюд-быстроход
public:
    FastCamel() : LandVehicle(40, 10, 8, 5, 6.5) {
        name = "Верблюд быстроход";
    }
};

#endif /* FastCamel_hpp */
