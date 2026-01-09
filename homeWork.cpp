#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size, min_value, max_value, threshold;

    std::cout << "¬ведите размер массива: ";
    std::cin >> size;

    std::cout << "¬ведите минимальное значение диапазона: ";
    std::cin >> min_value;

    std::cout << "¬ведите максимальное значение диапазона: ";
    std::cin >> max_value;

    std::srand(std::time(nullptr));

    std::vector<int> array(size);
    for (int i = 0; i < size; ++i) {
        array[i] = min_value + std::rand() % (max_value - min_value + 1);
    }

    std::cout << "—генерированный массив: ";
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "¬ведите значение дл€ сравнени€: ";
    std::cin >> threshold;

    int sum = 0;
    for (int num : array) {
        if (num < threshold) {
            sum += num;
        }
    }

    std::cout << "—умма элементов, меньше указанный значени€: " << sum << std::endl;

    return 0;
}