#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int n, tmp, * ptr = &tmp, max, min;

    cout << "������� ����� ������������������:\n";
    cin >> n;
    cout << "������� ������ �����:\n";
    cin >> *ptr;
    max = *ptr;
    min = *ptr;

    for (int i = 2; i <= n; i++){
        cin >> *ptr;
        if (*ptr > max) max = *ptr;
        else if (*ptr < min) min = *ptr; 
    }
    cout << "������������ �������: " << max << endl;
    cout << "����������� �������: " << min << endl;
    return 0;
}
