#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int col, max, number;
    cout << "¬ведите количество чисел:";
    cin >> col;

    cout << "¬ведите число 1:";
    cin >> max;
    for (int i = 1; i < col; i++) {
        cout << "¬ведите число " << i + 1 << ":";
        cin >> number;
        if (number > max) max = number;
    }
    cout << "—амое большое число из предложенных:" << max << endl;
    return 0;
}
