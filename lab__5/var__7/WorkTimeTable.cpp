#include "WorkTimeTable.h"
#include <windows.h>
#include <iostream>
#include <cstring> // ��� ������� strcmp � qsort
#include <algorithm> // ��� std::sort

// ����������� ��� ����������
WorkTimeTable::WorkTimeTable() : employeeName(""), arrivalDate(""), departureDate("") {}

// ����������� �����
WorkTimeTable::WorkTimeTable(const WorkTimeTable& other)
    : employeeName(other.employeeName), arrivalDate(other.arrivalDate), departureDate(other.departureDate) {}

// ����������� � �����������
WorkTimeTable::WorkTimeTable(const std::string& name, const std::string& arrival, const std::string& departure)
    : employeeName(name), arrivalDate(arrival), departureDate(departure) {}

// �������� ������������
WorkTimeTable& WorkTimeTable::operator=(const WorkTimeTable& other) {
    if (this != &other) {
        employeeName = other.employeeName;
        arrivalDate = other.arrivalDate;
        departureDate = other.departureDate;
    }
    return *this;
}

// �������� ���������
bool WorkTimeTable::operator==(const WorkTimeTable& other) const {
    return employeeName == other.employeeName && arrivalDate == other.arrivalDate && departureDate == other.departureDate;
}

// �������� "������"
bool WorkTimeTable::operator<(const WorkTimeTable& other) const {
    return employeeName < other.employeeName; // ���������� �� �����
}

// ������ �������
std::string WorkTimeTable::getName() const { return employeeName; }
std::string WorkTimeTable::getArrivalDate() const { return arrivalDate; }
std::string WorkTimeTable::getDepartureDate() const { return departureDate; }

// ����� �����
void WorkTimeTable::input() {
    std::cout << "������� �.�.�. ����������: ";
    std::getline(std::cin, employeeName);
    std::cout << "������� ���� ������� (YYYY-MM-DD): ";
    std::getline(std::cin, arrivalDate);
    std::cout << "������� ���� ����� (YYYY-MM-DD): ";
    std::getline(std::cin, departureDate);
}

// ����� ��������������
void WorkTimeTable::edit() {
    std::cout << "�������������� ������ ����������:\n";
    input();
}

// ����� ��� ����������� ������
void WorkTimeTable::print() const {
    std::cout << "�.�.�.: " << employeeName << ", ������: " << arrivalDate << ", ����: " << departureDate << std::endl;
}

// ����������� �������-���������� ��� qsort
int WorkTimeTable::compare(const void* a, const void* b) {
    const WorkTimeTable* objA = static_cast<const WorkTimeTable*>(a);
    const WorkTimeTable* objB = static_cast<const WorkTimeTable*>(b);
    return objA->employeeName.compare(objB->employeeName);
}

// ����������� ����� ���������� � �������������� qsort
void WorkTimeTable::sort(std::vector<WorkTimeTable>& tables) {
    qsort(&tables[0], tables.size(), sizeof(WorkTimeTable), compare);
}
