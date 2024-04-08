#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;

void countingSort(vector<int>& arr) {
    int max_val = *max_element(arr.begin(), arr.end());
    vector<int> count(max_val + 1, 0);

    for (int num : arr) {
        ++count[num];
    }

    int index = 0;
    for (int i = 0; i <= max_val; ++i) {
        while (count[i] > 0) {
            arr[index++] = i;
            --count[i];
        }
    }
}

void merge(vector<int>& left, vector<int>& right, vector<int>& bars) {
    int nL = left.size();
    int nR = right.size();
    int i = 0, j = 0, k = 0;

    while (j < nL && k < nR) {
        if (left[j] < right[k]) {
            bars[i] = left[j];
            j++;
        }
        else {
            bars[i] = right[k];
            k++;
        }
        i++;
    }
    while (j < nL) {
        bars[i] = left[j];
        j++; i++;
    }
    while (k < nR) {
        bars[i] = right[k];
        k++; i++;
    }
}

void mergeSort(vector<int>& arr) {
    if (arr.size() <= 1) return;

    int mid = arr.size() / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    mergeSort(left);
    mergeSort(right);
    merge(left, right, arr);
}

int partitionLomuto(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

void lomutoQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = partitionLomuto(arr, low, high);
        lomutoQuickSort(arr, low, pivot - 1);
        lomutoQuickSort(arr, pivot + 1, high);
    }
}

void shellSort(vector<int>& arr) {
    for (int gap = arr.size() / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < arr.size(); i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int partitionHoare(vector<int>& arr, int low, int high) {
    int pivot = arr[(low + high) / 2];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}

void hoareQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = partitionHoare(arr, low, high);
        hoareQuickSort(arr, low, pivot);
        hoareQuickSort(arr, pivot + 1, high);
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    vector<int> arr;

    for (int i = 0; i < 25; ++i) {
        int element;
        cin >> element;
        arr.push_back(element);
    }
    int choice;

    cout << "Выберите метод сортировки:\n";
    cout << "1 - Сортировка подсчетом\n";
    cout << "2 - Сортировка слиянием\n";
    cout << "3 - Быстрая сортировка по Ломуто\n";
    cout << "4 - Сортировка Шелла\n";
    cout << "5 - Быстрая сортировка по Хоару\n";
    cout << "Введите номер сортировки: ";
    cin >> choice;

    switch (choice) {
    case 1:
        countingSort(arr);
        break;
    case 2:
        mergeSort(arr);
        break;
    case 3:
        lomutoQuickSort(arr, 0, arr.size() - 1);
        break;
    case 4:
        shellSort(arr);
        break;
    case 5:
        hoareQuickSort(arr, 0, arr.size() - 1);
        break;
    default:
        cout << "Неверный выбор сортировки.\n";
        return 1;
    }

    cout << "Отсортированный массив:\n";
    copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
