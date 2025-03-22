#include <iostream>
using namespace std;
class MyClass {
private:
    int intValue;
    double doubleValue;
    string stringValue;

public:
    // ����������� �� ���������
    MyClass()
    {
        intValue = 0;
        doubleValue = 0.0;
        stringValue = "NONE";
        cout << "����������� �� ��������� ������." << endl;
    }

    // ����������� � �����������
    MyClass(int i, double d, const string& s)
    {
        this->intValue = i;
        this->doubleValue = d;
        this->stringValue = s;
        cout << "����������� � ����������� ������." << endl;
    }

    // ����������� ����������� � ������������ � ������������
    MyClass(const MyClass& other) :
        intValue(other.intValue + 1),
        doubleValue(other.doubleValue + 1.0),
        stringValue(other.stringValue)
    {
        cout << "����������� ����������� ������." << endl;
        cout << "  ����������� intValue: " << other.intValue << " -> " << intValue << endl;
        cout << "  ����������� doubleValue: " << other.doubleValue << " -> " << doubleValue << endl;
        cout << "  ����������� stringValue: " << other.stringValue << " -> " << stringValue << endl;
    }
    // �������� ������������ ������������ (��� ������� �������)
    MyClass& operator=(const MyClass& other)
    {
        cout << "�������� ������������ ������." << endl;
        if (this != &other) {
            intValue = other.intValue + 1;
            doubleValue = other.doubleValue + 1.0;
            stringValue = other.stringValue;

            cout << "  ������������ intValue: " << other.intValue << " -> " << intValue << endl;
            cout << "  ������������ doubleValue: " << other.doubleValue << " -> " << doubleValue << endl;
            cout << "  ������������ stringValue: " << other.stringValue << " -> " << stringValue << endl;
        }
        return *this;
    }

    // ����� ��� ������ ��������
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
    cout << "obj2 (����������� �� obj1):" << endl;
    obj2.print();

    MyClass obj3;
    obj3 = obj1;
    cout << "obj3 (��������� obj1):" << endl;
    obj3.print();
}