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
    std::cout << "������� ���������� �������: ";
    std::cin >> n;
    std::cin.ignore(); // ������� ������ �����

    // ���� ������
    for (int i = 0; i < n; ++i) {
        std::cout << "\n������ #" << i + 1 << ":\n";
        WorkTimeDetails record;
        record.input();
        records.push_back(record);
    }

    // ���������� ������
    std::cout << "\n���������� ������� �� �����...\n";
    std::sort(records.begin(), records.end());

    // ����� ��������������� ������
    std::cout << "��������������� ������:\n";
    for (const auto& record : records) {
        record.print();
    }

    // ����� ������
    std::cin.ignore();
    std::string searchName;
    std::cout << "\n������� ��� ��� ������: ";
    std::getline(std::cin, searchName);

    auto it = std::find_if(records.begin(), records.end(), [&](const WorkTimeDetails& record) {
        return record.getName() == searchName;
    });

    if (it != records.end()) {
        std::cout << "��������� ������:\n";
        it->print();
    } else {
        std::cout << "������ �� �������.\n";
    }

    return 0;
}
