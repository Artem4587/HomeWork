#include <iostream>
#include <vector>
using namespace std;
int main() {
    int data = 42; 

    int numPointers;
    cin >> numPointers;

    vector<int*> pointers;
    for (int i = 0; i < numPointers; i++) {
        pointers.push_back(&data); 
    }

    cout << "Адреса указателей:" << endl;
    for (int i = 0; i < numPointers; i++) {
        cout << "Указатель " << i + 1 << ": " << pointers[i] << endl;
    }
    cout << "Адрес объекта 'data': " << &data << endl;
}