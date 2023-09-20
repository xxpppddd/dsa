#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }
    void insertNode(int position, int data);
    void deleteNode(int position);
    void printList();
};

void LinkedList::insertNode(int position, int data) {
    Node* newNode = new Node(data);

    if (position == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        if (current != nullptr) {
            newNode->next = current->next;
            current->next = newNode;
        }
    }
}

void LinkedList::deleteNode(int position) {
    if (position == 0) {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    } else {
        Node* current = head;
        for (int i = 0; i < position - 1; i++) {
            if (current == nullptr || current->next == nullptr) {
                break;
            }
            current = current->next;
        }
        if (current != nullptr && current->next != nullptr) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }
}

void LinkedList::printList() {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}


int main() {
    LinkedList linkedList;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string operation;
        int position, data;
        cin >> operation;

        if (operation == "insert") {
            cin >> position >> data;
            linkedList.insertNode(position, data);
        } else if (operation == "delete") {
            cin >> position;
            linkedList.deleteNode(position);
        }
    }

    linkedList.printList();

    return 0;
}

