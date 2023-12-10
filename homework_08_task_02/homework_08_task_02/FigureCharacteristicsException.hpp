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

class BadDimention : public std::invalid_argument {
public:
    BadDimention(const std::string& what_arg): std::invalid_argument(what_arg) {}
    const char* what() const noexcept {
        return "Ошибка создания фигуры";
    }
};

#endif /* FigureCharacteristicsException_hpp */
