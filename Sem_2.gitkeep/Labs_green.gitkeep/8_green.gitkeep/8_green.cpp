#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

struct Person {
    string surname;
    string name;
    string patronymic;
    string address;
    string phone;
    int age;
};


void WriteToFile(const vector<Person>& people, const string& filename) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cerr << "������ ��� �������� ����� ��� ������." << endl;
        return;
    }

    for (const auto& person : people) {
        file.write(reinterpret_cast<const char*>(&person), sizeof(Person));
    }

    file.close();
}

vector<Person> ReadFromFile(const string& filename) {
    vector<Person> people;
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "������ ��� �������� ����� ��� ������." << endl;
        return people;
    }

    Person person;
    while (file.read(reinterpret_cast<char*>(&person), sizeof(Person))) {
        people.push_back(person);
    }

    file.close();
    return people;
}

void PrintPeople(const vector<Person>& people) {
    for (const auto& person : people) {
        cout << "�������: " << person.surname << ", ���: " << person.name
            << ", ��������: " << person.patronymic << ", �����: " << person.address
            << ", �������: " << person.phone << ", �������: " << person.age << endl;
    }
}


void RemoveByAge(vector<Person>& people, int age) {
    people.erase(remove_if(people.begin(), people.end(), age{ return age == person.age; }), people.end());
}


void AddAfter(vector<Person>& people, const Person& new_person, int index) {
    if (index >= 0 && index < people.size()) {
        people.insert(people.begin() + index + 1, new_person);
    }
    else {
        cerr << "�������� ������ ��� ���������� ��������." << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    vector<Person> people = {
        {"������", "����", "��������", "�. ������, ��. �������, �. 1", "123-456-7890", 30},
        {"�������", "�������", "������������", "�. �����������, ��. ������, �. 10", "234-567-8901", 45},
        {"��������", "�����", "����������", "�. ������������, ��. ����, �. 20", "345-678-9012", 37},
        {"�������", "������", "��������", "�. ������, ��. ���������, �. 30", "456-789-0123", 29},
        {"�����", "�������", "�����������", "�. ������, ��. ������, �. 40", "567-890-1234", 52},
        {"�������", "������", "���������", "�. ����, ��. ����������, �. 50", "678-901-2345", 20}
    };

    const string filename = "people.bin";

    WriteToFile(people, filename);

    vector<Person> loaded_people = ReadFromFile(filename);
    PrintPeople(loaded_people);

    RemoveByAge(loaded_people, 30);

    Person new_person = { "������", "����", "��������", "�. �����-���������, ���. ���� ��������, �. 2", "098-765-4321", 25 };
    AddAfter(loaded_people, new_person, 0);

    PrintPeople(loaded_people);

    return 0;
}
