//
//  main.cpp
//  race_game
//
//  Created by tkvitko on 16.12.2023.
//

#include <iostream>

enum class SurfaceType {
    land,
    air,
    unknown,
    mixed
};

class Vehicle {
    // Транспортное средство
protected:
    int speed;  // скорость
    std::string name;   // имя
public:
    Vehicle() {};
    Vehicle(int speed_) {
        speed = speed_;
    };
    virtual float get_time_for_distance (int distance) {
        return 0.0;
    };
    std::string get_name() {
        return this->name;
    };
};

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

class Camel : public LandVehicle {
    // Верблюд
public:
    Camel() : LandVehicle(10, 30, 8, 5, 0) {
        name = "Вербюд";
    }
};

class FastCamel : public LandVehicle {
    // Верблюд-быстроход
public:
    FastCamel() : LandVehicle(40, 10, 8, 5, 6.5) {
        name = "Верблюд быстроход";
    }
};

class Centaur : public LandVehicle {
    // Кентавр
public:
    Centaur() : LandVehicle(15, 8, 2, 0, 0) {
        name = "Кентавр";
    }
};

class AllTerrainBoots : public LandVehicle {
    // Ботинки-вездеходы
public:
    AllTerrainBoots() : LandVehicle(6, 60, 5, 10, 0) {
        name = "Ботинки_вездеходы";
    }
};

class AirVehicle : public Vehicle {
    // Воздушное транспортное средство
public:
    SurfaceType type = SurfaceType::air;
    AirVehicle(int speed_) : Vehicle(speed_) {}
};

class MagicCarpet : public AirVehicle {
    // Ковер самолет
public:
    MagicCarpet() : AirVehicle(10) {
        name = "Ковер_самолет";
    };
    float get_time_for_distance (int distance) override {
        float time = distance / speed;
        if (distance < 1000) {
            return time;
        } else if (distance < 5000) {
            return time * 0.97f;
        } else if (distance < 10000) {
            return time * 0.9f;
        } else {
            return time * 0.95f;
        }
    }
};

class Eagle : public AirVehicle {
    // Орел
public:
    Eagle() : AirVehicle(8) {
        name = "Орел";
    };
    float get_time_for_distance (int distance) override {
        return 0.94 * distance / speed;
    }
};

class Broom : public AirVehicle {
    // Метла
public:
    Broom() : AirVehicle(20) {
        name = "Метла";
    };
    float get_time_for_distance (int distance) override {
        return (1 - (distance/1000)/100.0) * distance / speed;
    }
};

class NotEnoughPlayers : public std::exception {
public:
    const char* what() const noexcept override {
        return "\nВнимание: Должно быть зарегистрировано хотя бы 2 транспортных средства";
    };
};

class WrongPlayerType : public std::exception {
public:
    const char* what() const noexcept override {
        return "\nВнимание: Попытка зарегистрировать неверный типа транспортного средства";
    };
};

class PlayerAlreadyREgistered : public std::exception {
public:
    const char* what() const noexcept override {
        return "\nВнимание: Этот тип уже зарегистрирован";
    };
};

struct Player {
    Vehicle* vehicle;
    float time;
};

bool compare_results(Player &player1, Player &player2)
{
    if (player2.time > player1.time) {
        return 1;
    } else {
        return 0;
    }
}

class Game {
    // Игра
protected:
    int distance = 0;
    int max_players = 0;
    Player* players = new Player[max_players];
    SurfaceType type = SurfaceType::unknown;
    
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
        distance = distance_;
        max_players = max_players_;
        type = type_;
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

class UserDialig {
private:
    void print_enumerated_choises(std::string* choises, int size) {
        for (int i=0; i<size; ++i) {
            std::cout << i+1 << ". " << choises[i] << std::endl;
        }
    };
    
public:
    void print_game_types(){
        std::string game_types[] = {
            "Гонка для наземного транспорта",
            "Гонка для воздушного транспорта",
            "Гонка для наземного и воздушного транспорта"
        };
        this->print_enumerated_choises(game_types, 3);
    };
    void print_vehicle_types(){
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
};



int main(int argc, const char * argv[]) {
    
    int example_distance = 1000;
    int test_distance = 4500;
    
    // Тестирование расчета времени
    
//    LandVehicle test_land_vehicle = LandVehicle(100, 6, 3, 0, 0);
//    std::cout << test_land_vehicle.get_time_for_distance(example_distance) << std::endl;
//
//    FastCamel fast_camel = FastCamel();
//    std::cout << fast_camel.get_time_for_distance(test_distance) << std::endl;
//
//    Centaur centaur = Centaur();
//    std::cout << centaur.get_time_for_distance(test_distance) << std::endl;
//
//    Camel camel = Camel();
//    std::cout << camel.get_time_for_distance(test_distance) << std::endl;
//
//    AllTerrainBoots boots = AllTerrainBoots();
//    std::cout << boots.get_time_for_distance(test_distance) << std::endl;
//
//    Broom broom = Broom();
//    std::cout << broom.get_time_for_distance(test_distance) << std::endl;
//
//    MagicCarpet carpet = MagicCarpet();
//    std::cout << carpet.get_time_for_distance(test_distance) << std::endl;
//
//    Eagle eagle = Eagle();
//    std::cout << eagle.get_time_for_distance(test_distance) << std::endl;
    
    // Тестирование процесса гонки
    Camel camel = Camel();
    Centaur centaur = Centaur();
    FastCamel fast_camel = FastCamel();
    Eagle eagle = Eagle();
    Game test_game = Game(test_distance, 7, SurfaceType::land);

    test_game.add_player(&camel);
//    test_game.add_player(&eagle);
    test_game.add_player(&centaur);
    test_game.add_player(&fast_camel);
    test_game.play();
    Player* results = test_game.get_players();
    for (int i=0; i<3; ++i) {
        std::cout << results[i].vehicle->get_name() << " " << results[i].time << std::endl;
    }
    
    // Продакшен-игра
    UserDialig dialog = UserDialig();
    std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;

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
    bool game_played = false;
    // регистрация участников
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
                            AllTerrainBoots boots = AllTerrainBoots();
                            game.add_player(&boots);}
                            break;
                        case 2: {
                            Broom broom = Broom();
                            game.add_player(&broom);}
                            break;
                        case 3: {
                            Camel camel = Camel();
                            game.add_player(&camel);}
                            break;
                        case 4: {
                            Centaur centaur = Centaur();
                            game.add_player(&centaur);}
                            break;
                        case 5: {
                            Eagle eagle = Eagle();
                            game.add_player(&eagle);}
                            break;
                        case 6: {
                            FastCamel fast_camel = FastCamel();
                            game.add_player(&fast_camel);}
                            break;
                        case 7: {
                            MagicCarpet carpet = MagicCarpet();
                            game.add_player(&carpet);}
                            break;
                    }
                    
                } catch (WrongPlayerType& e) {
                    std::cout << e.what() << std::endl;
                } catch (PlayerAlreadyREgistered& e) {
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
    return 0;
}
