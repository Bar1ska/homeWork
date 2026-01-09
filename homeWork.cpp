#include <iostream>
#include <vector>
#include <Windows.h>

void deleteColumn(std::vector<std::vector<int>>& matrix, int colIndex) {
    for (auto& row : matrix) {
        if (colIndex >= 0 && colIndex < row.size()) {
            row.erase(row.begin() + colIndex);
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int rows, cols, colToRemove;

    std::cout << "Введите количество строк: ";
    std::cin >> rows;
    std::cout << "Введите количество столбцов: ";
    std::cin >> cols;

    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));

    std::cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < rows; ++i) {
        std::cout << "Строка " << i + 1 << ": ";
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::cout << "Введите номер столбца для удаления (от 0 до " << cols - 1 << "): ";
    std::cin >> colToRemove;

    deleteColumn(matrix, colToRemove);

    std::cout << "Матрица после удаления столбца:\n";
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
