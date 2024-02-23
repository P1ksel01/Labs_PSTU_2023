#include<iostream>
using namespace std;

int f(int n) {
    if (n == 0 || n == 1) return n;
    else return f(n - 1) + f(n - 2);
}

int main() {
    setlocale(LC_ALL, "Rus");

    cout << "Сколько чисел вы хотите найти?\n";
    int n;
    cin >> n;

    for (int i = 0; i <= n; i++) cout << "f(" << i << ") = " << f(i) << "\n";
    return 0;
}