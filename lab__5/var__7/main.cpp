#include "WorkTimeTable.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<WorkTimeTable> tables;

    int n;
    std::cout << "Введите количество сотрудников: ";
    std::cin >> n;
    std::cin.ignore();

    // Ввод данных
    for (int i = 0; i < n; ++i) {
        std::cout << "Сотрудник #" << i + 1 << ":\n";
        WorkTimeTable table;
        table.input();
        tables.push_back(table);
    }

    // Сортировка
    std::cout << "\nСортировка списка сотрудников...\n";
    WorkTimeTable::sort(tables);

    std::cout << "Отсортированный список:\n";
    for (const auto& table : tables) {
        table.print();
    }

    // Поиск сотрудника
    std::cin.ignore();
    std::string searchName;
    std::cout << "\nВведите имя для поиска: ";
    std::getline(std::cin, searchName);

    auto it = std::find_if(tables.begin(), tables.end(), [&](const WorkTimeTable& t) {
        return t.getName() == searchName;
    });

    if (it != tables.end()) {
        std::cout << "Найденный сотрудник:\n";
        it->print();
    } else {
        std::cout << "Сотрудник не найден.\n";
    }

    return 0;
}
