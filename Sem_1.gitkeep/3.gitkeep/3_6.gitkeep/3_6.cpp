#include<iostream>
#include <clocale>
#include<string>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return c == '�' || c == '�' || c == '�' || c == '�' || c == '�' || c == '�' || c == '�' || c == '�' || c == '�' || c == '�';
}

int main() {
    setlocale(LC_ALL, "Rus");

    int countC = 0;
    int countV = 0;

    cout << "������� ������:\n";
    string st;

    getline(cin, st);

    const char* pt = st.data();

    while (*pt != '\0') {
        char c = tolower(*pt);
        if (isVowel(c)) countV++;
        else countC++;
        pt++;
    }

    cout << "���������� �������: " << countV << endl;
    cout << "���������� ���������: " << countC << endl;

    return 0;
}