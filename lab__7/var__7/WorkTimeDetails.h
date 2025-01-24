#ifndef WORKTIMEDETAILS_H
#define WORKTIMEDETAILS_H

#include "WorkTimeTable.h"
#include <string>

class WorkTimeDetails : public WorkTimeTable {
private:
    std::string department;  // �������������
    std::string dayOfWeek;   // ���� ������

public:
    // ������������
    WorkTimeDetails();
    WorkTimeDetails(const std::string& name, const std::string& arrival, const std::string& departure,
                    const std::string& dept, const std::string& day);

    // ������ �������
    std::string getDepartment() const;
    std::string getDayOfWeek() const;

    // ��������������� �������
    void input() override;
    void print() const override;
};

#endif
