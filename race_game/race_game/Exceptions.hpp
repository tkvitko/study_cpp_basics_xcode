//
//  Exceptions.hpp
//  race_game
//
//  Created by tkvitko on 20.12.2023.
//

#ifndef Exceptions_hpp
#define Exceptions_hpp

#include <stdio.h>
#include <exception>

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

#endif /* Exceptions_hpp */
