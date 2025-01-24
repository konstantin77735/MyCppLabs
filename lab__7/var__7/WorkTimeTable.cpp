#include "WorkTimeTable.h"
#include <iostream>

// Конструктор без параметров
WorkTimeTable::WorkTimeTable() : employeeName(""), arrivalTime(""), departureTime("") {}

// Конструктор с параметрами
WorkTimeTable::WorkTimeTable(const std::string& name, const std::string& arrival, const std::string& departure)
    : employeeName(name), arrivalTime(arrival), departureTime(departure) {}

// Методы доступа
std::string WorkTimeTable::getName() const { return employeeName; }
std::string WorkTimeTable::getArrivalTime() const { return arrivalTime; }
std::string WorkTimeTable::getDepartureTime() const { return departureTime; }

// Ввод данных
void WorkTimeTable::input() {
    std::cout << "Введите Ф.И.О. сотрудника: ";
    std::getline(std::cin, employeeName);
    std::cout << "Введите время прихода (HH:MM): ";
    std::getline(std::cin, arrivalTime);
    std::cout << "Введите время ухода (HH:MM): ";
    std::getline(std::cin, departureTime);
}

// Вывод данных
void WorkTimeTable::print() const {
    std::cout << "Ф.И.О.: " << employeeName << ", Приход: " << arrivalTime
              << ", Уход: " << departureTime << std::endl;
}

// Оператор "меньше" (для сортировки по имени)
bool WorkTimeTable::operator<(const WorkTimeTable& other) const {
    return employeeName < other.employeeName;
}
