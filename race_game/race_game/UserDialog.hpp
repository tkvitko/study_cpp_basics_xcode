//
//  UserDialog.hpp
//  race_game
//
//  Created by tkvitko on 19.12.2023.
//

#ifndef UserDialog_hpp
#define UserDialog_hpp

#include <stdio.h>
#include <string>
#include <iostream>

class UserDialog {
private:
    void print_enumerated_choises(std::string* choises, int size);
    
public:
    void print_game_types();
    void print_vehicle_types();
};

#endif /* UserDialog_hpp */
