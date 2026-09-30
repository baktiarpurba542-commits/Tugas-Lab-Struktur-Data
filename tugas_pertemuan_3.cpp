#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

struct Stack {
    Node* top;
};

void init(Stack &s) {
    s.top = nullptr;
}

bool isEmpty(Stack &s) {
    return s.top == nullptr;
}

void push(Stack &s, char c) {
    Node* baru = new Node;
    baru->data = c;
    baru->next = s.top;
    s.top = baru;
}

char pop(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack kosong!" << endl;
        return '\0';
    }
    Node* hapus = s.top;
    char c = hapus->data;
    s.top = hapus->next;
    delete hapus;
    return c;
}

int main() {
    Stack s;
    init(s);

    string kata;
    cout << "Masukkan sebuah kata: ";
    cin >> kata;

    for (int i = 0; i < (int)kata.length(); i++) {
        push(s, kata[i]);
    }

    string hasil = "";
    while (!isEmpty(s)) {
        hasil += pop(s);
    }

    cout << "Kata terbalik: " << hasil << endl;
    return 0;
}
