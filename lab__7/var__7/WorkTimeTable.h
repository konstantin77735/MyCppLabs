#ifndef WORKTIMETABLE_H
#define WORKTIMETABLE_H

#include <string>

class WorkTimeTable {
protected:
    std::string employeeName;  // Ф.И.О.
    std::string arrivalTime;   // Время прихода
    std::string departureTime; // Время ухода

public:
    // Конструкторы
    WorkTimeTable(); // Конструктор без параметров
    WorkTimeTable(const std::string& name, const std::string& arrival, const std::string& departure);

    // Виртуальный деструктор
    virtual ~WorkTimeTable() {}

    // Методы доступа
    std::string getName() const;
    std::string getArrivalTime() const;
    std::string getDepartureTime() const;

    // Ввод и вывод данных
    virtual void input();
    virtual void print() const;

    // Операторы
    bool operator<(const WorkTimeTable& other) const; // Сортировка по имени
};

#endif
