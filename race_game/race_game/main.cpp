//
//  main.cpp
//  race_game
//
//  Created by tkvitko on 16.12.2023.
//

#include <iostream>

enum class PlayerTypes {
    land,
    air,
    unknown
};

class Vehicle {
    // Транспортное средство
protected:
    int speed;  // скорость
public:
    std::string name;
    PlayerTypes type = PlayerTypes::unknown;
    Vehicle() {};
    Vehicle(int speed_) {
        speed = speed_;
    };
    virtual float get_time_for_distance (int distance) {
        return 0.0;
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
    PlayerTypes type = PlayerTypes::land;
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
        name = "Вербюд-быстроход";
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
        name = "Ботинки-вездеходы";
    }
};

class AirVehicle : public Vehicle {
    // Воздушное транспортное средство
public:
    PlayerTypes type = PlayerTypes::air;
    AirVehicle(int speed_) : Vehicle(speed_) {}
};

class MagicCarpet : public AirVehicle {
    // Ковер самолет
public:
    MagicCarpet() : AirVehicle(10) {};
    float get_time_for_distance (int distance) override {
        float time = distance / speed;
        if (distance < 1000) {
            return time;
        } else if (distance < 5000) {
            return time * 0.97;
        } else if (distance < 10000) {
            return time * 0.9;
        } else {
            return time * 0.95;
        }
    }
};

class Eagle : public AirVehicle {
    // Орел
public:
    Eagle() : AirVehicle(8) {};
    float get_time_for_distance (int distance) override {
        return 0.94 * distance / speed;
    }
};

class Broom : public AirVehicle {
    // Метла
public:
    Broom() : AirVehicle(20) {};
    float get_time_for_distance (int distance) override {
        return (1 - (distance/1000)/100.0) * distance / speed;
    }
};

class NotEnoughPlayers : public std::exception {
public:
    const char* what() const noexcept override {
        return "Должно быть зарегистрировано хотя бы 2 транспортных средства";
    }
};

class WrongPlayerType : public std::exception {
public:
    const char* what() const noexcept override {
        return "Попытка зарегистрировать неверный типа транспортного средства";
    }
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
    int players_number = 0;
    Player* players = new Player[max_players];
    
public:
    Game(int distance_, int max_players_) {
        distance = distance_;
        max_players = max_players_;
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

class LandGame : public Game {
    // наземная гонка
public:
    LandGame(int distance_, int max_players_) : Game(distance_, max_players_) {}
    void add_player(LandVehicle* player) {
        if (player->type != PlayerTypes::land) {
            throw WrongPlayerType();
        } else {
            this->players_number += 1;
            this->players[players_number - 1].vehicle = player;
            this->players[players_number - 1].time = 0;
        }
    }
};

class AirGame : public Game {
    // наземная гонка
public:
    AirGame(int distance_, int max_players_) : Game(distance_, max_players_) {}
    void add_player(AirVehicle* player) {
        if (player->type != PlayerTypes::air) {
            throw WrongPlayerType();
        } else {
            this->players_number += 1;
            this->players[players_number - 1].vehicle = player;
            this->players[players_number - 1].time = 0;
        }
    }
};

class MixedGame : public Game {
    // наземная гонка
public:
    MixedGame(int distance_, int max_players_) : Game(distance_, max_players_) {}
    void add_player(Vehicle* player) {
        this->players_number += 1;
        this->players[players_number - 1].vehicle = player;
        this->players[players_number - 1].time = 0;
    }
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
    
//    AirGame game = AirGame(test_distance, 7);
//    LandGame game = LandGame(test_distance, 7);
    MixedGame game = MixedGame(test_distance, 7);


    game.add_player(&camel);
    game.add_player(&centaur);
    game.add_player(&fast_camel);
    game.play();
    Player* results = game.get_players();
    for (int i=0; i<3; ++i) {
        std::cout << results[i].vehicle->name << " " << results[i].time << std::endl;
    }
    return 0;
}
