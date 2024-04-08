#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

// Вспомогательная функция для естественной сортировки: слияние двух отсортированных векторов
vector<int> merge(const vector<int>& left, const vector<int>& right) {
    vector<int> result;
    unsigned leftIndex = 0, rightIndex = 0;

    while (leftIndex < left.size() && rightIndex < right.size()) {
        if (left[leftIndex] < right[rightIndex]) {
            result.push_back(left[leftIndex]);
            leftIndex++;
        }
        else {
            result.push_back(right[rightIndex]);
            rightIndex++;
        }
    }

    // Добавляем оставшиеся элементы
    while (leftIndex < left.size()) result.push_back(left[leftIndex++]);
    while (rightIndex < right.size()) result.push_back(right[rightIndex++]);

    return result;
}

// Естественная сортировка
void naturalSort(vector<int>& arr) {
    bool isSorted = false;
    while (!isSorted) {
        isSorted = true;
        queue<vector<int>> q;

        // Разбиваем массив на отсортированные подпоследовательности
        for (size_t i = 0; i < arr.size();) {
            vector<int> seq;
            seq.push_back(arr[i++]);
            while (i < arr.size() && arr[i - 1] <= arr[i]) {
                seq.push_back(arr[i++]);
            }
            q.push(seq);
        }

        // Сливаем подпоследовательности
        while (q.size() > 1) {
            vector<int> seq1 = q.front();
            q.pop();
            vector<int> seq2 = q.front();
            q.pop();
            q.push(merge(seq1, seq2));
        }

        // Если в очереди осталась одна последовательность, значит массив отсортирован
        if (q.size() == 1) {
            arr = q.front();
            isSorted = true;
        }
    }
}

// Функция для разделения файла на серии и записи их во временные файлы
void distribute(const string& inputFile, const string& tempFile1, const string& tempFile2) {
    ifstream source(inputFile);
    ofstream out1(tempFile1);
    ofstream out2(tempFile2);
    int number;
    bool switchOutput = false;

    // Читаем числа из исходного файла и чередуем запись между двумя временными файлами
    while (source >> number) {
        (switchOutput ? out2 : out1) << number << ' ';
        switchOutput = !switchOutput;
    }

    out1.close();
    out2.close();
    source.close();
}

// Функция для слияния серий из двух временных файлов обратно в исходный файл
void merge(const string& f1, const string& f2, const string& outputFile) {
    ifstream in1(f1), in2(f2);
    ofstream output(outputFile);
    int num1, num2;
    bool f1HasData = static_cast<bool>(in1 >> num1);
    bool f2HasData = static_cast<bool>(in2 >> num2);

    while (f1HasData || f2HasData) {
        if (!f1HasData) {
            while (f2HasData) {
                output << num2 << ' ';
                f2HasData = static_cast<bool>(in2 >> num2);
            }
        }
        else if (!f2HasData) {
            while (f1HasData) {
                output << num1 << ' ';
                f1HasData = static_cast<bool>(in1 >> num1);
            }
        }
        else {
            if (num1 < num2) {
                output << num1 << ' ';
                f1HasData = static_cast<bool>(in1 >> num1);
            }
            else {
                output << num2 << ' ';
                f2HasData = static_cast<bool>(in2 >> num2);
            }
        }
    }

    in1.close();
    in2.close();
    output.close();
}

// Основная функция для многофазной сортировки
void polyphaseSort(const string& inputFile, const string& outputFile) {
    const string tempFile1 = "temp1.txt";
    const string tempFile2 = "temp2.txt";

    // Распределение серий
    distribute(inputFile, tempFile1, tempFile2);

    // Слияние серий
    merge(tempFile1, tempFile2, outputFile);

    // Удаление временных файлов
    remove(tempFile1.c_str());
    remove(tempFile2.c_str());
}



int main() {
    setlocale(LC_ALL, "Rus");
    const string inputFile = "input.txt";
    const string outputFile = "output.txt";
    vector<int> arr;
    int choice;
    cout << "Выберите метод сортировки:\n";
    cout << "1 - Многофазная сортировка\n";
    cout << "2 - Естественная сортировка\n";
    cout << "Введите номер сортировки: ";
    cin >> choice;

    switch (choice) {
    case 1:
        polyphaseSort(inputFile, outputFile);
        cout << "Массив отсортирован. Результат в файле: " << outputFile << endl;
        break;
    case 2:
        for (int i = 0; i < 25; ++i) {
            int element;
            cin >> element;
            arr.push_back(element);
        }
        naturalSort(arr);
        cout << "Отсортированный массив:\n";
        for (int num : arr) {
            cout << num << ' ';
        }
        cout << endl;
        break;
    default:
        cout << "Неверный выбор сортировки.\n";
        return 1;
    }

    return 0;
}
