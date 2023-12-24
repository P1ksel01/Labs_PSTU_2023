#include <iostream>
using namespace std;
int main() {
    int n = 5;
    int* ptr = &n;

    cin >> *ptr;

    cout << n << endl;

    return 0;
}