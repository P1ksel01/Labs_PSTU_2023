#include<iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Rus");
	int last = 0;
	bool flag = true;
	for (int number = 1;number != 0;) {
		cin >> number;
		if (number > last && flag == true) flag = true;
		else flag = false;
		last = number;
	}
	if (flag == true) cout << "Возрастающая";
	else cout << "Не возрастающая";
	return 0;
}