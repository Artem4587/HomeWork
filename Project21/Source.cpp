#include <iostream>
using namespace std;

struct Node {
    int data;     
    Node* next;     

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head; 

    LinkedList() : head(nullptr) {}

    void append(int value) {
        Node* newNode = new Node(value); 

        if (head == nullptr) { 
            head = newNode;    
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    LinkedList myList;

    myList.append(10);
    myList.append(20);
    myList.append(30);

    cout << "Список: ";
    myList.printList(); 
}