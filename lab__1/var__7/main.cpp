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
    std::cout << "������� ���������� �����������: ";
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < n; ++i) {
        std::cout << "��������� #" << i + 1 << ":\n";
        WorkTimeTable table; // �������� ��������: ������������ WorkTimeTable
        table.input();
        tables.push_back(table);
    }

    std::string sortProperty;
    bool ascending;
    std::cout << "\n������� �������� ��� ���������� (name, arrival, departure): ";
    std::cin >> sortProperty;
    std::cout << "����������� �� �����������? (1 - ��, 0 - ���): ";
    std::cin >> ascending;

    WorkTimeTable::sort(tables, sortProperty, ascending);

    std::cout << "\n��������������� ������:\n";
    for (const auto& table : tables) {
        table.print();
    }

    std::cin.ignore();
    std::string searchKey;
    std::cout << "\n������� ���� ��� ������: ";
    std::getline(std::cin, searchKey);

    WorkTimeTable* result = WorkTimeTable::search(tables, searchKey);
    if (result) {
        std::cout << "\n��������� ���������:\n";
        result->print();
        delete result;
    } else {
        std::cout << "\n��������� �� ������.\n";
    }

    return 0;
}
