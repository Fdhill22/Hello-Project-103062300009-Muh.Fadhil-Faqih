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

    int findMax() {
        if (head == nullptr) {
            cout << "Daftar kosong!" << endl;
            return -1;
        }
        int maxVal = head->data;
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data > maxVal) {
                maxVal = temp->data;
            }
            temp = temp->next;
        }
        return maxVal;
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
    int jumlahNode, data;
 
    cout << "Masukkan jumlah node: ";
    cin >> jumlahNode;

    for (int i = 1; i <= jumlahNode; ++i) {
        cout << "Input data untuk node " << i << ": ";
        cin >> data;
        dll.append(data);
    }

    cout << "Data yang dimasukkan ke dalam daftar adalah:" << endl;
    dll.display();

    int maxVal = dll.findMax();
    if (maxVal != -1) {
        cout << "Nilai Maksimum dalam Linked List: " << maxVal << endl;
    }

    return 0;
}

