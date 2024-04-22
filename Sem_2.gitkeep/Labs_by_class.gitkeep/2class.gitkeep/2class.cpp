#include <iostream>
#include "Header.h"
#include <string.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    Namber num;
    cout << "Объект num, созданный конструктором без параметров:" << endl;
    num.show();

    float mantis;
    int order;
    string performance;
    cout << "Введите мантиссу, порядок, и представление (+ или -)" << endl;
    cin >> mantis >> order >> performance;
    Namber num2(mantis, order, performance);
    cout << "Объект num2, созданный конструктором c параметрами (" << mantis << ", " << order << ", " << performance << "):" << endl;
    num2.show();

    Namber num3(mantis, order);
    cout << "Объект num3, созданный конструктором c параметрами (" << mantis << ", " << order << "):" << endl;
    num3.show();

    Namber num4(num2);
    cout << "Объект num4, созданный конструктором копирования (num4(num2)):" << endl;
    num4.show();

    return 0;
}