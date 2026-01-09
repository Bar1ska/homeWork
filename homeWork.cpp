#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

void insertColumn(vector<vector<int>>& array, int colIndex, const vector<int>& newColumn) {
    int numRows = array.size();

    
    if (newColumn.size() != numRows) {
        cout << "Длина вставляемого столбца должна быть равна количеству строк массива." << endl;
        return;
    }

    
    for (int i = 0; i < numRows; ++i) {
        if (colIndex < 0 || colIndex > array.size()) {
            cout << "Некорректный индекс столбца." << endl;
            return;
        }
        array.insert(array.begin() + colIndex, newColumn);
    }
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int rows, cols;
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;

    vector<vector<int>> array(rows, vector<int>(cols));
    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> array[i][j];
        }
    }

    int insertPos;
    cout << "Введите индекс позиции для вставки нового столбца (от 0 до " << cols << "): ";
    cin >> insertPos;

    vector<int> newColumn(rows);
    cout << "Введите элементы нового столбца:" << endl;
    for (int i = 0; i < rows; ++i) {
        cin >> newColumn[i];
    }

    insertColumn(array, insertPos, newColumn);

    cout << "Массив после вставки столбца:" << endl;
    for (const auto& row : array) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}
