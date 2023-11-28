//
//  main.cpp
//  homework_05_task_01
//
//  Created by tkvitko on 28.11.2023.
//

#include <iostream>
#include <string>

class Figure {
    
protected:
    int sides_count = 0;
    std::string name = "Фигура";

public:
    std::string get_description() {
        return this->name + ": " + std::to_string(this->sides_count) + "\n";

    }
};

class Triangle : public Figure {
public:
    Triangle() {
        name = "Треугольник";
        sides_count = 3;
    }
};

class Quadrilateral : public Figure {
public:
    Quadrilateral() {
        name = "Четырехугольник";
        sides_count = 4;
    }
};

int main(int argc, const char * argv[]) {
    
    Figure figure;
    Triangle triangle;
    Quadrilateral quadrilateral;
    
    std::cout << "Количество сторон:\n";
    std::cout << figure.get_description();
    std::cout << triangle.get_description();
    std::cout << quadrilateral.get_description();

    return 0;
}
