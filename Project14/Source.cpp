#include <iostream>
#include <stdexcept>
using namespace std;
class DynamicArr {
private:
    int* data;
    int size;
    int capacity;

public:
    // 1. Конструктор
    DynamicArr(int capacity)
    {
        capacity = capacity;
        size = 0;
        cout << "Constructor called. Capacity: " << capacity << endl;
        data = new int[capacity];
    }

    // 2. Деструктор
    ~DynamicArr() {
        cout << "Destructor called. Size: " << size << ", Capacity: " << capacity << endl;
        delete[] data;
    }

    // 3. Конструктор копирования
    DynamicArr(const DynamicArr& other) {
        cout << "Copy constructor called. Copying from object with size: " << other.size << ", capacity: " << other.capacity << endl;

        size = other.size + 1;      // Увеличиваем размер на 1
        capacity = other.capacity + 1; // Увеличиваем capacity на 1

        cout << "Allocating memory for copy. New size: " << size << ", New capacity: " << capacity << endl;
        data = new int[capacity];

        cout << "Copying elements and incrementing values." << endl;
        for (int i = 0; i < other.size; i++) {
            data[i] = other.data[i] + 1; // Копируем и увеличиваем на 1
        }

        cout << "Copy constructor finished." << endl;
    }

    // 4. Сеттеры и геттеры
    int getSize() const { return size; }

    int getCapacity() const { return capacity; }

    int getElement(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }

    void setElement(int index, int value) {
        if (index < 0 || index >= capacity) {
            throw out_of_range("Index out of bounds");
        }
        if (index >= size)
            size = index + 1;
        data[index] = value;
    }

    void push_back(int value) {
        if (size == capacity) {
            int newCapacity = capacity == 0 ? 1 : capacity * 2;
            int* newData = new int[newCapacity];
            for (int i = 0; i < size; i++)
                newData[i] = data[i];
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
        data[size++] = value;
    }
};

int main() {
    DynamicArr arr1(5);
    arr1.setElement(0, 10);
    arr1.setElement(1, 20);
    arr1.push_back(30);


    cout << "Array 1 - Size: " << arr1.getSize() << ", Capacity: " << arr1.getCapacity() << endl;
    cout << "Element at index 0: " << arr1.getElement(0) << endl;
    cout << "Element at index 1: " << arr1.getElement(1) << endl;

    DynamicArr arr2 = arr1; // Конструктор копирования
    cout << "Array 2 - Size: " << arr2.getSize() << ", Capacity: " << arr2.getCapacity() << endl;
    cout << "Element at index 0: " << arr2.getElement(0) << endl;
    cout << "Element at index 1: " << arr2.getElement(1) << endl;
}