#include "WorkTimeDetails.h"
#include <iostream>

// Конструктор без параметров
WorkTimeDetails::WorkTimeDetails() : WorkTimeTable(), department(""), dayOfWeek("") {}

// Конструктор с параметрами
WorkTimeDetails::WorkTimeDetails(const std::string& name, const std::string& arrival, const std::string& departure,
                                 const std::string& dept, const std::string& day)
    : WorkTimeTable(name, arrival, departure), department(dept), dayOfWeek(day) {}

// Методы доступа
std::string WorkTimeDetails::getDepartment() const { return department; }
std::string WorkTimeDetails::getDayOfWeek() const { return dayOfWeek; }

// Переопределение метода ввода
void WorkTimeDetails::input() {
    WorkTimeTable::input(); // Вызов базового метода
    std::cout << "Введите подразделение: ";
    std::getline(std::cin, department);
    std::cout << "Введите день недели: ";
    std::getline(std::cin, dayOfWeek);
}

// Переопределение метода вывода
void WorkTimeDetails::print() const {
    WorkTimeTable::print(); // Вызов базового метода
    std::cout << "Подразделение: " << department << ", День недели: " << dayOfWeek << std::endl;
}
