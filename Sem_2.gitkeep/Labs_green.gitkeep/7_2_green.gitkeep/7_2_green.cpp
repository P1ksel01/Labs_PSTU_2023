#include<iostream>
#include<vector>
#include<stdarg.h>
using namespace std;
int sum(int n, ...) {
    // ������� ������ va_list ��� ������� � ����������
    va_list args;
    // �������������� args, �������� ��������� ������������� ��������
    va_start(args, n);
    int result = 0;
    int current;
    for (int i = 0; i < n; i++) {
        current = va_arg(args, int);
        if (i % 2 == 0) {
            if (i + 1 < n) {
                int next = va_arg(args, int);
                i++;
                result += current * next;
            }
            else result += current;
        }
    }
    va_end(args);
    return result;
}
void main()
{
    setlocale(LC_ALL, "Rus");

    cout << sum(4, 3, 4, 7, 1) << "\n";

}
