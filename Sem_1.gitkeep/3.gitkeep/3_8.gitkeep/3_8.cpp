#include <iostream>
#include<clocale>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");

    cout << "������� ������: ";
    string s;
    getline(cin, s);

    cout << "������� ������� �����: ";
    char upper;
    cin >> upper;

    cout << "������� �������� �����: ";
    char lower;
    cin >> lower;

    int countUpper = 0, countTotal = 0, countOther = 0, countLower = 0;

    for (char c : s) {
        if (c == upper) countUpper++;
        else if (c == lower) countLower++;
        else if (c != ' ') countOther++;
        countTotal++;
    }

    cout << "���������� ������� " << upper << ": " << countUpper << endl;
    cout << "���������� ������� " << lower << ": " << countLower << endl;
    cout << "���������� ��������� ��������: " << countOther << endl;
    cout << "���������� ���� ��������: " << countTotal << endl;

    return 0;
}
