//
//  FigureCharacteristicsException.hpp
//  homework_08_task_02
//
//  Created by tkvitko on 07.12.2023.
//

#ifndef FigureCharacteristicsException_hpp
#define FigureCharacteristicsException_hpp

#include <stdio.h>
#include <string>


class BadDimention : public std::domain_error {
public:
    char* reason_;
    BadDimention(char* reason) : std::domain_error(reason) {
        this->reason_ = reason;
    };
    const char* what() const noexcept {
        return this->reason_;
    }
};

#endif /* FigureCharacteristicsException_hpp */
