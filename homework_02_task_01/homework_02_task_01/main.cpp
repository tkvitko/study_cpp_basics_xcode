#include <iostream>

enum months {
   und = 0,
   jan = 1,
   feb = 2,
   mar = 3,
   apr = 4,
   may = 5,
   jun = 6,
   jul = 7,
   aug = 8,
   sep = 9,
   oct = 10,
   nov = 11,
   dec = 12
};

int main() {
   int user_number = -1;
   bool working = true;

   while (working) {

      std::cout << "Введите номер месяца: ";
      std::cin >> user_number;
      months month = static_cast<months>(user_number);
      
      switch (month) {
         case months::und:
            std::cout << "До свидания!" << std::endl;
            working = false;
            break;
         case months::jan:
            std::cout << "Январь" << std::endl;
            break;
         case months::feb:
            std::cout << "Февраль" << std::endl;
            break;
         case months::mar:
            std::cout << "Март" << std::endl;
            break;
         case months::apr:
            std::cout << "Апрель" << std::endl;
            break;
         case months::may:
            std::cout << "Май" << std::endl;
            break;
         case months::jun:
            std::cout << "Июнь" << std::endl;
            break;
         case months::jul:
            std::cout << "Июль" << std::endl;
            break;
         case months::aug:
            std::cout << "Август" << std::endl;
            break;
         case months::sep:
            std::cout << "Сентябрь" << std::endl;
            break;
         case months::oct:
            std::cout << "Октябрь" << std::endl;
            break;
         case months::nov:
            std::cout << "Ноябрь" << std::endl;
            break;
         case months::dec:
            std::cout << "Декабрь" << std::endl;
            break;
         default:
               std::cout << "Неправильный номер!" << "\n";
               break;
      }
   }
   return 0;
}
