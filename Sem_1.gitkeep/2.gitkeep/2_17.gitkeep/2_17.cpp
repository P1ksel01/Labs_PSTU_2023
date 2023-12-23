#include<iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Rus");

	int x, n, i, f = 0;
	double sum = 0;

	cin >> x >> n;

	for (i = 0; i < n + 1; i++) {
		f *= i;
		if (f == 0) f = 1;
		sum += pow(x, i) / f;
	}

	cout << sum;
	cout << i;
	return 0;

}