#include<iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Rus");
	float n, a, max, maxi = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		a = sin(n + i / n);
		if (i == 1) max = a;
		if (a > max) { max = a; maxi = i; }
	}
	cout << "������������ �������� ���������:" << max << " ����� �� " << maxi << " �����";
	return 0;
}