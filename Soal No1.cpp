#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList() : head(nullptr) {}

    void append(int data) {
        Node* newNode = new Node{data, nullptr, nullptr};
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void insertAtPosition(int data, int position) {
        Node* newNode = new Node{data, nullptr, nullptr};
        if (position == 1) {
            newNode->next = head;
            if (head != nullptr) {
                head->prev = newNode;
            }
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 1; i < position - 1 && temp != nullptr; ++i) {
                temp = temp->next;
            }
            if (temp != nullptr) {
                newNode->next = temp->next;
                newNode->prev = temp;
                if (temp->next != nullptr) {
                    temp->next->prev = newNode;
                }
                temp->next = newNode;
            } else {
                cout << "Posisi di luar jangkauan" << endl;
            }
        }
    }

    void display() {
        Node* temp = head;
        int nodeNumber = 1;
        while (temp != nullptr) {
            cout << "Node " << nodeNumber++ << ": " << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main() {
    DoublyLinkedList dll;
    int jumlahNode, data, posisi;

    cout << "Masukkan jumlah node (3 atau lebih): ";
    cin >> jumlahNode;

    for (int i = 1; i <= jumlahNode; ++i) {
        cout << "Input data untuk node " << i << ": ";
        cin >> data;
        dll.append(data);
    }

    cout << "Data yang dimasukkan ke dalam daftar adalah:" << endl;
    dll.display();

    cout << "Masukkan posisi untuk memasukkan node baru: ";
    cin >> posisi;
    cout << "Input data untuk posisi " << posisi << ": ";
    cin >> data;

    dll.insertAtPosition(data, posisi);

    cout << "Setelah penyisipan, daftar baru adalah:" << endl;
    dll.display();

    return 0;
}

