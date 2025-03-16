#include <iostream>
using namespace std;
class ClassB; // Предварительное объявление ClassB

class ClassA {
private:
    int x;
    int y;

public:
    ClassA(int a, int b)
    {
        x = a;
        y = b;
    }

    friend void add(const ClassA& a, const ClassB& b);
};

class ClassB {
private:
    int m;
    int n;

public:
    ClassB(int c, int d)
    {
        m = c;
        n = d;
    }

    friend void add(const ClassA& a, const ClassB& b);
};

void add(const ClassA& a, const ClassB& b) {
    int sumX = a.x + b.m;
    int sumY = a.y + b.n;
    cout << "Sum of fields: " << sumX << ", " << sumY << endl;
}

int main() {
    ClassA objA(10, 20);
    ClassB objB(30, 40);
    add(objA, objB);
}