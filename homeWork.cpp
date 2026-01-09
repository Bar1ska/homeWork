#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size;
    std::cout << "Введите размер массивов: ";
    std::cin >> size;

    // Генерация диапазона для элементов
    int minVal, maxVal;
    std::cout << "Введите минимальное значение диапазона: ";
    std::cin >> minVal;
    std::cout << "Введите максимальное значение диапазона: ";
    std::cin >> maxVal;

    // Инициализация генератора случайных чисел
    std::srand(std::time(nullptr));

    std::vector<int> array1(size);
    std::vector<int> array2(size);
    std::vector<int> result(size);

    // Генерация массивов
    for (int i = 0; i < size; ++i) {
        array1[i] = minVal + std::rand() % (maxVal - minVal + 1);
        array2[i] = minVal + std::rand() % (maxVal - minVal + 1);
    }

    // Поэлементная сумма
    for (int i = 0; i < size; ++i) {
        result[i] = array1[i] + array2[i];
    }

    // Вывод результатов
    std::cout << "Массив 1: ";
    for (const auto& elem : array1) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::cout << "Массив 2: ";
    for (const auto& elem : array2) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::cout << "Результат (элементная сумма): ";
    for (const auto& elem : result) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}