#include <iostream>
using namespace std;


class Range {
private:
    double left;
    double right;


public:
    Range(double left = 0, double right = 0) {
        this->left = left;
        this->right = right;
    }


    Range(const Range& time) {
        left = time.left;
        right = time.right;
    }


    ~Range() {
        cout << "Уничтожен.\n";
    }

    void rengecheck(double x) {
        if ((x > left) && (x < right)) cout << "Число находится в диапазоне!\n";
        else cout << "Число не находится в диапазоне!!\n";
    }

};


int main() {
    setlocale(LC_ALL, "Rus");
    double lef, rig;
    cout << "Введите два числа DOUBLE: ";
    cin >> lef >> rig;
    cout << endl;

    Range ren(lef, rig);

    cout << "Введите число DOUBLE которое хотите проверить: ";
    double x;
    cin >> x;

    ren.rengecheck(x);

    return 0;
}