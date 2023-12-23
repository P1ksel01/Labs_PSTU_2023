#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int q = sqrt(N);

    for (int i = 0; i < q; i++){
        for (int j = 0; j < q; j++) cout << "*";
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++) cout << "*";
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (i == 0 || i == N - 1 || j == 0 || j == N - 1) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }
    return 0;
}
