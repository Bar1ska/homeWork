#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string searchWord, word;
    int count = 0;

    cout << "Введите слово для поиска: ";
    cin >> searchWord;

    ifstream file("file1.txt");

    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    while (file >> word) {
        word.erase(remove_if(word.begin(), word.end(),
            [](char c) { return !isalnum(c); }),
            word.end());

        transform(word.begin(), word.end(), word.begin(), ::tolower);
        transform(searchWord.begin(), searchWord.end(),
            searchWord.begin(), ::tolower);

        if (word == searchWord) {
            count++;
        }
    }

    file.close();

    // Вывод результата
    cout << "Слово \"" << searchWord << "\" встречается "
        << count << " раз(а)" << endl;

    return 0;
}