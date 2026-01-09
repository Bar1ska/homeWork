#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string inputFileName = "file1.txt";
    string outputFileName = "file2.txt";

    ifstream inputFile(inputFileName);

    if (!inputFile.is_open()) {
        cerr << "Ошибка открытия файла " << inputFileName << endl;
        return 1;
    }

    vector<string> lines;
    string line;

    while (getline(inputFile, line)) {
        lines.push_back(line);
    }

    inputFile.close();

    if (lines.empty()) {
        cout << "Файл пустой, нечего удалять" << endl;
        return 0;
    }

    ofstream outputFile(outputFileName);

    if (!outputFile.is_open()) {
        cerr << "Ошибка открытия файла " << outputFileName << endl;
        return 1;
    }

    for (size_t i = 0; i < lines.size() - 1; i++) {
        outputFile << lines[i] << endl;
    }

    outputFile.close();

    cout << "Последняя строка удалена. Результат записан в " << outputFileName << endl;

    return 0;
}