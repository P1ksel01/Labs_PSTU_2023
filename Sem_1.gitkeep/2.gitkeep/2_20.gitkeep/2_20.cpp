#include<iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Rus");
	float s, n, a;
	int b;
	bool flag = 1, flag1 = 0;
	cin >> n >> s;
	if (s > 1 || s < -1) { cout << "S не может быть таким"; flag = 0; }
	for (int i = 1; i <= n; i++) {
		a = sin(n + i / n);
		b = a * 100000;
		if (b == s * 100000) flag1 = 1;
	}
	if (flag = 1 && flag = 1 ) cout << "содержится";
	if (flag = 1 && flag = 0) cout << "не содержится";
	return 0;
}