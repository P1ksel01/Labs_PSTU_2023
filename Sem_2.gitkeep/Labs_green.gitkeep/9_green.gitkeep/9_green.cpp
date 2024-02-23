#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int Counter = 0;
	string stroka;
	ifstream file1;
	ofstream file2;
	ifstream file3;
	file1.open("F1.txt");
	file2.open("F2.txt");
	if ((file1.is_open()) && (file2.is_open())) cout << "Файлы открыты.\n";
	else cout << "Файлы не открыты!\n";
	bool flag = 0;
	cout << "F1:\n";
	while (getline(file1, stroka))
	{

		cout << stroka << "\n";
		for (int i = 0; i < stroka.length(); i++) {
			if (stroka[i] == '4') flag = 1;
			if (flag) file2 << stroka[i];
		}

	}


	file1.close();
	file2.close();
	file3.open("F2.txt");

	if (!file3.is_open()) cout << "Файл 2 не открыт!\n";

	vector<string> v;
	string s;
	cout << "F2:\n";
	while (getline(file3, stroka))
	{
		cout << stroka << "\n";
		istringstream iss(stroka);
		while (iss >> s) v.push_back(s);
		string ss = v[v.size() - 1];
		for (int i = 0;i < ss.length();i++) Counter++;

	}
	cout << Counter;
	file3.close();
	return 0;
}
