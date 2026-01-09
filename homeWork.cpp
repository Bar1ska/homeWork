#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    long long number;
    cout << "Введите целое число: ";
    cin >> number;

    bool isNegative = false;
    if (number < 0) {
        isNegative = true;
        number = -number;
    }

    string numStr = to_string(number);
    string result = "";

    for (char digit : numStr) {
        if (digit != '3' && digit != '6') {
            result += digit;
        }
    }

    if (result.empty()) {
        cout << "Результат: 0" << endl;
    }
    else {
        if (isNegative) {
            cout << "Результат: -" << result << endl;
        }
        else {
            cout << "Результат: " << result << endl;
        }
    }

    return 0;
}