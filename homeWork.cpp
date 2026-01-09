#include <iostream>
#include <vector>
#include <algorithm> 


void shiftRows(std::vector<std::vector<int>>& matrix, int numShifts, bool toRight) {
    int M = matrix.size();
    if (M == 0) return;
    int N = matrix.size();

    for (int i = 0; i < M; ++i) {
        int shift = numShifts % N;
        if (!toRight) shift = N - shift; 
        std::rotate(matrix.begin(), matrix.begin() + shift, matrix.end());
    }
}


void shiftColumns(std::vector<std::vector<int>>& matrix, int numShifts, bool downward) {
    int M = matrix.size();
    if (M == 0) return;
    int N = matrix.size();

    for (int j = 0; j < N; ++j) {
        int shift = numShifts % M;
        if (!downward) shift = M - shift; 
        std::vector<int> column(M);
        for (int i = 0; i < M; ++i) {
            column = matrix[i];
        }
        std::rotate(column.begin(), column.begin() + shift, column.end());
        for (int i = 0; i < M; ++i) {
            matrix[i] = column;
        }
    }
}

int main() {
    int M, N;
    std::cout << "Введите количество строк M: ";
    std::cin >> M;
    std::cout << "Введите количество столбцов N: ";
    std::cin >> N;

    std::vector<std::vector<int>> matrix(M, std::vector<int>(N));

    
    std::cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    int numShifts;
    char direction;
    std::cout << "Введите количество сдвигов: ";
    std::cin >> numShifts;
    std::cout << "Сдвигать строки или столбцы? (s для строк, c для столбцов): ";
    char axis;
    std::cin >> axis;
    bool shiftRightOrDown = true;
    std::cout << "Направление сдвига? (r для вправо или вниз, l для влево или вверх): ";
    std::cin >> direction;

    if (axis == 's') {
        shiftRightOrDown = (direction == 'r');
        shiftRows(matrix, numShifts, shiftRightOrDown);
    }
    else if (axis == 'c') {
        shiftRightOrDown = (direction == 'd'); 
        if (direction == 'd') shiftRightOrDown = true;
        else if (direction == 'u') shiftRightOrDown = false;
        shiftColumns(matrix, numShifts, shiftRightOrDown);
    }

    std::cout << "Изменённая матрица:\n";
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            std::cout << elem << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
