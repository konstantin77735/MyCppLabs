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
    // Конструкторы
    WorkTimeTable(); // Конструктор без параметров
    WorkTimeTable(const WorkTimeTable& other); // Конструктор копий
    WorkTimeTable(const std::string& name, const std::string& arrival, const std::string& departure); // Конструктор с параметрами

    // Операции
    WorkTimeTable& operator=(const WorkTimeTable& other); // Оператор присваивания
    bool operator==(const WorkTimeTable& other) const; // Оператор сравнения
    bool operator<(const WorkTimeTable& other) const;  // Оператор "меньше"

    // Методы доступа
    std::string getName() const;
    std::string getArrivalDate() const;
    std::string getDepartureDate() const;

    // Ввод, вывод и редактирование
    void input();
    void edit();

    // Статический метод сортировки с использованием qsort
    static void sort(std::vector<WorkTimeTable>& tables);

    // Метод для отображения данных
    void print() const;

    // Статическая функция-компаратор для qsort
    static int compare(const void* a, const void* b);
};

#endif
