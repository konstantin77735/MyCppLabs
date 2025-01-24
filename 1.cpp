#include <iostream>   
#include <string>
#include <conio.h> 
#include "windows.h"
using namespace std;


// была проблема с выводом "Вы ввели" на русском в консоли. Это отображалось как иероглифы
// чтобы это исправить поменя в VS Code в самом низу кодировку с UTF-8 на 1251
int main() 
{
    SetConsoleCP(1251);  
    SetConsoleOutputCP(1251);  

    string name;
    cin >> name;

    
    cout << "Вы ввели: " << name << endl;

    getche();
}
