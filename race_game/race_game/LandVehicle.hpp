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
                float first_rest_time_, float second_rest_time_) : Vehicle(speed_){
        time_before_rest = time_before_rest_;
        rest_time = rest_time_;
        first_rest_time = first_rest_time_;
        second_rest_time = second_rest_time_;
    };
    float get_time_for_distance (int distance) override {
        float time = distance / speed; // время без учета остановок
        
        float stops_count = time / time_before_rest;   // количество остановок
        if (stops_count != int(stops_count)) {
            stops_count = int(stops_count); // если поделилось не нацело, округляем вниз
        } else {
            stops_count -= 1;   // если поделилось нацело, отнимаем 1 остановку (уже достиг финиша)
        }
        
        // добавление времени на остановки
        for (int i=1; i<=stops_count; ++i) {
            if (i == 1) {
                if (first_rest_time != 0) {time += first_rest_time;} else {time += rest_time;}
            } else if (i == 2) {
                if (second_rest_time != 0) {time += second_rest_time;} else {time += rest_time;}
            } else {
                time += rest_time;
            }
        };
        return time;
    }
};

#endif /* LandVehicle_hpp */
