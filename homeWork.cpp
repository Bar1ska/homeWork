#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;

struct Contact {
    string name;
    string phone;
};

class PhoneBook {
private:
    vector<Contact> contacts;

public:
    void addContact() {
        Contact newContact;
        cout << "Введите имя: ";
        cin.ignore();
        getline(cin, newContact.name);
        cout << "Введите телефон: ";
        getline(cin, newContact.phone);
        contacts.push_back(newContact);
        cout << "Контакт добавлен успешно!\n";
    }

    void searchByName() {
        string name;
        cout << "Введите имя для поиска: ";
        cin.ignore();
        getline(cin, name);

        bool found = false;
        for (size_t i = 0; i < contacts.size(); i++) {
            if (contacts[i].name == name) {
                cout << "Найдено:\n";
                cout << "Имя: " << contacts[i].name << "\n";
                cout << "Телефон: " << contacts[i].phone << "\n";
                found = true;
            }
        }
        if (!found) {
            cout << "Контакт не найден.\n";
        }
    }

    void searchByPhone() {
        string phone;
        cout << "Введите телефон для поиска: ";
        cin.ignore();
        getline(cin, phone);

        bool found = false;
        for (size_t i = 0; i < contacts.size(); i++) {
            if (contacts[i].phone == phone) {
                cout << "Найдено:\n";
                cout << "Имя: " << contacts[i].name << "\n";
                cout << "Телефон: " << contacts[i].phone << "\n";
                found = true;
            }
        }
        if (!found) {
            cout << "Контакт не найден.\n";
        }
    }

    void editContact() {
        string name;
        cout << "Введите имя контакта для изменения: ";
        cin.ignore();
        getline(cin, name);

        for (size_t i = 0; i < contacts.size(); i++) {
            if (contacts[i].name == name) {
                cout << "Текущие данные:\n";
                cout << "Имя: " << contacts[i].name << "\n";
                cout << "Телефон: " << contacts[i].phone << "\n";

                cout << "\nВведите новое имя (или Enter для сохранения): ";
                string newName;
                getline(cin, newName);
                if (!newName.empty()) {
                    contacts[i].name = newName;
                }

                cout << "Введите новый телефон (или Enter для сохранения): ";
                string newPhone;
                getline(cin, newPhone);
                if (!newPhone.empty()) {
                    contacts[i].phone = newPhone;
                }

                cout << "Контакт обновлен!\n";
                return;
            }
        }
        cout << "Контакт не найден.\n";
    }

    void displayAll() {
        if (contacts.empty()) {
            cout << "Справочник пуст.\n";
            return;
        }

        cout << "\n=== Все контакты ===\n";
        for (size_t i = 0; i < contacts.size(); i++) {
            cout << i + 1 << ". " << contacts[i].name
                << " - " << contacts[i].phone << "\n";
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    PhoneBook phoneBook;
    int choice;

    do {
        cout << "\n=== Телефонный справочник ===\n";
        cout << "1. Добавить контакт\n";
        cout << "2. Поиск по имени\n";
        cout << "3. Поиск по телефону\n";
        cout << "4. Изменить контакт\n";
        cout << "5. Показать все контакты\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            phoneBook.addContact();
            break;
        case 2:
            phoneBook.searchByName();
            break;
        case 3:
            phoneBook.searchByPhone();
            break;
        case 4:
            phoneBook.editContact();
            break;
        case 5:
            phoneBook.displayAll();
            break;
        case 0:
            cout << "До свидания!\n";
            break;
        default:
            cout << "Неверный выбор!\n";
        }
    } while (choice != 0);

    return 0;
}