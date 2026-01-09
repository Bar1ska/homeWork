#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Car {
    double length;
    double clearance;
    double engineVolume;
    int enginePower;
    double wheelDiameter;
    string color;
    string transmissionType;
};

void setCar(Car& car, double len, double clear, double engVol,
    int engPow, double wheelDiam, string col, string trans) {
    car.length = len;
    car.clearance = clear;
    car.engineVolume = engVol;
    car.enginePower = engPow;
    car.wheelDiameter = wheelDiam;
    car.color = col;
    car.transmissionType = trans;
}

void displayCar(const Car& car) {
    cout << "=== Характеристики автомобиля ===" << endl;
    cout << "Длина: " << car.length << " м" << endl;
    cout << "Клиренс: " << car.clearance << " см" << endl;
    cout << "Объем двигателя: " << car.engineVolume << " л" << endl;
    cout << "Мощность двигателя: " << car.enginePower << " л.с." << endl;
    cout << "Диаметр колес: " << car.wheelDiameter << " дюймов" << endl;
    cout << "Цвет: " << car.color << endl;
    cout << "Коробка передач: " << car.transmissionType << endl;
    cout << "=================================" << endl;
}

vector<int> findByColor(const vector<Car>& cars, const string& color) {
    vector<int> indices;
    for (size_t i = 0; i < cars.size(); i++) {
        if (cars[i].color == color) {
            indices.push_back(i);
        }
    }
    return indices;
}

vector<int> findByTransmission(const vector<Car>& cars, const string& trans) {
    vector<int> indices;
    for (size_t i = 0; i < cars.size(); i++) {
        if (cars[i].transmissionType == trans) {
            indices.push_back(i);
        }
    }
    return indices;
}

vector<int> findByPower(const vector<Car>& cars, int minPower) {
    vector<int> indices;
    for (size_t i = 0; i < cars.size(); i++) {
        if (cars[i].enginePower >= minPower) {
            indices.push_back(i);
        }
    }
    return indices;
}

int main() {
    setlocale(LC_ALL, "Russian");

    vector<Car> cars(3);

    setCar(cars[0], 4.5, 18.5, 2.0, 150, 17, "Красный", "Автомат");
    setCar(cars[1], 4.8, 20.0, 3.5, 249, 18, "Черный", "Механика");
    setCar(cars[2], 4.2, 16.0, 1.6, 110, 16, "Красный", "Автомат");

    cout << "\n--- ВСЕ АВТОМОБИЛИ ---\n" << endl;
    for (size_t i = 0; i < cars.size(); i++) {
        cout << "Автомобиль #" << i + 1 << endl;
        displayCar(cars[i]);
        cout << endl;
    }

    cout << "\n--- ПОИСК ---\n" << endl;

    cout << "Поиск красных автомобилей:" << endl;
    vector<int> redCars = findByColor(cars, "Красный");
    for (int idx : redCars) {
        cout << "Найден автомобиль #" << idx + 1 << endl;
    }
    cout << endl;

    cout << "Поиск автомобилей с автоматической коробкой:" << endl;
    vector<int> autoCars = findByTransmission(cars, "Автомат");
    for (int idx : autoCars) {
        cout << "Найден автомобиль #" << idx + 1 << endl;
    }
    cout << endl;

    cout << "Поиск автомобилей с мощностью >= 150 л.с.:" << endl;
    vector<int> powerfulCars = findByPower(cars, 150);
    for (int idx : powerfulCars) {
        cout << "Найден автомобиль #" << idx + 1 << endl;
    }

    return 0;
}