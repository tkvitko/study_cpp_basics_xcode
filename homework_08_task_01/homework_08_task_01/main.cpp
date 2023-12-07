//
//  main.cpp
//  homework_08_task_01
//
//  Created by tkvitko on 06.12.2023.
//

#include <iostream>
#include <string>


class BadLength : public std::exception {
public:
    const char* what() const noexcept override {
        return "Запрещенная длина";
    }
};

int get_word_len(std::string str, int forbidden_length) {
    auto str_len = str.length();
    int str_len_int = static_cast<int>(str_len) / 2;
    if (str_len_int==forbidden_length) {
        throw BadLength();
    };
    return str_len_int;
}

int main(int argc, const char * argv[]) {
    int forbidden_len = 0;
    std::cout << "Введите запретную длину: ";
    std::cin >> forbidden_len;
    
    int len_of_entered_word = 0;
    while (len_of_entered_word != forbidden_len) {
        std::string entered_word;
        std::cout << "Введите слово: ";
        std::cin >> entered_word;
        
        try {
            len_of_entered_word = get_word_len(entered_word, forbidden_len);
            std::cout << "Длина слова " << entered_word << " равна " << len_of_entered_word << std::endl;
        } catch (const BadLength& e) {
            std::cout << "Вы ввели слово запретной длины! До свидания" << std::endl;
            break;
        }
    }
    return 0;
}
