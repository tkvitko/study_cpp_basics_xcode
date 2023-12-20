//
//  LandVehicle.hpp
//  race_game
//
//  Created by tkvitko on 19.12.2023.
//

#ifndef LandVehicle_hpp
#define LandVehicle_hpp

#include <stdio.h>
#include "Vehicle.hpp"
#include "SurfaceType.hpp"

class LandVehicle : public Vehicle {
    // Наземное транспортное средство
protected:
    int time_before_rest; // время движения до отдыха
    float rest_time = 0;    //  общее время отдыха
    float first_rest_time = 0;  // время отдыха на первой остановке
    float second_rest_time = 0; // время отдыха на второй остановке
    
public:
    SurfaceType type = SurfaceType::land;
    LandVehicle(int speed_, int time_before_rest_, float rest_time_,
                float first_rest_time_, float second_rest_time_);
    
    float get_time_for_distance (int distance) override;
};

#endif /* LandVehicle_hpp */
