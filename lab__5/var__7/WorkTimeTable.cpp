#include "WorkTimeTable.h"
#include <iostream>
#include <cstring> // Для функции strcmp в qsort
#include <algorithm> // Для std::sort

// Конструктор без параметров
WorkTimeTable::WorkTimeTable() : employeeName(""), arrivalDate(""), departureDate("") {}

// Конструктор копий
WorkTimeTable::WorkTimeTable(const WorkTimeTable& other)
    : employeeName(other.employeeName), arrivalDate(other.arrivalDate), departureDate(other.departureDate) {}

// Конструктор с параметрами
WorkTimeTable::WorkTimeTable(const std::string& name, const std::string& arrival, const std::string& departure)
    : employeeName(name), arrivalDate(arrival), departureDate(departure) {}

// Оператор присваивания
WorkTimeTable& WorkTimeTable::operator=(const WorkTimeTable& other) {
    if (this != &other) {
        employeeName = other.employeeName;
        arrivalDate = other.arrivalDate;
        departureDate = other.departureDate;
    }
    return *this;
}

// Оператор сравнения
bool WorkTimeTable::operator==(const WorkTimeTable& other) const {
    return employeeName == other.employeeName && arrivalDate == other.arrivalDate && departureDate == other.departureDate;
}

// Оператор "меньше"
bool WorkTimeTable::operator<(const WorkTimeTable& other) const {
    return employeeName < other.employeeName; // Сортировка по имени
}

// Методы доступа
std::string WorkTimeTable::getName() const { return employeeName; }
std::string WorkTimeTable::getArrivalDate() const { return arrivalDate; }
std::string WorkTimeTable::getDepartureDate() const { return departureDate; }

// Метод ввода
void WorkTimeTable::input() {
    std::cout << "Введите Ф.И.О. сотрудника: ";
    std::getline(std::cin, employeeName);
    std::cout << "Введите дату прихода (YYYY-MM-DD): ";
    std::getline(std::cin, arrivalDate);
    std::cout << "Введите дату ухода (YYYY-MM-DD): ";
    std::getline(std::cin, departureDate);
}

// Метод редактирования
void WorkTimeTable::edit() {
    std::cout << "Редактирование данных сотрудника:\n";
    input();
}

// Метод для отображения данных
void WorkTimeTable::print() const {
    std::cout << "Ф.И.О.: " << employeeName << ", Приход: " << arrivalDate << ", Уход: " << departureDate << std::endl;
}

// Статическая функция-компаратор для qsort
int WorkTimeTable::compare(const void* a, const void* b) {
    const WorkTimeTable* objA = static_cast<const WorkTimeTable*>(a);
    const WorkTimeTable* objB = static_cast<const WorkTimeTable*>(b);
    return objA->employeeName.compare(objB->employeeName);
}

// Статический метод сортировки с использованием qsort
void WorkTimeTable::sort(std::vector<WorkTimeTable>& tables) {
    qsort(&tables[0], tables.size(), sizeof(WorkTimeTable), compare);
}
