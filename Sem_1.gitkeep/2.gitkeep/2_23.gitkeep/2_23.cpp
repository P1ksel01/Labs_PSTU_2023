#include<iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Rus");
	float n, a, max = 0, count = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		a = sin(n + i / n);
		if (a == max) count++;
		if (i == 1) max = a;
		if (a > max) { max = a; count = 1; }
	}
	cout << "Максимальное значение равняется:" << max << " Оно повторяется " << count << " раз";
	return 0;
}