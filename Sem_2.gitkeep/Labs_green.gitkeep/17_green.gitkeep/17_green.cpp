#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Функция для создания таблицы префиксов для KMP
vector<int> createLPS(const string& pattern) {
    vector<int> lps(pattern.size(), 0);
    int length = 0;
    int i = 1;
    while (i < pattern.size()) {
        if (pattern[i] == pattern[length]) {
            lps[i++] = ++length;
        }
        else {
            if (length != 0) {
                length = lps[length - 1];
            }
            else {
                lps[i++] = 0;
            }
        }
    }
    return lps;
}

// Алгоритм Кнута-Морриса-Пратта
int KMP(const string& text, const string& pattern) {
    vector<int> lps = createLPS(pattern);
    int i = 0;
    int j = 0;
    while (i < text.size()) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }
        if (j == pattern.size()) {
            return i - j;
            j = lps[j - 1];
        }
        else if (i < text.size() && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }
    return -1;
}

// Функция для создания таблицы сдвигов для алгоритма Бойера-Мура
vector<int> createShiftTable(const string& pattern) {
    const int ALPHABET_SIZE = 256;
    vector<int> table(ALPHABET_SIZE, -1);
    for (int i = 0; i < pattern.size(); i++) {
        table[pattern[i]] = i;
    }
    return table;
}

// Алгоритм Бойера-Мура
int boyerMoore(const string& text, const string& pattern) {
    vector<int> shiftTable = createShiftTable(pattern);
    int skip;
    for (int i = 0; i <= text.size() - pattern.size(); i += skip) {
        skip = 0;
        for (int j = pattern.size() - 1; j >= 0; j--) {
            if (pattern[j] != text[i + j]) {
                skip = max(1, j - shiftTable[text[i + j]]);
                break;
            }
        }
        if (skip == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    setlocale(LC_ALL, "Rus");
    string text;
    cin >> text;
    string pattern;


    int choice;

    cout << "Выберите метод поиска:\n";
    cout << "1 - KMP\n";
    cout << "2 - Boyer-Moore\n";
    cout << "Введите номер сортировки: ";
    cin >> choice;



    switch (choice) {
    case 1:
        cin >> pattern;
        cout << "Индекс начала подстроки (KMP): " << KMP(text, pattern) << endl;
        break;
    case 2:
        cin >> pattern;
        cout << "Индекс начала подстроки (Boyer-Moore): " << boyerMoore(text, pattern) << endl;
        break;
    default:
        cout << "Неверный выбор поиска.\n";
        return 1;
    }

    return 0;
}
