#include<iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	int number, sum = 0;

	cout << "������� ����������� �����:";
	cin >> number;

	while (number > 0) {
		sum += number % 10;
		number /= 10;
	}

	cout << "����� ���� ������� ����� ���������:" << sum;
	return 0;
}