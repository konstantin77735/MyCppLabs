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
    // ������������
    WorkTimeTable();
    WorkTimeTable(const std::string& name, const std::string& arrival, const std::string& departure);

    // ������ ����� ������
    void input();

    // ������ ������� (�������)
    std::string getName() const;
    std::string getArrivalDate() const;
    std::string getDepartureDate() const;

    // ����� ��� ������ ������
    void print() const; // <--- ����������� �������� ��� ����������

    // ����������� ������
    static void sort(std::vector<WorkTimeTable>& tables, const std::string& sortProperty, bool ascending);
    static WorkTimeTable* search(const std::vector<WorkTimeTable>& tables, const std::string& key);
};

#endif
