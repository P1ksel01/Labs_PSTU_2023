#include<iostream>
#include <cstdlib>
#include<ctime>
using namespace std;

void delete_row(int arr[100][100], int& n, int m, int row) {

	for (int i = row; i < n - 1; i++) for (int j = 0; j < m; j++) arr[i][j] = arr[i + 1][j];
	n--;
	for (int j = 0; j < m; j++) arr[n][j] = 0;
}

int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int n, m;
	cout << "������� ���������� ����� � �������� �������: ";
	cin >> n >> m;

	int arr[100][100];
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) arr[i][j] = rand() % 101 - 50;

	cout << "�������� ������:" << "\n";

	for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) cout << arr[i][j] << "\t";cout << "\n"; }

	int a, b;
	cout << "������� ������ �����, ������� ����� ������� (�� 1 �� " << n << "): ";
	cin >> a >> b;

	while (a <= b) { delete_row(arr, n, m, a - 1); b--; }


	// ������� �������� ������
	cout << "�������� ������:" << endl;
	for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) cout << arr[i][j] << "\t";cout << "\n"; }
	return 0;
}