#include <iostream>   
#include <string>
#include <conio.h> 
#include "windows.h"
using namespace std;


// ���� �������� � ������� "�� �����" �� ������� � �������. ��� ������������ ��� ���������
// ����� ��� ��������� ������ � VS Code � ����� ���� ��������� � UTF-8 �� 1251
int main() 
{
    SetConsoleCP(1251);  
    SetConsoleOutputCP(1251);  

    string name;
    cin >> name;

    
    cout << "�� �����: " << name << endl;

    getche();
}
