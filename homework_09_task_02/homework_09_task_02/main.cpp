//
//  main.cpp
//  homework_09_task_02
//
//  Created by tkvitko on 09.12.2023.
//

#include <iostream>

class Fraction
{
private:
    int numerator_;
    int denominator_;
    
    int find_gcd(int num1, int num2) {
        // поиск наибольшего общего делителя двух чисел (применяется для сокращения дроби)
        int gcd, remainder;

        remainder = num1 % num2;
        while (remainder != 0) {
            num1 = num2;
            num2 = remainder;
            remainder = num1 % num2;
        }
        gcd = num2;
        return gcd;
    }

public:
    Fraction(int numerator, int denominator)
    {
        numerator_ = numerator;
        denominator_ = denominator;
    };
    friend void make_common_denominator(Fraction& fraction1, Fraction& fraction2);
    friend std::ostream& operator<<(std::ostream& left, Fraction right);
    
    void reduce() {
        // сокращение дроби
        int gcd;
        gcd = find_gcd(numerator_, denominator_);
        numerator_ /= gcd;
        denominator_ /= gcd;
    }
    
    Fraction operator+(Fraction other) {
        make_common_denominator(*this, other);
        Fraction res = Fraction(numerator_ + other.numerator_, denominator_);
        this->reduce();
        other.reduce();
        return res;
    };
    
    Fraction operator-(Fraction other) {
        make_common_denominator(*this, other);
        Fraction res =  Fraction(numerator_ - other.numerator_, denominator_);
        this->reduce();
        other.reduce();
        return res;
    };
    
    Fraction operator*(Fraction other) {
        Fraction res = Fraction(numerator_ * other.numerator_, denominator_ * other.denominator_);
        res.reduce();
        return res;
    };
    
    Fraction operator/(Fraction other) {
        Fraction res = Fraction(numerator_ * other.denominator_, denominator_ * other.numerator_);
        res.reduce();
        return res;
    };
    
    Fraction operator-() {
        return Fraction(-numerator_, denominator_);
    };
    
    Fraction operator++() {
        Fraction one_as_fraction = Fraction(1, 1);
        return *this + one_as_fraction;
    };
    
    Fraction operator++(int) {
        Fraction temp = *this;
        ++(*this);
        return temp;
    };
    
    Fraction operator--() {
        Fraction one_as_fraction = Fraction(1, 1);
        return *this - one_as_fraction;
    };
    
    Fraction operator--(int) {
        Fraction temp = *this;
        --(*this);
        return temp;
    };
    
};

std::ostream& operator<<(std::ostream& left, Fraction right) {
    std::cout << right.numerator_ << "/" << right.denominator_;
    return left;
}

void make_common_denominator(Fraction& fraction1, Fraction& fraction2) {
    // приведение двух дробей к общему знаменателю
    int common_denominator = fraction1.denominator_ * fraction2.denominator_;
    int new_first_numerator = fraction1.numerator_ * fraction2.denominator_;
    int new_second_numerator = fraction2.numerator_ * fraction1.denominator_;
    
    fraction1.numerator_ = new_first_numerator;
    fraction2.numerator_ = new_second_numerator;
    fraction1.denominator_ = fraction2.denominator_ = common_denominator;
}

int main()
{
    int numerator1 = 0;
    int numerator2 = 0;
    int denominator1 = 0;
    int denominator2 = 0;

    std::cout << "Введите числитель дроби 1: ";
    std::cin >> numerator1;
    std::cout << "Введите знаменатель дроби 1: ";
    std::cin >> denominator1;
    std::cout << "Введите числитель дроби 2: ";
    std::cin >> numerator2;
    std::cout << "Введите знаменатель дроби 2: ";
    std::cin >> denominator2;
    
    Fraction f1 = Fraction(numerator1, denominator1);
    Fraction f2 = Fraction(numerator2, denominator2);
    
    std::cout << f1 << " + " << f2 << " = " << f1 + f2 << std::endl;
    std::cout << f1 << " - " << f2 << " = " << f1 - f2 << std::endl;
    std::cout << f1 << " * " << f2 << " = " << f1 * f2 << std::endl;
    std::cout << f1 << " / " << f2 << " = " << f1 / f2 << std::endl;
    std::cout << "++" << f1 << " * " << f2 << " = " << ++f1 * f2 << std::endl;
    std::cout << "Значение дроби 1 = " << f1 << std::endl;
    std::cout << f1 << "--" << " * " << f2 << " = " << f1-- * f2 << std::endl;
    std::cout << "Значение дроби 1 = " << f1 << std::endl;
    return 0;
}
