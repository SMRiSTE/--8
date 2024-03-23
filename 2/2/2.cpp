#include <iostream>

class Fraction {

private:
    int numerator;
    int denominator;

public:
    Fraction(int num = 0, int den = 1){
        numerator = num;
        denominator = den;
    }

    Fraction operator+(const Fraction& other) {
        return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) {
        return Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    Fraction operator-() {
        return Fraction(-numerator, denominator);
    }

    Fraction& operator++() {
        numerator += denominator;
        return *this;
    }

    Fraction operator++(int) {
        Fraction temp = *this;
        numerator += denominator;
        return temp;
    }

    Fraction& operator--() {
        numerator -= denominator;
        return *this;
    }

    Fraction operator--(int) {
        Fraction temp = *this;
        numerator -= denominator;
        return temp;
    }

    friend std::ostream& operator<<(std::ostream& left, const Fraction& right) {
        left << right.numerator << "/" << right.denominator;
        return left;
    }

    void print() {
        std::cout << numerator << '/' << denominator <<  std::endl;
    }


};

int main() {
    setlocale(LC_ALL, "Russian");

    int num1, den1, num2, den2;
    std::cout << "Введите числитель дроби 1: ";
    std::cin >> num1;
    std::cout << "Введите числитель дроби 1: ";
    std::cin >> den1;

    std::cout << "Введите знаменатель дроби 2: ";
    std::cin >> num2;
    std::cout << "Введите знаменатель дроби 2: ";
    std::cin >> den2;

    Fraction f1(num1, den1);
    Fraction f2(num2, den2);

    Fraction sum = f1 + f2;
    Fraction sub = f1 - f2;
    Fraction mult = f1 * f2;
    Fraction div = f1 / f2;

    std::cout << f1 << " + " << f2 << " = ";
    sum.print();

    std::cout << f1 << " - " << f2 << " = ";
    sub.print();

    std::cout << f1 << " * " << f2 << " = ";
    mult.print();

    std::cout << f1 << " / " << f2 << " = ";
    div.print();

    std::cout << "++" << f1 << " * " << f2 << " = ";
    (++f1).print();

    std::cout << "Значение дроби 1 = ";
    f1.print();

    std::cout << f1 << "--" << " * " << f2 << " = ";
    (f1-- * f2).print();

    std::cout << "Значение дроби 1 = ";
    f1.print();

    return 0;
}