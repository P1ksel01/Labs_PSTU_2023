#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int col, max, number;
    cout << "������� ���������� �����:";
    cin >> col;

    cout << "������� ����� 1:";
    cin >> max;
    for (int i = 1; i < col; i++) {
        cout << "������� ����� " << i + 1 << ":";
        cin >> number;
        if (number > max) max = number;
    }
    cout << "����� ������� ����� �� ������������:" << max << endl;
    return 0;
}
