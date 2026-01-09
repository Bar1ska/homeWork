#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int totalSize = 10;
    const int partSize = 5;
    int array;
    int firstArray, secondArray;

    std::srand(std::time(nullptr));

    for (int i = 0; i < totalSize; ++i) {
        array = std::rand() % 100;
    }

    for (int i = 0; i < partSize; ++i) {
        firstArray = array;
        secondArray = array;
    }

    std::cout << "Исходный массив: ";
    for (int i = 0; i < totalSize; ++i) {
        std::cout << array << " ";
    }
    std::cout << std::endl;

    std::cout << "Первый массив: ";
    for (int i = 0; i < partSize; ++i) {
        std::cout << firstArray << " ";
    }
    std::cout << std::endl;

    std::cout << "Второй массив: ";
    for (int i = 0; i < partSize; ++i) {
        std::cout << secondArray << " ";
    }
    std::cout << std::endl;

    return 0;
}
