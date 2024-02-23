#include<iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    int n;
    cout << "Введите размерность массива массива: ";
    cin >> n;
    int** a = new int* [n];
    for (int i = 0; i < n; i++) a[i] = new int[n];
    int tmp;
    for (int i = 0; i < n; i++) {
        tmp = 0;
        for (int j = 0; j < n; j++) {
            if (j >= i) {
                tmp += 1;
                if (tmp == 10) tmp = 1;
                a[j][i] = tmp;
            }
            else a[j][i] = 0;
        }
    }
    cout << "Полученный массив: \n";
    for (int i = 0; i < n; i++) { for (int j = 0; j < n; j++) cout << a[i][j] << "  "; cout << "\n"; }
    return 0;
}
