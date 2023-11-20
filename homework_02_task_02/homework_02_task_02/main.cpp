#include <iostream>
#include <string>

struct account {
    int id;
    std::string owner;
    float balance;
};

void change_balance(account& account, float new_banalce) {
    account.balance = new_banalce;
};

int main() {
    account user_account;
    std::cout << "Введите номер счёта: ";
    std::cin >> user_account.id;
    std::cout << "Введите имя владельца: ";
    std::cin >> user_account.owner;
    std::cout << "Введите баланс: ";
    std::cin >> user_account.balance;

    float new_banalce = 0;
    std::cout << "Введите новый баланс: ";
    std::cin >> new_banalce;
    change_balance(user_account, new_banalce);

    std::cout << "Ваш счёт: " << user_account.owner << ", " << user_account.id << ", " << user_account.balance << std::endl;
    return 0;
}
