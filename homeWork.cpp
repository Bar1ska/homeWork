#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <Windows.h>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'а' || c == 'е' || c == 'ё' || c == 'и' || c == 'о' ||
        c == 'у' || c == 'ы' || c == 'э' || c == 'ю' || c == 'я');
}

bool isConsonant(char c) {
    c = tolower(c);
    if ((c >= 'a' && c <= 'z') && !isVowel(c)) {
        return true;
    }
    if ((c >= 'а' && c <= 'я') || c == 'ё') {
        return !isVowel(c);
    }
    return false;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream inputFile("file1.txt");
    if (!inputFile.is_open()) {
        cerr << "Ошибка открытия входного файла!" << endl;
        return 1;
    }

    int charCount = 0;      
    int lineCount = 0;      
    int vowelCount = 0;     
    int consonantCount = 0; 
    int digitCount = 0;     

    string line;

    while (getline(inputFile, line)) {
        lineCount++;

        for (char c : line) {
            charCount++;

            if (isdigit(c)) {
                digitCount++;
            }
            else if (isVowel(c)) {
                vowelCount++;
            }
            else if (isConsonant(c)) {
                consonantCount++;
            }
        }
    }

    inputFile.close();

    ofstream outputFile("file2.txt");
    if (!outputFile.is_open()) {
        cerr << "Ошибка создания выходного файла!" << endl;
        return 1;
    }

    outputFile << "=== Статистика файла file1.txt ===" << endl;
    outputFile << "Количество символов: " << charCount << endl;
    outputFile << "Количество строк: " << lineCount << endl;
    outputFile << "Количество гласных букв: " << vowelCount << endl;
    outputFile << "Количество согласных букв: " << consonantCount << endl;
    outputFile << "Количество цифр: " << digitCount << endl;

    outputFile.close();

    cout << "Статистика успешно записана в файл file2.txt" << endl;

    return 0;
}