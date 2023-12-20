//
//  UserDialog.cpp
//  race_game
//
//  Created by tkvitko on 19.12.2023.
//

#include "UserDialog.hpp"

void UserDialog::print_enumerated_choises(std::string* choises, int size) {
    for (int i=0; i<size; ++i) {
        std::cout << i+1 << ". " << choises[i] << std::endl;
    }
};

void UserDialog::print_game_types(){
    std::string game_types[] = {
        "Гонка для наземного транспорта",
        "Гонка для воздушного транспорта",
        "Гонка для наземного и воздушного транспорта"
    };
    this->print_enumerated_choises(game_types, 3);
};

void UserDialog::print_vehicle_types(){
    std::string vehicle_types[] = {
        "Ботинки-вездеходы",
        "Метла",
        "Верблюд",
        "Кентавр",
        "Орёл",
        "Верблюд-быстроход",
        "Ковёр-самолёт"
    };
    this->print_enumerated_choises(vehicle_types, 7);
};
