#include<iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Rus");

	int a, b = 0;

	cout << "������� ����������� �����:";
	cin >> a;

	while (a > 0) {
		b = 10 * b + a % 10;
		a /= 10;
	}

	cout << "�������� ����� ���������� �����:" << b;
	return 0;
}