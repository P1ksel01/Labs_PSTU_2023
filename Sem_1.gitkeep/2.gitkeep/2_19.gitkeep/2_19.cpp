#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int s = 0;

	for (int i = 1; i <= N;i++) {
		if (i % 3 == 0) s = s - i;
		else s = s + i;
	}
	cout << s;
	return 0;
}