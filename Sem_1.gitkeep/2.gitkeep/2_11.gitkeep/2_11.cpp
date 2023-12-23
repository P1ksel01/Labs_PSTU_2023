#include<iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	int col, number, first = 0;

	cout << "Введите количество чисел:";
	cin >> col;


	for (int i = 0; i < col; i++) {
		cout << "Введите число " << i + 1 << ":";
		cin >> number;

		if (first != 0) continue;
		else first = number;
	}

	if (first > 0) cout << "Первое число не равное 0 является положительным";
	else if (first < 0) cout << "Первое число не равное 0 является отрицательным";
	else cout << "Все числа равны нулю";
	return 0;
}