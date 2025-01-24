#ifndef WORKTIMETABLE_H
#define WORKTIMETABLE_H

#include <string>
#include <vector>

class WorkTimeTable {
private:
    std::string employeeName;
    std::string arrivalDate;
    std::string departureDate;

public:
    //  онструкторы
    WorkTimeTable();
    WorkTimeTable(const std::string& name, const std::string& arrival, const std::string& departure);

    // ћетоды ввода данных
    void input();

    // ћетоды доступа (геттеры)
    std::string getName() const;
    std::string getArrivalDate() const;
    std::string getDepartureDate() const;

    // ћетод дл€ вывода данных
    void print() const; // <--- ќЅя«ј“≈Ћ№Ќќ включите это объ€вление

    // —татические методы
    static void sort(std::vector<WorkTimeTable>& tables, const std::string& sortProperty, bool ascending);
    static WorkTimeTable* search(const std::vector<WorkTimeTable>& tables, const std::string& key);
};

#endif
