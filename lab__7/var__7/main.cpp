#include "WorkTimeDetails.h"
#include <windows.h>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<WorkTimeDetails> records;

    int n;
    std::cout << "Введите количество записей: ";
    std::cin >> n;
    std::cin.ignore(); // Очистка буфера ввода

    // Ввод данных
    for (int i = 0; i < n; ++i) {
        std::cout << "\nЗапись #" << i + 1 << ":\n";
        WorkTimeDetails record;
        record.input();
        records.push_back(record);
    }

    // Сортировка данных
    std::cout << "\nСортировка записей по имени...\n";
    std::sort(records.begin(), records.end());

    // Вывод отсортированных данных
    std::cout << "Отсортированные записи:\n";
    for (const auto& record : records) {
        record.print();
    }

    // Поиск записи
    std::cin.ignore();
    std::string searchName;
    std::cout << "\nВведите имя для поиска: ";
    std::getline(std::cin, searchName);

    auto it = std::find_if(records.begin(), records.end(), [&](const WorkTimeDetails& record) {
        return record.getName() == searchName;
    });

    if (it != records.end()) {
        std::cout << "Найденная запись:\n";
        it->print();
    } else {
        std::cout << "Запись не найдена.\n";
    }

    return 0;
}
