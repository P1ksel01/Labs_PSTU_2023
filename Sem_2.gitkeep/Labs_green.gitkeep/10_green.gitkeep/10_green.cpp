#include <iostream>
#include<vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    int n;
    cout << "������� ������ �������: ";
    cin >> n;

    int* arr = new int[n];

    cout << "������� �������� �������: ";
    for (int i = 0; i < n; ++i) cin >> arr[i];

    int m;
    cout << "������� ����� �������� ��� ��������: ";
    cin >> m;

    int k;
    cout << "������� ���������� ��������� ��� ����������: ";
    cin >> k;

    int newElement;
    cout << "������� �����(��) �������(�): ";

    vector<int> v;

    for (int i = 0; i < m - 1; ++i) v.push_back(arr[i]);

    for (int i = 0; i < k; i++) {
        cin >> newElement;
        v.push_back(newElement);
    }

    for (int i = m; i < n; i++) v.push_back(arr[i]);

    cout << "����������� ������: ";

    for (int i = 0; i < v.size(); ++i) cout << v[i] << " ";
    cout << "\n";

    delete[] arr;

    return 0;
}




