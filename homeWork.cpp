#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream file("file1.txt");

    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    string line;
    int maxLength = 0;

    while (getline(file, line)) {
        int currentLength = line.length();
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }

    file.close();

    cout << "Длина самой длинной строки: " << maxLength << endl;

    return 0;
}