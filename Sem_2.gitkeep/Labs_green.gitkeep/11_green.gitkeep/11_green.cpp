#include <iostream>
#include <fstream>
using namespace std;

void WriteListToFile(const char* filename) {
    ofstream os(filename);

    if (!os) {
        cout << "Cannot open the file to output." << endl;
        return;
    }

    char str[80];
    cout << "Save the lines to HDD. Enter '!' to stop." << endl;
    do {
        cout << ":";
        cin.getline(str, 80);
        os << str << endl;
    } while (*str != '!');

    os.close();
}

int main() {
    setlocale(LC_ALL, "Rus");
    WriteListToFile("myfile.txt");
    return 0;
}