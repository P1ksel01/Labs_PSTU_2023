#include<iostream>
using namespace std;
//Сложение двух целых чисел через указатели
int main() {
	int a;
	cin >> a;
	int* pa1 = &a;
	int c = *pa1;
	cin >> a;
	*pa1 = a + c;


	cout << a << endl;
	return 0;
}