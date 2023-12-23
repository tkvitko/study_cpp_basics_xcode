//
//  Game.cpp
//  race_game
//
//  Created by tkvitko on 19.12.2023.
//

#include "Player.hpp"
#include "Game.hpp"

void Game::_add_player(Vehicle* player) {
    this->check_player_alredy_registered(player);
    this->players_number += 1;
    this->players[players_number - 1].vehicle = player;
    this->players[players_number - 1].time = 0;
}

void Game::check_player_alredy_registered(Vehicle* player) {
    for (int i=0; i<players_number; ++i){
        if (this->players[i].vehicle->get_name() == player->get_name()) {
            throw PlayerAlreadyRegistered();
        }
    }
}

Game::Game(int distance_, int max_players_, SurfaceType type_) {
    distance = distance_;
    type = type_;
    this->players = new Player[max_players_];
}

Game::~Game() {
    delete[] this->players;
//    this->clear_players();
}

std::string Game::get_game_info() {
    std::string result_str = "\n\nРасстояние: " + std::to_string(distance) + "\n";
    result_str += "Зарегистрированные транспортные средства: ";
    for (int i=0; i<players_number; ++i) {
        result_str += this->players[i].vehicle->get_name();
        result_str += " ";
    }
    return result_str;
}

void Game::add_player(LandVehicle* player) {
    if (this->type == SurfaceType::air) {
        throw WrongPlayerType();
    } else {
        this->_add_player(player);
    }
}

void Game::add_player(AirVehicle* player) {
    if (this->type == SurfaceType::land) {
        throw WrongPlayerType();
    } else {
        this->_add_player(player);
    }
}

Player* Game::get_players() {
    std::sort(this->players, this->players+players_number, &compare_results);
    return this->players;
}
//
//void Game::clear_players() {
//    delete[] this->players;
//}

void Game::play() {
    if (this->players_number < 2) {
        throw NotEnoughPlayers();
    } else {
        for (int i=0; i<=players_number-1; ++i) {
            this->players[i].time = this->players[i].vehicle->get_time_for_distance(this->distance);
        }
    }
}
