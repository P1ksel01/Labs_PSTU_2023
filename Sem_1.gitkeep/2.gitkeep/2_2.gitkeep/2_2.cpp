#include <iostream>

using namespace std;

int main()
{
    int n; int product = 1;

    cin >> n;

    for (int i = 1; i <= n; i++) product *= i;
    cout << product << endl;
    return 0;
}
