#include<iostream>
using namespace std;
//�������� �������� ���� ���������� ����� ���������.
int main() {
	int a, b;
	cin >> a >> b;

	int* pa = &a;
	int* pb = &b;
	int c = *pa;


	*pa = b;
	*pb = c;

	cout << a << "\t" << b << endl;
	return 0;
}