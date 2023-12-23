#include<iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	int number, sum = 0;

	cout << "Введите натуральное число:";
	cin >> number;

	while (number > 0) {
		sum += number % 10;
		number /= 10;
	}

	cout << "Сумма цифр данного числа равняется:" << sum;
	return 0;
}