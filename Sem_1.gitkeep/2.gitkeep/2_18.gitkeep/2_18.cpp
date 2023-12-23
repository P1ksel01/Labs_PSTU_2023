#include<iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Rus");

	int a, b = 0;

	cout << "¬ведите натуральное число:";
	cin >> a;

	while (a > 0) {
		b = 10 * b + a % 10;
		a /= 10;
	}

	cout << "ќбратное число исхождному равно:" << b;
	return 0;
}