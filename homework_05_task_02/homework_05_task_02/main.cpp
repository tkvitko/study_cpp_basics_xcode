//
//  main.cpp
//  homework_05_task_02
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
    virtual void print_info() {
        std::cout << this->name << ":\n";
    }
};

class Triangle : public Figure {

protected:
    int a, b, c;
    int A, B, C;
    
public:
    Triangle(int a_, int b_, int c_, int A_, int B_, int C_) {
        name = "Треугольник";
        sides_count = 3;
        a = a_;
        b = b_;
        c = c_;
        A = A_;
        B = B_;
        C = C_;
    };
    void print_info() override {
        std::cout << this->name << ":\n" << "Стороны: a=" << this->a << " b=" << this->b << " c=" << this->c << "\nУглы: A=" << this->A << " B=" << this->B << " C=" << this->C << "\n\n";
    }
};

class RightTriangle : public Triangle {
    // прямоугольный треугольник
public:
    RightTriangle(int a_, int b_, int c_, int A_, int B_) : Triangle(a_, b_, c_, A_, B_, 90) {
        name = "Прямоугольный треугольник";
    }
};

class IsoscelesTriangle : public Triangle {
    // равнобедренный треугольник
public:
    IsoscelesTriangle(int a_, int b_, int A_, int B_) : Triangle(a_, b_, a_, A_, B_, A_) {
        name = "Равнобедренный треугольник";
    }
};

class EquilateralTriangle : public IsoscelesTriangle {
    // равносторонний треугольник
public:
    EquilateralTriangle(int a_) : IsoscelesTriangle(a_, a_, 60, 60) {
        name = "Равносторонний треугольник";
    }
};

class Quadrilateral : public Triangle {
    
protected:
    int d;
    int D;
    
public:
    Quadrilateral(int a_, int b_, int c_, int d_, int A_, int B_, int C_, int D_) : Triangle(a_, b_, c_, A_, B_, C_) {
        name = "Четырехугольник";
        sides_count = 4;
        d = d_;
        D = D_;
    };
    void print_info() override {
        std::cout << this->name << ":\n" << "Стороны: a=" << this->a << " b=" << this->b << " c=" << this->c << " d=" << this->d << "\nУглы: A=" << this->A << " B=" << this->B << " C=" << this->C << " D=" << this->D << "\n\n";
    }
};

class Rectangle : public Quadrilateral {
    // прямоугольник
public:
    Rectangle(int a_, int b_) : Quadrilateral(a_, b_, a_, b_, 90, 90, 90, 90) {
        name = "Прямоугольник";
    }
};

class Square : public Rectangle {
    // квадрат
public:
    Square(int a_) : Rectangle(a_, a_) {
        name = "Квадрат";
    }
};

class Parallelogram : public Quadrilateral {
    // параллелограмм
public:
    Parallelogram(int a_, int b_, int A_, int B_) : Quadrilateral(a_, b_, a_, b_, A_, B_, A_, B_) {
        name = "Параллелограмм";
    }
};

class Rhombus : public Parallelogram {
    // ромб
public:
    Rhombus(int a_, int A_, int B_) : Parallelogram(a_, a_, A_, B_) {
        name = "Ромб";
    }
};

int main(int argc, const char * argv[]) {

    Triangle triangle = Triangle(10, 20, 30, 50, 60, 70);
    Figure* ptr_triangle = &triangle;
    ptr_triangle->print_info();
    
    RightTriangle right_triangle = RightTriangle(10, 20, 30, 50, 60);
    Figure* ptr_right_triangle = &right_triangle;
    ptr_right_triangle->print_info();
    
    IsoscelesTriangle isosceles_triangle = IsoscelesTriangle(10, 20, 50, 60);
    Figure* ptr_isosceles_triangle = &isosceles_triangle;
    ptr_isosceles_triangle->print_info();
    
    EquilateralTriangle equilateral_triangle = EquilateralTriangle(30);
    Figure* ptr_equilateral_triangle = &equilateral_triangle;
    ptr_equilateral_triangle->print_info();
    
    Quadrilateral quadrilateral = Quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    Figure* ptr_quadrilateral = &quadrilateral;
    ptr_quadrilateral->print_info();
    
    Rectangle rectangle = Rectangle(10, 20);
    Figure* ptr_rectangle = &rectangle;
    ptr_rectangle->print_info();
    
    Square square = Square(20);
    Figure* ptr_square = &square;
    ptr_square->print_info();
    
    Parallelogram parallelogram = Parallelogram(20, 30, 30, 40);
    Figure* ptr_parallelogram = &parallelogram;
    ptr_parallelogram->print_info();
    
    Rhombus rhombus = Rhombus(30, 30, 40);
    Figure* ptr_rhombus = &rhombus;
    ptr_rhombus->print_info();

    return 0;
}
