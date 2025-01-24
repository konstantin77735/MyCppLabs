#include "WorkTimeTable.h"
#include <windows.h>
#include <iostream>
#include <limits>
#include <vector>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<WorkTimeTable> tables;

    int n;
    std::cout << "Введите количество сотрудников: ";
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < n; ++i) {
        std::cout << "Сотрудник #" << i + 1 << ":\n";
        WorkTimeTable table; // Обратите внимание: используется WorkTimeTable
        table.input();
        tables.push_back(table);
    }

    std::string sortProperty;
    bool ascending;
    std::cout << "\nВведите свойство для сортировки (name, arrival, departure): ";
    std::cin >> sortProperty;
    std::cout << "Сортировать по возрастанию? (1 - да, 0 - нет): ";
    std::cin >> ascending;

    WorkTimeTable::sort(tables, sortProperty, ascending);

    std::cout << "\nОтсортированный список:\n";
    for (const auto& table : tables) {
        table.print();
    }

    std::cin.ignore();
    std::string searchKey;
    std::cout << "\nВведите ключ для поиска: ";
    std::getline(std::cin, searchKey);

    WorkTimeTable* result = WorkTimeTable::search(tables, searchKey);
    if (result) {
        std::cout << "\nНайденный сотрудник:\n";
        result->print();
        delete result;
    } else {
        std::cout << "\nСотрудник не найден.\n";
    }

    return 0;
}
