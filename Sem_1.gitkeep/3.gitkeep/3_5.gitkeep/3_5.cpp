#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    unsigned int n, fact = 1;
    unsigned int* f = &fact;

    cin >> n;

    for (int i = 1; i <= n; i++) *f *= i;
    cout << "��������� " << n << " ����� " << fact << endl;

    return 0;
}
