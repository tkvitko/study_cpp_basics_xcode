#include <iostream>
#include <string>

struct address {
    std::string city;
    std::string street;
    int house;
    int apartment;
    int index;
};

void print_address(address& address) {
    std::cout << "Город: " << address.city << std::endl;
    std::cout << "Улица: " << address.street << std::endl;
    std::cout << "Номер дома: " << address.house << std::endl;
    std::cout << "Номер квартиры: " << address.apartment << std::endl;
    std::cout << "Индекс: " << address.index << "\n" << std::endl;
};

int main() {
    address address_1 = {"Москва", "Арбат", 12, 8, 123456};
    address address_2 = {"Ижевск", "Пушкина", 59, 143, 953769};

    print_address(address_1);
    print_address(address_2);
}
