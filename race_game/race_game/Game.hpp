//
//  Game.hpp
//  race_game
//
//  Created by tkvitko on 19.12.2023.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <algorithm>

#include "Player.hpp"
#include "SurfaceType.hpp"
#include "Vehicle.hpp"
#include "LandVehicle.hpp"
#include "AirVehicle.hpp"
#include "Exceptions.hpp"



inline bool compare_results(Player &player1, Player &player2)
{
    if (player2.time > player1.time) {
        return 1;
    } else {
        return 0;
    }
};

class Game {
    // Игра
protected:
    int distance = 0;
    SurfaceType type = SurfaceType::unknown;
    Player* players;
    
private:
    void _add_player(Vehicle* player);
    void check_player_alredy_registered(Vehicle* player);
    
public:
    int players_number = 0;
    
    Game(int distance_, int max_players_, SurfaceType type_);
    ~Game();
    std::string get_game_info();
    void add_player(LandVehicle* player);
    void add_player(AirVehicle* player);
    void clear_players();
    Player* get_players();
    void play();
};

#endif /* Game_hpp */
