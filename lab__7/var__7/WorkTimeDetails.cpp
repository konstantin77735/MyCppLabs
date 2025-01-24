#include "WorkTimeDetails.h"
#include <iostream>

// ����������� ��� ����������
WorkTimeDetails::WorkTimeDetails() : WorkTimeTable(), department(""), dayOfWeek("") {}

// ����������� � �����������
WorkTimeDetails::WorkTimeDetails(const std::string& name, const std::string& arrival, const std::string& departure,
                                 const std::string& dept, const std::string& day)
    : WorkTimeTable(name, arrival, departure), department(dept), dayOfWeek(day) {}

// ������ �������
std::string WorkTimeDetails::getDepartment() const { return department; }
std::string WorkTimeDetails::getDayOfWeek() const { return dayOfWeek; }

// ��������������� ������ �����
void WorkTimeDetails::input() {
    WorkTimeTable::input(); // ����� �������� ������
    std::cout << "������� �������������: ";
    std::getline(std::cin, department);
    std::cout << "������� ���� ������: ";
    std::getline(std::cin, dayOfWeek);
}

// ��������������� ������ ������
void WorkTimeDetails::print() const {
    WorkTimeTable::print(); // ����� �������� ������
    std::cout << "�������������: " << department << ", ���� ������: " << dayOfWeek << std::endl;
}
