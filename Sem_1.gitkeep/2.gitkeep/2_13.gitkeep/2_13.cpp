#include <iostream>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    double a, b, c;
    cout << "Введите a, b и c: ";
    cin >> a >> b >> c;

    double D = b * b - 4 * a * c;

    if (D < 0) cout << "Уравнение не имеет действительных корней" << endl;
    else if (D == 0) {
        double x = -b / (2 * a);
        cout << "Уравнение имеет один корень: x = " << x << endl;
    }
    else {
        double x1 = (-b + sqrt(D)) / (2 * a);
        double x2 = (-b - sqrt(D)) / (2 * a);
        cout << "Уравнение имеет два корня: x1 = " << x1 << ", x2 = " << x2 << endl;
    }
    return 0;
}
