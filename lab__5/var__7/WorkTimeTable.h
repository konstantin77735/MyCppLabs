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
    WorkTimeTable(); // ����������� ��� ����������
    WorkTimeTable(const WorkTimeTable& other); // ����������� �����
    WorkTimeTable(const std::string& name, const std::string& arrival, const std::string& departure); // ����������� � �����������

    // ��������
    WorkTimeTable& operator=(const WorkTimeTable& other); // �������� ������������
    bool operator==(const WorkTimeTable& other) const; // �������� ���������
    bool operator<(const WorkTimeTable& other) const;  // �������� "������"

    // ������ �������
    std::string getName() const;
    std::string getArrivalDate() const;
    std::string getDepartureDate() const;

    // ����, ����� � ��������������
    void input();
    void edit();

    // ����������� ����� ���������� � �������������� qsort
    static void sort(std::vector<WorkTimeTable>& tables);

    // ����� ��� ����������� ������
    void print() const;

    // ����������� �������-���������� ��� qsort
    static int compare(const void* a, const void* b);
};

#endif
