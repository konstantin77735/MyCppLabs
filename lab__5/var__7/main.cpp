#include "WorkTimeTable.h"
#include <windows.h>
#include <iostream>
#include <vector>
#include <algorithm> // ��� std::find_if

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<WorkTimeTable> tables;

    int n;
    std::cout << "������� ���������� �����������: ";
    std::cin >> n;
    std::cin.ignore();

    // ���� ������
    for (int i = 0; i < n; ++i) {
        std::cout << "��������� #" << i + 1 << ":\n";
        WorkTimeTable table;
        table.input();
        tables.push_back(table);
    }

    // ����������
    std::cout << "\n���������� ������ �����������...\n";
    WorkTimeTable::sort(tables);

    std::cout << "��������������� ������:\n";
    for (const auto& table : tables) {
        table.print();
    }

    // ����� ����������
    std::cin.ignore();
    std::string searchName;
    std::cout << "\n������� ��� ��� ������: ";
    std::getline(std::cin, searchName);

    auto it = std::find_if(tables.begin(), tables.end(), [&](const WorkTimeTable& t) {
        return t.getName() == searchName;
    });

    if (it != tables.end()) {
        std::cout << "��������� ���������:\n";
        it->print();
    } else {
        std::cout << "��������� �� ������.\n";
    }

    return 0;
}
