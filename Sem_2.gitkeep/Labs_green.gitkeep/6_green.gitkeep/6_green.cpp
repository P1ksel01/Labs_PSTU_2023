#include<iostream>
#include<ctime>
#include<vector>
#include<string>
#include<sstream>
#include<string.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	cout << "¬ведите строку: \n";
	string str;
	string s;

	vector<string> v;
	getline(cin, str);

	istringstream iss(str);

	while (iss >> s) v.push_back(s);

	for (int i = 0; i < v.size(); i++) {
		string ss = v[i];
		int c = 0;
		for (int i = 0;i < ss.length();i++) {
			if (ss[i] == '0' || ss[i] == '1' || ss[i] == '2' || ss[i] == '3' || ss[i] == '4' || ss[i] == '5'
				|| ss[i] == '6' || ss[i] == '7' || ss[i] == '8' || ss[i] == '9') {
				c++;
			}
		}
		if (c == 1) cout << v[i] << "\n";
	}

	return 0;
}
