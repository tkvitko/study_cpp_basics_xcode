//
//  main.cpp
//  race_game
//
//  Created by tkvitko on 16.12.2023.
//

#include <iostream>

#include "Camel.hpp"
#include "FastCamel.hpp"
#include "Centaur.hpp"
#include "AllTerrainBoots.hpp"
#include "Eagle.hpp"
#include "Broom.hpp"
#include "MagicCarpet.hpp"

#include "Game.hpp"
#include "UserDialog.hpp"


int main(int argc, const char * argv[]) {
    
    // Продакшен-игра
    UserDialog dialog = UserDialog();
    std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;

    while(true) {
        
        // Выбор типа гонки
        dialog.print_game_types();
        int game_type_number = 0;
        std::cout << "Выберите тип гонки: ";
        std::cin >> game_type_number;

        // Выбор дистанции
        int distance = 0;
        std::cout << "Укажите дистанцию (должна быть положительна): ";
        std::cin >> distance;

        // Создание объекта гонки
        SurfaceType game_type = SurfaceType::unknown;
        switch (game_type_number) {
            case 1:
                game_type = SurfaceType::land;
                break;
            case 2:
                game_type = SurfaceType::air;
                break;
            case 3:
                game_type = SurfaceType::mixed;
                break;
            default:
                break;
        };
        Game game = Game(distance, 7, game_type);
    
        // регистрация участников
        bool game_played = false;
        while (!game_played) {
            std::cout << game.get_game_info() << std::endl;
            std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;
            std::cout << "1. Зарегистрировать транспорт." << std::endl;
            std::cout << "2. Начать гонку" << std::endl;
            std::cout << "Выберите действие: ";
            int choise = 0;
            std::cin >> choise;

            if (choise == 1) {
                bool end = false;
                while (!end) {
                    std::cout << game.get_game_info() << std::endl;
                    dialog.print_vehicle_types();
                    std::cout << "0. Закончить регистрацию" << std::endl;
                    std::cout << "Выбете транспорт: ";
                    std::cin >> choise;
                    try {
                        switch (choise) {
                            case 0:
                                end = true;
                                break;
                            case 1: {
                                AllTerrainBoots* boots = new AllTerrainBoots();
                                game.add_player(boots);}
                                break;
                            case 2: {
                                Broom* broom = new Broom();
                                game.add_player(broom);}
                                break;
                            case 3: {
                                Camel* camel = new Camel();
                                game.add_player(camel);}
                                break;
                            case 4: {
                                Centaur* centaur = new Centaur();
                                game.add_player(centaur);}
                                break;
                            case 5: {
                                Eagle* eagle = new Eagle();
                                game.add_player(eagle);}
                                break;
                            case 6: {
                                FastCamel* fast_camel = new FastCamel();
                                game.add_player(fast_camel);}
                                break;
                            case 7: {
                                MagicCarpet* carpet = new MagicCarpet();
                                game.add_player(carpet);}
                                break;
                        }
                        
                    } catch (WrongPlayerType& e) {
                        std::cout << e.what() << std::endl;
                    } catch (PlayerAlreadyRegistered& e) {
                        std::cout << e.what() << std::endl;
                    }
                }
            } else if (choise == 2) {
                try {
                    game.play();
                    Player* results = game.get_players();
                        for (int i=0; i<game.players_number; ++i) {
                            std::cout << results[i].vehicle->get_name() << " " << results[i].time << std::endl;
                        }
                    game_played = true;
                    
                    
                } catch (NotEnoughPlayers& e) {
                    std::cout << e.what() << std::endl;
                }
            }
        }
        std::cout << "1. Сыграть ещё раз" << std::endl;
        std::cout << "2. Закончить" << std::endl;
        std::cout << "Выберите действие: ";
        int choise = 0;
        std::cin >> choise;
        switch (choise) {
            case 1:
                for (int i=0; i<game.players_number; ++i) {
                    delete game.get_players()[i].vehicle;
                };
                break;
            case 2:
                return 0;
        };
    }
}
