//
//  Exceptions.cpp
//  race_game
//
//  Created by tkvitko on 20.12.2023.
//

#include "Exceptions.hpp"

const char* NotEnoughPlayers::what() const noexcept {
    return "\nВнимание: Должно быть зарегистрировано хотя бы 2 транспортных средства";
};

const char* WrongPlayerType::what() const noexcept {
    return "\nВнимание: Попытка зарегистрировать неверный типа транспортного средства";
};

const char* PlayerAlreadyRegistered::what() const noexcept {
    return "\nВнимание: Этот тип уже зарегистрирован";
};
