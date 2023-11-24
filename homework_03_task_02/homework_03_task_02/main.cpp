#include <iostream>
#include <string>

class Counter {
    
private:
    int counter;

public:

    Counter() {
        this->counter = 1;
    }

    Counter(int counter) {
        this->counter = counter;
    }

    void increment() {
        this->counter += 1;
    }

    void decrement() {
        this->counter -= 1;
    }

    int get_current_value() {
        return this->counter;
    }
};

int main() {
    bool create_with_user_value;
    std::string user_answer;
    
    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> user_answer;
    if (user_answer == "да") {
        create_with_user_value = true;
    } else {
        create_with_user_value = false;
    };

    Counter counter;
    if (create_with_user_value) {
        int initial_value = 0;
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> initial_value;
        counter = Counter(initial_value);
    }

    char command;
    while (command != 'x') {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command;
        switch (command) {
            case '+':
                counter.increment();
                break;
            case '-':
                counter.decrement();
                break;
            case '=':
                std::cout << counter.get_current_value() << std::endl;
                break;
            default:
                break;
        };
    };
    std::cout << "До свидания!" << std::endl;
}
