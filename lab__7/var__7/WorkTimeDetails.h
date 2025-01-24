#ifndef WORKTIMEDETAILS_H
#define WORKTIMEDETAILS_H

#include "WorkTimeTable.h"
#include <string>

class WorkTimeDetails : public WorkTimeTable {
private:
    std::string department;  // Подразделение
    std::string dayOfWeek;   // День недели

public:
    // Конструкторы
    WorkTimeDetails();
    WorkTimeDetails(const std::string& name, const std::string& arrival, const std::string& departure,
                    const std::string& dept, const std::string& day);

    // Методы доступа
    std::string getDepartment() const;
    std::string getDayOfWeek() const;

    // Переопределение методов
    void input() override;
    void print() const override;
};

#endif
