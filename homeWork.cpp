#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Employee {
    int id;
    string lastName;
    string firstName;
    int age;
    string position;
    double salary;
};

class EmployeeSystem {
private:
    vector<Employee> employees;
    int nextId;
    string filename;

public:
    EmployeeSystem() : nextId(1) {}

    void loadFromFile(const string& fname) {
        filename = fname;
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Файл не найден. Будет создан новый.\n";
            return;
        }

        Employee emp;
        while (file >> emp.id >> emp.lastName >> emp.firstName
            >> emp.age >> emp.position >> emp.salary) {
            employees.push_back(emp);
            if (emp.id >= nextId) nextId = emp.id + 1;
        }
        file.close();
        cout << "Загружено сотрудников: " << employees.size() << endl;
    }

    void saveToFile(const string& fname = "") {
        string saveFile = fname.empty() ? filename : fname;
        ofstream file(saveFile);
        if (!file.is_open()) {
            cout << "Ошибка сохранения файла!\n";
            return;
        }

        for (const auto& emp : employees) {
            file << emp.id << " " << emp.lastName << " "
                << emp.firstName << " " << emp.age << " "
                << emp.position << " " << emp.salary << "\n";
        }
        file.close();
        cout << "Данные сохранены в файл: " << saveFile << endl;
    }

    void addEmployee() {
        Employee emp;
        emp.id = nextId++;

        cout << "Фамилия: ";
        cin >> emp.lastName;
        cout << "Имя: ";
        cin >> emp.firstName;
        cout << "Возраст: ";
        cin >> emp.age;
        cout << "Должность: ";
        cin >> emp.position;
        cout << "Зарплата: ";
        cin >> emp.salary;

        employees.push_back(emp);
        cout << "Сотрудник добавлен с ID: " << emp.id << endl;
    }

    void editEmployee() {
        int id;
        cout << "Введите ID сотрудника для редактирования: ";
        cin >> id;

        for (auto& emp : employees) {
            if (emp.id == id) {
                cout << "Новая фамилия (текущая: " << emp.lastName << "): ";
                cin >> emp.lastName;
                cout << "Новое имя (текущее: " << emp.firstName << "): ";
                cin >> emp.firstName;
                cout << "Новый возраст (текущий: " << emp.age << "): ";
                cin >> emp.age;
                cout << "Новая должность (текущая: " << emp.position << "): ";
                cin >> emp.position;
                cout << "Новая зарплата (текущая: " << emp.salary << "): ";
                cin >> emp.salary;
                cout << "Данные обновлены!\n";
                return;
            }
        }
        cout << "Сотрудник с ID " << id << " не найден!\n";
    }

    void deleteEmployee() {
        int id;
        cout << "Введите ID сотрудника для удаления: ";
        cin >> id;

        auto it = remove_if(employees.begin(), employees.end(),
            [id](const Employee& emp) { return emp.id == id; });

        if (it != employees.end()) {
            employees.erase(it, employees.end());
            cout << "Сотрудник удален!\n";
        }
        else {
            cout << "Сотрудник с ID " << id << " не найден!\n";
        }
    }

    void searchByLastName() {
        string lastName;
        cout << "Введите фамилию: ";
        cin >> lastName;

        vector<Employee> found;
        for (const auto& emp : employees) {
            if (emp.lastName == lastName) {
                found.push_back(emp);
            }
        }

        if (found.empty()) {
            cout << "Сотрудники не найдены!\n";
        }
        else {
            displayEmployees(found);
            saveSearchResults(found);
        }
    }

    void searchByAge() {
        int age;
        cout << "Введите возраст: ";
        cin >> age;

        vector<Employee> found;
        for (const auto& emp : employees) {
            if (emp.age == age) {
                found.push_back(emp);
            }
        }

        if (found.empty()) {
            cout << "Сотрудники не найдены!\n";
        }
        else {
            displayEmployees(found);
            saveSearchResults(found);
        }
    }

    void searchByFirstLetter() {
        char letter;
        cout << "Введите первую букву фамилии: ";
        cin >> letter;

        vector<Employee> found;
        for (const auto& emp : employees) {
            if (!emp.lastName.empty() &&
                tolower(emp.lastName[0]) == tolower(letter)) {
                found.push_back(emp);
            }
        }

        if (found.empty()) {
            cout << "Сотрудники не найдены!\n";
        }
        else {
            displayEmployees(found);
            saveSearchResults(found);
        }
    }

    void displayAll() {
        if (employees.empty()) {
            cout << "Список сотрудников пуст!\n";
            return;
        }
        displayEmployees(employees);
    }

private:
    void displayEmployees(const vector<Employee>& emps) {
        cout << "\n" << string(80, '=') << endl;
        cout << "ID\tФамилия\t\tИмя\t\tВозраст\tДолжность\tЗарплата\n";
        cout << string(80, '=') << endl;

        for (const auto& emp : emps) {
            cout << emp.id << "\t" << emp.lastName << "\t\t"
                << emp.firstName << "\t\t" << emp.age << "\t"
                << emp.position << "\t\t" << emp.salary << endl;
        }
        cout << string(80, '=') << endl;
    }

    void saveSearchResults(const vector<Employee>& results) {
        char choice;
        cout << "Сохранить результаты в файл? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            string fname;
            cout << "Имя файла: ";
            cin >> fname;

            ofstream file(fname);
            for (const auto& emp : results) {
                file << emp.id << " " << emp.lastName << " "
                    << emp.firstName << " " << emp.age << " "
                    << emp.position << " " << emp.salary << "\n";
            }
            file.close();
            cout << "Результаты сохранены!\n";
        }
    }
};

int main() {
    EmployeeSystem system;
    string filename;

    cout << "=== Информационная система «Сотрудники» ===\n";
    cout << "Введите имя файла для загрузки данных: ";
    cin >> filename;
    system.loadFromFile(filename);

    int choice;
    do {
        cout << "\n--- МЕНЮ ---\n";
        cout << "1. Добавить сотрудника\n";
        cout << "2. Редактировать сотрудника\n";
        cout << "3. Удалить сотрудника\n";
        cout << "4. Поиск по фамилии\n";
        cout << "5. Поиск по возрасту\n";
        cout << "6. Поиск по первой букве фамилии\n";
        cout << "7. Показать всех сотрудников\n";
        cout << "8. Сохранить данные\n";
        cout << "0. Выход\n";
        cout << "Выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: system.addEmployee(); break;
        case 2: system.editEmployee(); break;
        case 3: system.deleteEmployee(); break;
        case 4: system.searchByLastName(); break;
        case 5: system.searchByAge(); break;
        case 6: system.searchByFirstLetter(); break;
        case 7: system.displayAll(); break;
        case 8: system.saveToFile(); break;
        case 0:
            system.saveToFile();
            cout << "Программа завершена. До свидания!\n";
            break;
        default:
            cout << "Неверный выбор!\n";
        }
    } while (choice != 0);

    return 0;
}