#include<iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	int col, number, max, min;

	cout << "������� ���������� �����:";
	cin >> col;

	if (col == 0) cout << "������� ��������� ���������� �����";

	cout << "������� ����� 1:";
	cin >> number;
	max = min = number;

	for (int i = 1; i < col; i++) {
		cout << "������� ����� " << i + 1 << ":";
		cin >> number;

		if (number > max) max = number;
		if (number < min) min = number;
	}

	cout << "����� ������������� � ������������ �������� ������������������ �����:" << max + min;
	return 0;
}