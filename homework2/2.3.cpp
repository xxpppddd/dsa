#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node (int data) {
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

class doublyLinkedList {
public:
    Node* head;
    doublyLinkedList() {
        head = NULL;
    }
    Node* insertNode(Node* head, int data) {
        Node* newNode = new Node(data);
        newNode -> next = NULL;
        if (head == NULL) head = newNode;
        else {
            Node* p = head;
            while (p -> next != NULL) p = p -> next;
            p -> next = newNode;
            newNode -> prev = p;
        }
        return head;
    }
    int count_triplets(Node* head, int n) {;
        int cnt = 0;
        Node* p = head;
        p = p -> next;
        for (int i = 1; i <= n - 2; i++) {
            if ( p -> prev -> data + p -> data + p -> next -> data == 0) cnt++;
            p = p -> next;
        }
        return cnt;
    }
};
 int main() {
    doublyLinkedList dll;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Node* head = new Node(a[0]);
    dll.head = head;
    for (int i  = 1; i < n; i++) {
         head = dll.insertNode(head, a[i]);
    }
    cout << dll.count_triplets(head, n);

 }
