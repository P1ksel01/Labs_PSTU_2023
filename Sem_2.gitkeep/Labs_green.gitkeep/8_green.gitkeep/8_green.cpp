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
        cerr << "Ошибка при открытии файла для записи." << endl;
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
        cerr << "Ошибка при открытии файла для чтения." << endl;
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
        cout << "Фамилия: " << person.surname << ", Имя: " << person.name
            << ", Отчество: " << person.patronymic << ", Адрес: " << person.address
            << ", Телефон: " << person.phone << ", Возраст: " << person.age << endl;
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
        cerr << "Неверный индекс для добавления элемента." << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    vector<Person> people = {
        {"Иванов", "Иван", "Иванович", "г. Москва, ул. Пушкина, д. 1", "123-456-7890", 30},
        {"Смирнов", "Алексей", "Владимирович", "г. Новосибирск, ул. Ленина, д. 10", "234-567-8901", 45},
        {"Кузнецов", "Борис", "Николаевич", "г. Екатеринбург, ул. Мира, д. 20", "345-678-9012", 37},
        {"Соколов", "Михаил", "Игоревич", "г. Казань, ул. Советская, д. 30", "456-789-0123", 29},
        {"Попов", "Дмитрий", "Анатольевич", "г. Самара, ул. Победы, д. 40", "567-890-1234", 52},
        {"Лебедев", "Андрей", "Сергеевич", "г. Омск, ул. Набережная, д. 50", "678-901-2345", 20}
    };

    const string filename = "people.bin";

    WriteToFile(people, filename);

    vector<Person> loaded_people = ReadFromFile(filename);
    PrintPeople(loaded_people);

    RemoveByAge(loaded_people, 30);

    Person new_person = { "Петров", "Петр", "Петрович", "г. Санкт-Петербург, наб. реки Фонтанки, д. 2", "098-765-4321", 25 };
    AddAfter(loaded_people, new_person, 0);

    PrintPeople(loaded_people);

    return 0;
}
