// f(x) = x - 2 + sin(1/x);
// f'(x) = 1 - cos(1/x)/x^2;
// f''(x) = (2*cos(1/x)*x-sin(1/x))/x^4;
// [1, 2]

#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    double x, xPrev;
    // ���������, ����� �� �� ������� a ��� b �� ��������� �������� x
    // f(b) * f''(b) > 0
    // 0,48 * 0,19 > 0 => x0 = b;
    // ���� �� ������� �� �����������, ����� ��������� ��� � a
    x = 2;  // x0 = b;
    xPrev = 0;  // �������������� ���������� x(n-1)
    double eps = 0.000001;

    while (abs(x - xPrev) > eps)
    {
        xPrev = x;
        // ���� �� ����� �������, ��� x(i-1) - f(x(i-1)) / f'(x(i-1))
        x = xPrev - ((xPrev - 2 + sin(1 / xPrev)) / (1 - cos(1 / xPrev) / xPrev * xPrev * xPrev * xPrev));
    }
    cout << "������: " << x << endl;
    return 0;
}