//
//  AirVehicle.hpp
//  race_game
//
//  Created by tkvitko on 19.12.2023.
//

#ifndef AirVehicle_hpp
#define AirVehicle_hpp

#include <stdio.h>
#include "Vehicle.hpp"
#include "SurfaceType.hpp"

class AirVehicle : public Vehicle {
    // Воздушное транспортное средство
public:
    SurfaceType type = SurfaceType::air;
    AirVehicle(int speed_);
};

#endif /* AirVehicle_hpp */
