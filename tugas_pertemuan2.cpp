//buatlah program c++ menggunakan single linked lisst non-circular untuk menyimpan data 10 nilai mahasiswa
#include <iostream>
using namespace std;

//mendefenisikan node
struct Node{
    int data;
    Node* next;
};

int main(){
    //membuat node 1
    Node* node1 = new Node();
    node1-> data = 100;
    node1-> next = nullptr;

    // membuat node 2
    Node* node2 = new Node();
    node2-> data = 92;
    node2-> next = nullptr;

    // membuat node 3
    Node* node3 = new Node();
    node3-> data = 45;
    node3-> next = nullptr;

    // membuat node 4
    Node* node4 = new Node();
    node4-> data = 87;
    node4-> next = nullptr;

    // membuat node 5
    Node* node5 = new Node();
    node5-> data = 71;
    node5-> next = nullptr;

    // membuat node 6
    Node* node6 = new Node();
    node6-> data = 99;
    node6-> next = nullptr;

    // membuat node 7
    Node* node7 = new Node();
    node7-> data = 95;
    node7-> next = nullptr;

    // membuat node 8
    Node* node8 = new Node();
    node8-> data = 60;
    node8-> next = nullptr;

    // membuat node 9
    Node* node9 = new Node();
    node9-> data = 55;
    node9-> next = nullptr;

    // membuat node 10
    Node* node10 = new Node();
    node10-> data = 88;
    node10-> next = nullptr;

    //node 1 -> node 10 
    node1-> next = node2;
    node2-> next = node3;
    node3-> next = node4;
    node4-> next = node5;
    node5-> next = node6;
    node6-> next = node7;
    node7-> next = node8;
    node8-> next = node9;
    node9-> next = node10;


    //head and tail
    Node* head = node1;
    Node* tail = node10;

    cout << "Isi linked list: ";
    Node* temp = head;
    while (temp != nullptr){
        cout << temp-> data << " ";
        temp = temp-> next;
    }

    //menambahkan node baru di akhir
    Node* Node11 = new Node();
    Node11-> data = 50;
    Node11-> next = nullptr;
    tail-> next = Node11;
    tail = Node11;

    cout << endl;

    //menambahkan node baru di awal
    Node* Node12 = new Node();
    Node12-> data = 70;
    Node12-> next = head;
    head = Node12;

    temp = head;
    while (temp != nullptr){
        cout << temp-> data << " ";
        temp = temp-> next;
    }
    cout << endl;

    //menambahkan node baru di tengah
    Node* Node13 = new Node();
    Node13-> data = 0;
    Node13-> next = node3-> next;
    node3-> next = Node13;

    temp= head;
    while (temp != nullptr){
        cout << temp-> data << " ";
        temp = temp-> next;
    }
    cout << endl;

       //menghapus node ke 6
    temp = head;
    while (temp-> next ->data != 99){
        temp = temp-> next;
    }
    Node* hapus1 = temp-> next;
    temp-> next = hapus1-> next;
    delete hapus1;
    
    cout << "Isi linked list setelah menghapus node keenam: ";
    temp = head;
    while (temp != nullptr){
        cout << temp-> data << " ";
        temp = temp-> next;
    }
    cout<<endl;

    //menghapus node ke 8
    temp = head;
    while (temp-> next ->data != 60){
        temp = temp-> next;
    }

    Node* hapus2 = temp-> next;
    temp-> next = hapus2-> next;
    delete hapus2;
   
    cout<<" isi linked list setelah menghapus node kedelapan: ";
    temp = head;
    while (temp != nullptr){
        cout << temp-> data << " ";
        temp = temp-> next;
    }

    cout<<endl;

    
    Node* hapus = temp-> next; // node yang akan dihapus
    temp-> next = hapus-> next; // node sebelum node yang akan dihapus menunjuk ke 
    //node setekah node yang akan dihapus
    delete hapus;

    return 0;

}
