#include <iostream>
#include <fstream>
#include <string>

struct Node {
    int data;
    Node* next;
};

Node* createList() {
    return nullptr;
}

void addElement(Node*& head, int value) {
    Node* newNode = new Node{ value, head };
    head = newNode;
}

void deleteElement(Node*& head, int value) {
    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) return;

    if (prev == nullptr) {
        head = temp->next;
    }
    else {
        prev->next = temp->next;
    }

    delete temp;
}

void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << ' ';
        head = head->next;
    }
    std::cout << std::endl;
}

void writeListToFile(Node* head, const std::string& filename) {
    std::ofstream file(filename);
    while (head != nullptr) {
        file << head->data << std::endl;
        head = head->next;
    }
    file.close();
}

void destroyList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void restoreListFromFile(Node*& head, const std::string& filename) {
    destroyList(head);
    std::ifstream file(filename);
    int value;
    while (file >> value) {
        addElement(head, value);
    }
    file.close();
}

int main() {
    Node* myList = createList();

    addElement(myList, 1);
    addElement(myList, 2);
    addElement(myList, 3);

    printList(myList);

    writeListToFile(myList, "list.txt");

    deleteElement(myList, 2);

    printList(myList);

    destroyList(myList);

    restoreListFromFile(myList, "list.txt");

    printList(myList);

    destroyList(myList);

    return 0;
}
