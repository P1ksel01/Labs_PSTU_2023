#include <iostream>
using namespace std;


void tower(int n, int from, int to, int buf) {
    setlocale(LC_ALL, "rus");
    if (n != 0) {
        tower(n - 1, from, buf, to);
        cout << "Переместим диск " << n << " с башни " << from << " на башню " << to << endl;
        tower(n - 1, buf, to, from);
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    int start, finish, buffer, n_disks;

    cout << "Номер первого столбика:\n";
    cin >> start;
    cout << "Номер конечного столбика:\n";
    cin >> finish;
    cout << "Номер промежуточного столбика:\n";
    cin >> buffer;
    cout << "Количество дисков:\n";
    cin >> n_disks;

    tower(n_disks, start, finish, buffer);
    return 0;
}



