#include<iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Rus");

	int number, s, ostatok = 0, c;
	bool flag = 1;

	cout << "������� ����������� �����:";
	cin >> number;

	cout << "������� ����� ��� �������� �������:";
	cin >> s;

	while (flag) {
		ostatok = number % 10;
		number /= 10;
		if (ostatok == s) {flag = 0; c = 1;}
		if (number == 0) flag = 0;
	}

	if (c == s) cout << "������ ����� ���������� � �����";
	else cout << "������ ����� � ����� �� ����������";
	return 0;
}
