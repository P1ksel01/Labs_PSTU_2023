#include<iostream>
#include <clocale>
#include<string>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return c == 'а' || c == 'е' || c == 'ё' || c == 'и' || c == 'о' || c == 'у' || c == 'ы' || c == 'э' || c == 'ю' || c == 'я';
}

int main() {
    setlocale(LC_ALL, "Rus");

    int countC = 0;
    int countV = 0;

    cout << "Введите строку:\n";
    string st;

    getline(cin, st);

    const char* pt = st.data();

    while (*pt != '\0') {
        char c = tolower(*pt);
        if (isVowel(c)) countV++;
        else countC++;
        pt++;
    }

    cout << "Количество гласных: " << countV << endl;
    cout << "Количество согласных: " << countC << endl;

    return 0;
}