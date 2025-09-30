#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = nullptr;

void push(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    cout << value << " di-push ke stack\n";
}

void pop() {
    if (top == nullptr) {
        cout << "Stack kosong!\n";
        return;
    }
    cout << top->data << " di-pop dari stack\n";
    Node* temp = top;
    top = top->next;
    delete temp;
}

void display() {
    Node* temp = top;
    cout << "Isi stack: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    push(10);
    push(20);
    push(30);

    display();

    pop();

    display();

    return 0;
}
