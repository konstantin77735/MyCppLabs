#include "WorkTimeTable.h"
#include <iostream>
#include <algorithm>

WorkTimeTable::WorkTimeTable() : employeeName(""), arrivalDate(""), departureDate("") {}

WorkTimeTable::WorkTimeTable(const std::string& name, const std::string& arrival, const std::string& departure)
    : employeeName(name), arrivalDate(arrival), departureDate(departure) {}

void WorkTimeTable::input() {
    std::cout << "Введите Ф.И.О. сотрудника: ";
    std::getline(std::cin, employeeName);
    std::cout << "Введите дату прихода (в формате YYYY-MM-DD): ";
    std::getline(std::cin, arrivalDate);
    std::cout << "Введите дату ухода (в формате YYYY-MM-DD): ";
    std::getline(std::cin, departureDate);
}

std::string WorkTimeTable::getName() const {
    return employeeName;
}

std::string WorkTimeTable::getArrivalDate() const {
    return arrivalDate;
}

std::string WorkTimeTable::getDepartureDate() const {
    return departureDate;
}

void WorkTimeTable::print() const {
    std::cout << "Ф.И.О.: " << employeeName 
              << ", Дата прихода: " << arrivalDate 
              << ", Дата ухода: " << departureDate << std::endl;
}

void WorkTimeTable::sort(std::vector<WorkTimeTable>& tables, const std::string& sortProperty, bool ascending) {
    auto comparator = [&](const WorkTimeTable& a, const WorkTimeTable& b) {
        if (sortProperty == "name")
            return ascending ? a.getName() < b.getName() : a.getName() > b.getName();
        if (sortProperty == "arrival")
            return ascending ? a.getArrivalDate() < b.getArrivalDate() : a.getArrivalDate() > b.getArrivalDate();
        if (sortProperty == "departure")
            return ascending ? a.getDepartureDate() < b.getDepartureDate() : a.getDepartureDate() > b.getDepartureDate();
        return false;
    };
    std::sort(tables.begin(), tables.end(), comparator);
}

WorkTimeTable* WorkTimeTable::search(const std::vector<WorkTimeTable>& tables, const std::string& key) {
    for (const auto& table : tables) {
        if (table.getName() == key || table.getArrivalDate() == key || table.getDepartureDate() == key)
            return new WorkTimeTable(table);
    }
    return nullptr;
}
