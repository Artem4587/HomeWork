#include <iostream>
using namespace std;
class Point {
private:
    double x;
    double y;
    double z;

public:
    Point()
    {
        double x = 0;
        double y = 0;
        double z = 0;

    }

    Point(double x, double y, double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }

    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
    void setZ(double z) { this->z = z; }

    bool operator==(const Point& other)
    {
        return (x == other.x && y == other.y && z == other.z);
    }

    bool operator!=(const Point& other)
    {
        return !(*this == other);
    }

    bool operator<(const Point& other)
    {
        return (x + y + z) < (other.x + other.y + other.z);
    }

    bool operator>(const Point& other)
    {
        return (x + y + z) > (other.x + other.y + other.z);
    }

    bool operator<=(const Point& other)
    {
        return !(*this > other);
    }

    bool operator>=(const Point& other)
    {
        return !(*this < other);
    }

    Point operator-(const Point& other)
    {
        return Point(x - other.x, y - other.y, z - other.z);
    }

    Point& operator++()
    {
        x += 1.0;
        y += 1.0;
        z += 1.0;
        return *this;
    }
    Point operator++(int) {
        Point temp = *this;
        ++(*this);
        return temp;
    }
    void print() {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }
};

int main() {
    Point p1(1.0, 2.0, 3.0);
    Point p2(1.0, 2.0, 3.0);
    Point p3(4.0, 5.0, 6.0);

    cout << "p1: "; p1.print();
    cout << "p2: "; p2.print();
    cout << "p3: "; p3.print();
    cout << "p1 == p2: " << (p1 == p2) << endl;
    cout << "p1 != p3: " << (p1 != p3) << endl;
    cout << "p1 < p3: " << (p1 < p3) << endl;
    cout << "p1 > p3: " << (p1 > p3) << endl;

    Point p4 = p3 - p1;
    cout << "p3 - p1: "; p4.print();
    cout << "p1++: "; (p1++).print();
    cout << "p1 after p1++: "; p1.print();
    cout << "++p2: "; (++p2).print();
    cout << "p2 after ++p2: "; p2.print();
}