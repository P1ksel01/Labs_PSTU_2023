#include <iostream>
using namespace std;


void tower(int n, int from, int to, int buf) {
    setlocale(LC_ALL, "rus");
    if (n != 0) {
        tower(n - 1, from, buf, to);
        cout << "���������� ���� " << n << " � ����� " << from << " �� ����� " << to << endl;
        tower(n - 1, buf, to, from);
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    int start, finish, buffer, n_disks;

    cout << "����� ������� ��������:\n";
    cin >> start;
    cout << "����� ��������� ��������:\n";
    cin >> finish;
    cout << "����� �������������� ��������:\n";
    cin >> buffer;
    cout << "���������� ������:\n";
    cin >> n_disks;

    tower(n_disks, start, finish, buffer);
    return 0;
}



