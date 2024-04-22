#include <iostream>
#include "Header.h"

using namespace std;
int main() {
    setlocale(LC_ALL, "Rus");
    Time time1;
    cout << "Введите минуты и секунды для объекта time1:" << endl;
    cin >> time1;
    cout << "time1:\t" << time1 << endl;

    Time time2 = time1;
    cout << "Создан объект time2 и ему присвоено значение time1." << endl;

    int subtraction_seconds;
    cout << "Введите количество секунд, которое будет прибавлено к time2:" << endl;
    cin >> subtraction_seconds;
    time2 = time2 + subtraction_seconds;
    cout << "time2:\t" << time2 << endl;

    bool comparison;
    cout << "Результат операции сравнения:" << endl;
    comparison = time1 == time2;
    cout << comparison << endl;

    return 0;
}