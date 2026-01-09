#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int cellSize;
    int boardSize = 8;

    cout << "¬ведите размер клетки: ";
    cin >> cellSize;

    for (int row = 0; row < boardSize * cellSize; row++) {
        int cellRow = row / cellSize;

        for (int col = 0; col < boardSize * cellSize; col++) {
            int cellCol = col / cellSize;

            if ((cellRow + cellCol) % 2 == 0) {
                cout << '*';
            }
            else {
                cout << '-';
            }
        }
        cout << endl;
    }

    return 0;
}