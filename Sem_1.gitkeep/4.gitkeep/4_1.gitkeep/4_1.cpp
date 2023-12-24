#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    float a, b, c;
    float fA, fB, fC;
    double eps = 0.000001;

    a = 1;
    b = 2;

    while (b - a > eps) {
        c = (a + b) / 2;
        fA = (a - 2 + sin(1 / a));
        fB = (b - 2 + sin(1 / b));
        fC = (c - 2 + sin(1 / c));
        if (fA * fC < 0) { b = c; }
        else if (fC * fB < 0) { a = c; }
        else { cout << "Что-то не то!" << endl; }
    }
    cout << "Корни: " << a << "; " << b << endl;
    return 0;
}