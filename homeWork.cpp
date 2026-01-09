#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int count = 0;

    for (int num = 100; num <= 999; num++) {
        int digit1 = num / 100;        
        int digit2 = (num / 10) % 10;  
        int digit3 = num % 10;         

        if (digit1 == digit2 || digit1 == digit3 || digit2 == digit3) {
            count++;
        }
    }

    cout << "Количество чисел с двумя одинаковыми цифрами: " << count << endl;

    return 0;
}