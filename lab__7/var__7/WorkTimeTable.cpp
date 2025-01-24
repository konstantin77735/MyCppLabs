#include "WorkTimeTable.h"
#include <iostream>

// ����������� ��� ����������
WorkTimeTable::WorkTimeTable() : employeeName(""), arrivalTime(""), departureTime("") {}

// ����������� � �����������
WorkTimeTable::WorkTimeTable(const std::string& name, const std::string& arrival, const std::string& departure)
    : employeeName(name), arrivalTime(arrival), departureTime(departure) {}

// ������ �������
std::string WorkTimeTable::getName() const { return employeeName; }
std::string WorkTimeTable::getArrivalTime() const { return arrivalTime; }
std::string WorkTimeTable::getDepartureTime() const { return departureTime; }

// ���� ������
void WorkTimeTable::input() {
    std::cout << "������� �.�.�. ����������: ";
    std::getline(std::cin, employeeName);
    std::cout << "������� ����� ������� (HH:MM): ";
    std::getline(std::cin, arrivalTime);
    std::cout << "������� ����� ����� (HH:MM): ";
    std::getline(std::cin, departureTime);
}

// ����� ������
void WorkTimeTable::print() const {
    std::cout << "�.�.�.: " << employeeName << ", ������: " << arrivalTime
              << ", ����: " << departureTime << std::endl;
}

// �������� "������" (��� ���������� �� �����)
bool WorkTimeTable::operator<(const WorkTimeTable& other) const {
    return employeeName < other.employeeName;
}
