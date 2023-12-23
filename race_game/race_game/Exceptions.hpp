//
//  Exceptions.hpp
//  race_game
//
//  Created by tkvitko on 20.12.2023.
//

#ifdef RACELIB_EXPORTS
#define RACELIB_API __declspec(dllexport)
#else
#define RACELIB_API __declspec(dllimport)
#endif

#ifndef Exceptions_hpp
#define Exceptions_hpp

#include <stdio.h>
#include <exception>

class NotEnoughPlayers : public std::exception {
public:
    const char* what() const noexcept override;
};

class WrongPlayerType : public std::exception {
public:
    const char* what() const noexcept override;
};

class PlayerAlreadyRegistered : public std::exception {
public:
    const char* what() const noexcept override;
};

#endif /* Exceptions_hpp */
