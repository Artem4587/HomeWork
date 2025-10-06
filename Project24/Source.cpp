#include <iostream>

using namespace std;
class Node {
public:
    int data;    
    Node* next;  

    Node(int dataValue)
    {
        data = dataValue;
        next = nullptr;
    }
};


class LinkedList {
private:
    Node* head; 

public:

    LinkedList()
    {
        head = nullptr;
    }

    void addNode(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        cout << "���� � ������� " << data << " ������� ��������!" << endl;
    }

    void removeNode() {
        if (head == nullptr) {
            cout << "������ ����!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "���� ������� ������!" << endl;
    }

    void displayList() const {
        if (head == nullptr) {
            cout << "������ ����!" << endl;
            return;
        }
        Node* current = head;
        cout << "������: ";
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
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
    LinkedList list; 
    list.addNode(10);
    list.addNode(20);
    list.addNode(30);
    list.displayList();
    list.removeNode();
    list.displayList();
}