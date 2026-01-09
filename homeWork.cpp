#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

struct Complex {
    double real;  
    double imag;  

    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }

    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        if (denominator == 0) {
            cout << "Ошибка: деление на ноль!" << endl;
            return Complex(0, 0);
        }
        return Complex(
            (real * other.real + imag * other.imag) / denominator,
            (imag * other.real - real * other.imag) / denominator
        );
    }

    void print() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i";
        else
            cout << real << " - " << -imag << "i";
    }
};

int main() {
    Complex c1(3, 4);   
    Complex c2(1, -2);  

    cout << "Первое число: ";
    c1.print();
    cout << endl;

    cout << "Второе число: ";
    c2.print();
    cout << endl << endl;

    Complex sum = c1 + c2;
    cout << "Сумма: ";
    sum.print();
    cout << endl;

    Complex diff = c1 - c2;
    cout << "Разность: ";
    diff.print();
    cout << endl;

    Complex prod = c1 * c2;
    cout << "Произведение: ";
    prod.print();
    cout << endl;

    Complex quot = c1 / c2;
    cout << "Частное: ";
    quot.print();
    cout << endl;

    return 0;
}