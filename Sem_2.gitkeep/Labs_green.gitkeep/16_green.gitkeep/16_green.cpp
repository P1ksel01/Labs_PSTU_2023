#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Линейный поиск
int linearSearch(const vector<int>& data, int key) {
    for (int i = 0; i < data.size(); ++i) {
        if (data[i] == key) {
            return i;
        }
    }
    return -1;
}

// Бинарный поиск
int binarySearch(const vector<int>& data, int key) {
    int left = 0;
    int right = data.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (data[mid] == key) {
            return mid;
        }
        else if (data[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

// Интерполяционный поиск
int interpolationSearch(const vector<int>& data, int key) {
    int low = 0;
    int high = data.size() - 1;
    while (low <= high && key >= data[low] && key <= data[high]) {
        if (low == high) {
            if (data[low] == key) return low;
            return -1;
        }
        int pos = low + (((double)(high - low) / (data[high] - data[low])) * (key - data[low]));
        if (data[pos] == key) {
            return pos;
        }
        if (data[pos] < key) {
            low = pos + 1;
        }
        else {
            high = pos - 1;
        }
    }
    return -1;
}

int main() {
    setlocale(LC_ALL, "Rus");
    vector<int> data;
    for (int i = 0; i < 25; ++i) {
        int element;
        cin >> element;
        data.push_back(element);
    }
    int key;

    cout << "Выберите метод поиска:\n";
    cout << "1 - Линейный поиск\n";
    cout << "2 - Бинарный поиск\n";
    cout << "3 - Интерполяционный поиск\n";
    cout << "Введите номер поиска: ";
    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Введите ключ для линейного поиска: ";
        cin >> key;
        cout << "Индекс элемента: " << linearSearch(data, key) << endl;
        break;
    case 2:
        cout << "Введите ключ для бинарного поиска: ";
        cin >> key;
        cout << "Индекс элемента: " << binarySearch(data, key) << endl;
        break;
    case 3:
        cout << "Введите ключ для интерполяционного поиска: ";
        cin >> key;
        cout << "Индекс элемента: " << interpolationSearch(data, key) << endl;
        break;
    default:
        cout << "Неверный выбор поиска.\n";
        return 1;
    }

    return 0;
}
