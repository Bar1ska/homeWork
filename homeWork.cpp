#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

vector<vector<int>> transpose(const vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return {};
    }

    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> transposed(cols, vector<int>(rows));

    // Заполняем транспонированную матрицу
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    return transposed;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6}
    };

    cout << "Исходная матрица:" << endl;
    printMatrix(matrix);

    vector<vector<int>> transposed = transpose(matrix);

    cout << "\nТранспонированная матрица:" << endl;
    printMatrix(transposed);

    return 0;
}