#include<iostream>
using namespace std;

int main() {

	setlocale(LC_ALL, "Rus");

	int n;
	cout << "Введите количество строк массива: ";
	cin >> n;

	int m;
	cout << "Введите количество столбцов массива: ";
	cin >> m;

	int** a = new int* [n];
	for (int i = 0; i < n; i++) a[i] = new int[m];

	int k = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (((i + j) % 2) == 0) { a[i][j] = k; k++; }
			else a[i][j] = 0;
			if (k == 10) k = 1;
		}
	}

	//выводим полученный массив
	cout << "Полученный массив: \n";
	for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) cout << a[i][j] << "  "; cout << "\n"; }


	return 0;
}




