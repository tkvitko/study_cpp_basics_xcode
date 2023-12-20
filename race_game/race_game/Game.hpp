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
    int max_players = 0;
    SurfaceType type = SurfaceType::unknown;
    Player* players;
    
private:
    void _add_player(Vehicle* player) {
        this->check_player_alredy_registered(player);
        this->players_number += 1;
        this->players[players_number - 1].vehicle = player;
        this->players[players_number - 1].time = 0;
    }
    
    void check_player_alredy_registered(Vehicle* player) {
        for (int i=0; i<players_number; ++i){
            if (this->players[i].vehicle->get_name() == player->get_name()) {
                throw PlayerAlreadyREgistered();
            }
        }
    }
    
public:
    int players_number = 0;
    
    Game(int distance_, int max_players_, SurfaceType type_) {
        this->players = new Player[max_players];
        distance = distance_;
        max_players = max_players_;
        type = type_;
    }
    
    ~Game() {
        delete[] this->players;
    }
    
    std::string get_game_info() {
        std::string result_str = "\n\nРасстояние: " + std::to_string(distance) + "\n";
        result_str += "Зарегистрированные транспортные средства: ";
        for (int i=0; i<players_number; ++i) {
            result_str += this->players[i].vehicle->get_name();
            result_str += " ";
        }
        return result_str;
    }
    
    void add_player(LandVehicle* player) {
        if (this->type == SurfaceType::air) {
            throw WrongPlayerType();
        } else {
            this->_add_player(player);
        }
    }
    
    void add_player(AirVehicle* player) {
        if (this->type == SurfaceType::land) {
            throw WrongPlayerType();
        } else {
            this->_add_player(player);
        }
    }
    
    Player* get_players() {
        std::sort(this->players, this->players+players_number, &compare_results);
        return this->players;
    }

    void play() {
        if (this->players_number < 2) {
            throw NotEnoughPlayers();
        } else {
            for (int i=0; i<=players_number-1; ++i) {
                this->players[i].time = this->players[i].vehicle->get_time_for_distance(this->distance);
            }
        }
    }
};

#endif /* Game_hpp */
