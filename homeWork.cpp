#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <Windows.h>
using namespace std;

// Функция для проверки, является ли символ гласной буквой
bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'а' || c == 'е' || c == 'ё' || c == 'и' || c == 'о' ||
        c == 'у' || c == 'ы' || c == 'э' || c == 'ю' || c == 'я');
}

// Функция для проверки, является ли символ согласной буквой
bool isConsonant(char c) {
    c = tolower(c);
    // Английские согласные
    if ((c >= 'a' && c <= 'z') && !isVowel(c)) {
        return true;
    }
    // Русские согласные
    if ((c >= 'а' && c <= 'я') || c == 'ё') {
        return !isVowel(c);
    }
    return false;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Открываем входной файл
    ifstream inputFile("file1.txt");
    if (!inputFile.is_open()) {
        cerr << "Ошибка открытия входного файла!" << endl;
        return 1;
    }

    // Переменные для статистики
    int charCount = 0;      // Количество символов
    int lineCount = 0;      // Количество строк
    int vowelCount = 0;     // Количество гласных
    int consonantCount = 0; // Количество согласных
    int digitCount = 0;     // Количество цифр

    string line;

    // Читаем файл построчно
    while (getline(inputFile, line)) {
        lineCount++;

        // Анализируем каждый символ в строке
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

    // Создаём и записываем статистику в выходной файл
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