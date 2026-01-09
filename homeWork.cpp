#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream file1("file1.txt");
    ifstream file2("file2.txt");

    if (!file1.is_open()) {
        cout << "Ошибка открытия файла file1.txt" << endl;
        return 1;
    }

    if (!file2.is_open()) {
        cout << "Ошибка открытия файла file2.txt" << endl;
        return 1;
    }

    string line1, line2;
    int lineNumber = 1;
    bool filesMatch = true;

    while (true) {
        bool hasLine1 = (bool)getline(file1, line1);
        bool hasLine2 = (bool)getline(file2, line2);

        if (hasLine1 != hasLine2) {
            cout << "Файлы имеют разное количество строк!" << endl;
            if (hasLine1) {
                cout << "Строка " << lineNumber << " в file1.txt: " << line1 << endl;
                cout << "Строка " << lineNumber << " в file2.txt: отсутствует" << endl;
            }
            else {
                cout << "Строка " << lineNumber << " в file1.txt: отсутствует" << endl;
                cout << "Строка " << lineNumber << " в file2.txt: " << line2 << endl;
            }
            filesMatch = false;
            break;
        }

        if (!hasLine1 && !hasLine2) {
            break;
        }

        if (line1 != line2) {
            cout << "Несовпадение в строке " << lineNumber << ":" << endl;
            cout << "file1.txt: " << line1 << endl;
            cout << "file2.txt: " << line2 << endl;
            filesMatch = false;
            break;
        }

        lineNumber++;
    }

    if (filesMatch) {
        cout << "Все строки в файлах совпадают!" << endl;
    }

    file1.close();
    file2.close();

    return 0;
}