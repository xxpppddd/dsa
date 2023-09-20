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

class Stack {
public:
    Node* head;

    Stack() {
        head = NULL;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* p = head;
        while (p -> next != NULL) {
            p = p -> next;
        }
        p -> next = newNode;
    }

    void pop() {
        if (head == NULL) {
            return;
        }
        else {
            Node* p = head;
            while (p -> next -> next != NULL) {
                p = p -> next;
            }
            p -> next = NULL;

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
    Stack stack;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;

        if (operation == "push") {
            int x;
            cin >> x;
            stack.push(x);
        }
        else if (operation == "pop") {
            stack.pop();
        }
    }

    stack.print();

    return 0;
}


