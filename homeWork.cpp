#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <Windows.h>

using namespace std;

string replaceAll(string str, const string& from, const string& to) {
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string searchWord, replaceWord;

    cout << "Введите слово для поиска: ";
    getline(cin, searchWord);

    cout << "Введите слово для замены: ";
    getline(cin, replaceWord);

    ifstream inputFile("file1.txt");
    if (!inputFile.is_open()) {
        cerr << "Ошибка открытия файла!" << endl;
        return 1;
    }

    stringstream buffer;
    buffer << inputFile.rdbuf();
    string content = buffer.str();
    inputFile.close();

    int count = 0;
    size_t pos = 0;
    while ((pos = content.find(searchWord, pos)) != string::npos) {
        count++;
        pos += searchWord.length();
    }

    content = replaceAll(content, searchWord, replaceWord);

    ofstream outputFile("file1.txt");
    if (!outputFile.is_open()) {
        cerr << "Ошибка записи в файл!" << endl;
        return 1;
    }

    outputFile << content;
    outputFile.close();

    cout << "Замена выполнена успешно!" << endl;
    cout << "Количество замен: " << count << endl;

    return 0;
}