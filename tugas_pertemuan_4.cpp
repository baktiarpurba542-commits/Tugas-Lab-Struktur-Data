#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* kiri;
    Node* kanan;
};

Node* buatNode(int nilai) {
    Node* baru = new Node;
    baru->data = nilai;
    baru->kiri = nullptr;
    baru->kanan = nullptr;
    return baru;
}

Node* sisip(Node* root, int nilai) {
    if (root == nullptr) {
        return buatNode(nilai);  
    }
    if (nilai < root->data) {
        root->kiri = sisip(root->kiri, nilai);
    } else if (nilai > root->data) {
        root->kanan = sisip(root->kanan, nilai);
    }
    return root;
}

// preorder
void preOrder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preOrder(root->kiri);
    preOrder(root->kanan);
}

// in order
void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->kiri);
    cout << root->data << " ";
    inOrder(root->kanan);
}

// postorder
void postOrder(Node* root) {
    if (root == nullptr) return;
    postOrder(root->kiri);
    postOrder(root->kanan);
    cout << root->data << " ";
}

void hapusTree(Node* root) {
    if (root == nullptr) return;
    hapusTree(root->kiri);
    hapusTree(root->kanan);
    delete root;
}

int main() {
    Node* root = nullptr;
    int angka;

    cout << "Masukkan angka (input 0 untuk berhenti):" << endl;
    while (true) {
        cout << "> ";
        cin >> angka;
        if (angka == 0) break;
        root = sisip(root, angka);
    }

    if (root == nullptr) {
        cout << "Tree kosong." << endl;
        return 0;
    }

    cout << "\nPre-order  : ";
    preOrder(root);
    cout << "\nIn-order   : ";
    inOrder(root);
    cout << "\nPost-order : ";
    postOrder(root);
    cout << endl;

    hapusTree(root);
    return 0;
}
