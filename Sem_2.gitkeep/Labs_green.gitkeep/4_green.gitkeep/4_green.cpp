#include<iostream>
#include<vector>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	int n;
	cout << "Введите число элементов массива: ";
	cin >> n;
	int* a = new int[n];
	//Генерируем и выводим массив
	cout << "Исходный массив: \n";
	for (int i = 0; i < n; i++) { a[i] = rand() % 100 - 50; cout << a[i] << "\t"; }

	int j = 1;
	for (int i = 1; i < n; i++) if (i % 3 != 0) a[j++] = a[i];

	// Выводим массив без элементнов с индексом кратном 3
	n = j;
	cout << "\nМассив без элементов с индексом кратных 3: \n";
	for (int i = 0; i < n; i++) cout << a[i] << "\t";

	vector<int> res;
	for (int i = 0; i < n; i++) {
		res.push_back(a[i]);
		if (a[i] < 0) res.push_back((i == 0) ? 1 : abs(a[i - 1] + 1));
	}

	// Выводим полученный результат
	cout << "\nКонечный массив: \n";
	for (int x : res) cout << x << "\t";

	return 0;
}