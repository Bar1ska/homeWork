#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    const int size = 10; 
    std::vector<int> arr(size);

    
    std::srand(std::time(nullptr));

    
    for (int& num : arr) {
        num = std::rand() % 100; 
    }

    
    int min = arr[0];
    int max = arr[0];

    
    for (const int& num : arr) {
        if (num < min) min = num;
        if (num > max) max = num;
    }

    
    std::cout << "Массив: ";
    for (const int& num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\nМинимальный элемент: " << min << "\nМаксимальный элемент: " << max << std::endl;

    return 0;
}