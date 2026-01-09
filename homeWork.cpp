#include <iostream>
#include <limits>
#include <string>
#include <Windows.h>
using namespace std;

void menu() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Ввести число\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            long long num;
            cout << "Введите число: ";
            cin >> num;

            // Обработка отрицательных чисел
            long long abs_num = (num < 0) ? -num : num;

            int digitCount = 0;
            int zeroCount = 0;
            long long sumDigits = 0;
            long long temp = abs_num;

            if (temp == 0) {
                digitCount = 1;
                zeroCount = 1;
                sumDigits = 0;
            }
            else {
                while (temp > 0) {
                    int digit = temp % 10;
                    sumDigits += digit;
                    if (digit == 0)
                        zeroCount++;
                    digitCount++;
                    temp /= 10;
                }
            }

            double average = (digitCount != 0) ? static_cast<double>(sumDigits) / digitCount : 0;

            cout << "Количество цифр: " << digitCount << endl;
            cout << "Сумма цифр: " << sumDigits << endl;
            cout << "Среднее арифметическое: " << average << endl;
            cout << "Количество нулей: " << zeroCount << endl;

            break;
        }
        case 0:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Некорректный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}
