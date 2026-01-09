#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <Windows.h>

using namespace std;

const int MAX_SIZE = 10000;

void findAndReplace(char* text, const char* oldWord, const char* newWord) {
    char result[MAX_SIZE] = "";
    char* pos = text;
    char* found;
    int oldLen = strlen(oldWord);
    int newLen = strlen(newWord);

    while ((found = strstr(pos, oldWord)) != nullptr) {
        strncat(result, pos, found - pos);
        strcat(result, newWord);
        pos = found + oldLen;
    }
    strcat(result, pos);
    strcpy(text, result);
}

void capitalizeSentences(char* text) {
    bool newSentence = true;

    for (int i = 0; text[i] != '\0'; i++) {
        if (newSentence && isalpha(text[i])) {
            text[i] = toupper(text[i]);
            newSentence = false;
        }

        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            newSentence = true;
        }
    }
}

void countLetters(const char* text) {
    int letters[256] = { 0 };

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char ch = tolower(text[i]);
            letters[(unsigned char)ch]++;
        }
    }

    cout << "\n=== Статистика букв ===" << endl;
    for (int i = 0; i < 256; i++) {
        if (letters[i] > 0) {
            cout << (char)i << ": " << letters[i] << endl;
        }
    }
}

void countDigits(const char* text) {
    int digits[10] = { 0 };
    int totalDigits = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (isdigit(text[i])) {
            digits[text[i] - '0']++;
            totalDigits++;
        }
    }

    cout << "\n=== Статистика цифр ===" << endl;
    for (int i = 0; i < 10; i++) {
        if (digits[i] > 0) {
            cout << i << ": " << digits[i] << endl;
        }
    }
    cout << "Всего цифр: " << totalDigits << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    char text[MAX_SIZE];
    char oldWord[100], newWord[100];

    ifstream inputFile("file1.txt");
    if (!inputFile.is_open()) {
        cout << "Ошибка открытия файла file1.txt" << endl;
        return 1;
    }

    text[0] = '\0';
    char line[1000];
    while (inputFile.getline(line, 1000)) {
        strcat(text, line);
        strcat(text, " ");
    }
    inputFile.close();

    cout << "Исходный текст:\n" << text << endl;

    cout << "\nВведите слово для замены: ";
    cin >> oldWord;
    cout << "Введите новое слово: ";
    cin >> newWord;

    findAndReplace(text, oldWord, newWord);
    cout << "\nТекст после замены:\n" << text << endl;

    capitalizeSentences(text);
    cout << "\nТекст с заглавными буквами в начале предложений:\n" << text << endl;

    countLetters(text);

    countDigits(text);

    ofstream outputFile("file2.txt");
    if (outputFile.is_open()) {
        outputFile << text;
        outputFile.close();
        cout << "\nРезультат сохранен в файл file2.txt" << endl;
    }

    return 0;
}