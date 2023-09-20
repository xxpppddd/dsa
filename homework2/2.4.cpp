#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Queue {
public:
    Node* head;
    Node* tail;

    Queue() {
        head = NULL;
        tail = NULL;
    }

    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (tail == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void dequeue() {
        if (head == NULL) {
            return;
        } else {
            head = head->next;
            if (head == NULL) {
                tail = NULL;
            }
        }
    }

    void print() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
    }
};


int main() {
    Queue queue;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;

        if (operation == "enqueue") {
            int x;
            cin >> x;
            queue.enqueue(x);
        }
        else if (operation == "dequeue") {
            queue.dequeue();
        }
    }

    queue.print();

    return 0;
}


