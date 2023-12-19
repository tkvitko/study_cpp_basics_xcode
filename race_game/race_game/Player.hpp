//
//  Player.hpp
//  race_game
//
//  Created by tkvitko on 19.12.2023.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "Vehicle.hpp"

struct Player {
    Vehicle* vehicle;
    float time;
};

#endif /* Player_hpp */
