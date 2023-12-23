#include <iostream>
using namespace std;

int main() {
    int size;
    cin >> size;
    int diag = size / 2 + 1;
    int help;
    if (size % 2 == 0) help = 1;
    else help = 0;
    for (int i = 0; i < diag; i++) {
        for (int e = diag - 1; e > i; e--) cout << "  ";
        for (int j = 0; j < size; j++) {
            if (i == 0 || i == diag - 1 || j == 0) {
                cout << "* ";
                if (j == 0 && i != 0 && i != size / 2) {
                    for (int l = 2; l <= i; l++) cout << "  ";
                    cout << ".";
                }
            }
            else {
                if (j == size - i - 1) cout << " *";
                else if (j < size - i) cout << "  ";
            }
        }
        for (int k = 1; k < i; k++) cout << "  ";
        if (i != 0) {
            if (i == diag - 1) cout << "*";
            else cout << " *";
        }
        cout << endl;
    }
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size; j++) {
            if (j == 0 || j == size - 1 || i == size - 2) cout << "* ";
            else if (i == size - j - 2 && i > (size - 1) / 2 - 1) cout << ". ";
            else if (j == diag - 1 && i < (size - 1) / 2 || i == (size - 1) / 2 - 1 && j>diag - 1) cout << ". ";
            else cout << "  ";
        }
        if (i <= size - diag - 1) {
            if (i == (size - 1) / 2 - 1) {
                for (int h = (size - 1) / 2 + help - 1; h > 0;h--) cout << ". ";
                cout << "* ";
            }
            else {
                for (int w = diag - 2; w >= 1; w--) cout << "  ";
                cout << "*";
            }
        }
        else {
            if (size % 2 == 0) {
                for (int r = diag - 4; r > i - diag + 1; r--) cout << "  ";
                if (i != size - 2) cout << "*";
            }
            else {
                for (int r = diag - 4; r > i - diag; r--) cout << "  ";
                if (i != size - 2) cout << "*";
            }
        }
        cout << endl;
    }
    return 0;
}

