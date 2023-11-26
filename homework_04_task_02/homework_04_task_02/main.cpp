#include <iostream>
#include <string>
#include <fstream>

class Address {

private:
    std::string street;
    int building_number;
    int apartment_number;
    
public:
    std::string city;
    
    Address () {};
    Address (std::string _city, std::string _street, int _building_number, int _apartment_number) {
        this->city = _city;
        this->street = _street;
        this->building_number = _building_number;
        this->apartment_number = _apartment_number;
    };
    
    std::string get_formatted_address() {
        // функция вывода данных адреса в нужном формате
        std::string delimiter = ", ";
        return this->city + delimiter + this->street + delimiter + std::to_string(this->building_number) + delimiter + std::to_string(this->apartment_number) + "\n";
    };
};


bool compare_address(Address &address1, Address &address2)
{
    if (address2.city > address1.city) {
        return 1;
    } else {
        return 0;
    }
}


int main() {
    
    // получение количества адресов из файла
    int addresses_count = 0;
    std::ifstream source_file("/Users/tkvitko/c/netology/xcode_projects/homework_04_task_02/homework_04_task_02/in.txt");
    if ( ! source_file.is_open()  ) {
            std::cerr << "open source failed" << std::endl;
            return 1;
        }
    else {
    source_file >> addresses_count;
        }
    
    // создание массива для хранения объектов адресов
    Address* addresses = new Address[addresses_count];
    
    // заполнение массива объектами адресов
    for (int i = 0; i < addresses_count; ++i) {

        // инициализация переменных для хранения
        std::string current_city;
        std::string current_street;
        int current_building_number;
        int current_apartment_number;

        // чтение данных их файла
        source_file >> current_city;
        source_file >> current_street;
        source_file >> current_building_number;
        source_file >> current_apartment_number;

        // создание объекта и помещение его в массив
        addresses[i] = Address(current_city, current_street, current_building_number, current_apartment_number);
    };

    // сортировка адресов
    std::sort(addresses, addresses+addresses_count, &compare_address);

    
    // открытие выходного файла для записи данных
    std::ofstream target_file("/Users/tkvitko/c/netology/xcode_projects/homework_04_task_02/homework_04_task_02/out.txt");
    if ( ! target_file.is_open()  ) {
            std::cerr << "open target failed" << std::endl;
            return 1;
        }
    else {
        target_file << addresses_count << std::endl;
        for (int i = 0; i < addresses_count; ++i) {
            target_file << addresses[i].get_formatted_address();
        }
    };
    
    // очистка памяти
    delete[] addresses;
    return 0;
}
