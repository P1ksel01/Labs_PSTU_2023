#include<iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	int col, number, first = 0;

	cout << "������� ���������� �����:";
	cin >> col;


	for (int i = 0; i < col; i++) {
		cout << "������� ����� " << i + 1 << ":";
		cin >> number;

		if (first != 0) continue;
		else first = number;
	}

	if (first > 0) cout << "������ ����� �� ������ 0 �������� �������������";
	else if (first < 0) cout << "������ ����� �� ������ 0 �������� �������������";
	else cout << "��� ����� ����� ����";
	return 0;
}