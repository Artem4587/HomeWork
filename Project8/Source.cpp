#include <iostream>
using namespace std;
class MyClass {
private:
    int intValue;
    double doubleValue;
    string stringValue;

public:
    // Конструктор по умолчанию
    MyClass()
    {
        intValue = 0;
        doubleValue = 0.0;
        stringValue = "NONE";
        cout << "Конструктор по умолчанию вызван." << endl;
    }

    // Конструктор с параметрами
    MyClass(int i, double d, const string& s)
    {
        this->intValue = i;
        this->doubleValue = d;
        this->stringValue = s;
        cout << "Конструктор с параметрами вызван." << endl;
    }

    // Конструктор копирования с логированием и модификацией
    MyClass(const MyClass& other) :
        intValue(other.intValue + 1),
        doubleValue(other.doubleValue + 1.0),
        stringValue(other.stringValue)
    {
        cout << "Конструктор копирования вызван." << endl;
        cout << "  Копирование intValue: " << other.intValue << " -> " << intValue << endl;
        cout << "  Копирование doubleValue: " << other.doubleValue << " -> " << doubleValue << endl;
        cout << "  Копирование stringValue: " << other.stringValue << " -> " << stringValue << endl;
    }
    // Оператор присваивания копированием (для полноты картины)
    MyClass& operator=(const MyClass& other)
    {
        cout << "Оператор присваивания вызван." << endl;
        if (this != &other) {
            intValue = other.intValue + 1;
            doubleValue = other.doubleValue + 1.0;
            stringValue = other.stringValue;

            cout << "  Присваивание intValue: " << other.intValue << " -> " << intValue << endl;
            cout << "  Присваивание doubleValue: " << other.doubleValue << " -> " << doubleValue << endl;
            cout << "  Присваивание stringValue: " << other.stringValue << " -> " << stringValue << endl;
        }
        return *this;
    }

    // Метод для вывода значений
    void print()
    {
        cout << "intValue: " << intValue << endl;
        cout << "doubleValue: " << doubleValue << endl;
        cout << "stringValue: " << stringValue << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    MyClass obj1(10, 3.14, "Hello");
    cout << "obj1:" << endl;
    obj1.print();

    MyClass obj2 = obj1;
    cout << "obj2 (скопирована из obj1):" << endl;
    obj2.print();

    MyClass obj3;
    obj3 = obj1;
    cout << "obj3 (присвоена obj1):" << endl;
    obj3.print();
}