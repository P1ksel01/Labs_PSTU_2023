#include<iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	int col, number, max, min;

	cout << "¬ведите количество чисел:";
	cin >> col;

	if (col == 0) cout << "¬ведите коректное количество чисел";

	cout << "¬ведите число 1:";
	cin >> number;
	max = min = number;

	for (int i = 1; i < col; i++) {
		cout << "¬ведите число " << i + 1 << ":";
		cin >> number;

		if (number > max) max = number;
		if (number < min) min = number;
	}

	cout << "—умма максимального и минимального элемента последовательности равна:" << max + min;
	return 0;
}