#ifndef WORKTIMETABLE_H
#define WORKTIMETABLE_H

#include <string>

class WorkTimeTable {
protected:
    std::string employeeName;  // �.�.�.
    std::string arrivalTime;   // ����� �������
    std::string departureTime; // ����� �����

public:
    // ������������
    WorkTimeTable(); // ����������� ��� ����������
    WorkTimeTable(const std::string& name, const std::string& arrival, const std::string& departure);

    // ����������� ����������
    virtual ~WorkTimeTable() {}

    // ������ �������
    std::string getName() const;
    std::string getArrivalTime() const;
    std::string getDepartureTime() const;

    // ���� � ����� ������
    virtual void input();
    virtual void print() const;

    // ���������
    bool operator<(const WorkTimeTable& other) const; // ���������� �� �����
};

#endif
