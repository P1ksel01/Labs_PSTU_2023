#include<iostream>
#include<ctime>
using namespace std;

int board[8][8];
int firstrow;
int firstcol;

bool Safe(int row, int col) {

	for (int i = 0; i < row; i++) if (board[i][col] == 1) return false;

	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) if (board[i][j] == 1) return false;

	for (int i = row, j = col; i < 8 && j < 8; i++, j++) if (board[i][j] == 1) return false;

	for (int i = row, j = col; i >= 0 && j < 8; i--, j++) if (board[i][j] == 1) return false;

	for (int i = row, j = col; i < 8 && j >= 0; i++, j--) if (board[i][j] == 1) return false;

	if (col == firstcol) return false;

	return true;
}

bool solve(int row) {
	if (row == 8) return true;

	if (row == firstrow) return solve(row + 1);

	for (int col = 0; col < 8; col++) {
		if (Safe(row, col)) {
			board[row][col] = 1;
			if (solve(row + 1)) return true;
			board[row][col] = 0;
		}
	}
	return false;
}

void printBoard() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) cout << ((board[i][j] == 1) ? "Q " : ". ");
		cout << "\n";
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) board[i][j] = 0;

	firstrow = rand() % 8;
	firstcol = rand() % 8;
	board[firstrow][firstcol] = 1;

	cout << "Исходное расположение\n";
	printBoard();

	if (solve(0)) { cout << "Решение найдено:\n"; printBoard(); }
	else cout << "Решения не существует\n";

	return 0;
}

