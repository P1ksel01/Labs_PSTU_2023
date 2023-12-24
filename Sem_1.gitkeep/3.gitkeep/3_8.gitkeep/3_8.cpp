#include <iostream>
#include<clocale>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");

    cout << "Введите строку: ";
    string s;
    getline(cin, s);

    cout << "Введите большую букву: ";
    char upper;
    cin >> upper;

    cout << "Введите строчную букву: ";
    char lower;
    cin >> lower;

    int countUpper = 0, countTotal = 0, countOther = 0, countLower = 0;

    for (char c : s) {
        if (c == upper) countUpper++;
        else if (c == lower) countLower++;
        else if (c != ' ') countOther++;
        countTotal++;
    }

    cout << "Количество символа " << upper << ": " << countUpper << endl;
    cout << "Количество символа " << lower << ": " << countLower << endl;
    cout << "Количество остальных символов: " << countOther << endl;
    cout << "Количество всех символов: " << countTotal << endl;

    return 0;
}
