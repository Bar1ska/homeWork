#include <iostream>
#include <fstream>
#include <string>
#include <codecvt>
#include <Windows.h>

using namespace std;

wchar_t encryptChar(wchar_t ch, int key) {
    wstring lowerRus = L"абвгдежзийклмнопрстуфхцчшщъыьэюя";
    wstring upperRus = L"АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";

    size_t pos = lowerRus.find(ch);
    if (pos != wstring::npos) {
        int newPos = (pos + key) % lowerRus.length();
        return lowerRus[newPos];
    }

    pos = upperRus.find(ch);
    if (pos != wstring::npos) {
        int newPos = (pos + key) % upperRus.length();
        return upperRus[newPos];
    }

    return ch;
}

wstring encryptText(const wstring& text, int key) {
    wstring result;
    for (wchar_t ch : text) {
        result += encryptChar(ch, key);
    }
    return result;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int key;

    cout << "Введите ключ шифрования (число): ";
    cin >> key;

    wifstream inputFile("file1.txt");
    inputFile.imbue(locale(inputFile.getloc(),
        new codecvt_utf8<wchar_t>));

    if (!inputFile.is_open()) {
        cerr << "Ошибка открытия входного файла!" << endl;
        return 1;
    }

    wstring text, line;
    while (getline(inputFile, line)) {
        text += line + L"\n";
    }
    inputFile.close();

    wstring encryptedText = encryptText(text, key);

    wofstream outputFile("file2.txt");
    outputFile.imbue(locale(outputFile.getloc(),
        new codecvt_utf8<wchar_t>));

    if (!outputFile.is_open()) {
        cerr << "Ошибка открытия выходного файла!" << endl;
        return 1;
    }

    outputFile << encryptedText;
    outputFile.close();

    cout << L"Текст успешно зашифрован и записан в файл: file2.txt" << endl;

    return 0;
}