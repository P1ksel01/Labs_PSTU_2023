#include<iostream>
using namespace std;


float f(int n, int x) {
    if (n == 1) return (pow(-1, n + 1) * pow(x, 2 * n) / (2 * n * (2 * n - 1)));
    else return (pow(-1, n + 1) * pow(x, 2 * n) / (2 * n * (2 * n - 1))) + f(n - 1, x);
}

int main() {
    setlocale(LC_ALL, "Rus");

    cout << "¬ведите пор€док 'n': ";
    int n;
    cin >> n;

    cout << "¬ведите переменную 'x': ";
    int x;
    cin >> x;


    cout << f(n, x);
    return 0;
}