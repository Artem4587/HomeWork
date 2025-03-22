#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;
// ID Generator
class IDGenerator {
private:
    static int nextID;
    int id;

public:
    IDGenerator() : id(nextID++) {}
    virtual ~IDGenerator() {}
    int getID() const { return id; }
};

int IDGenerator::nextID = 0;

// Абстрактный класс Shape
class Shape : public IDGenerator {
protected:
    double M_PI;
public:
    virtual ~Shape() {}
    virtual double calculateArea() const = 0;
    virtual double calculateVolume() const { return 0.0; } 
    virtual void displayInfo() const = 0;

    virtual string getType() const = 0;

    bool operator>(const Shape& other) const {
        return calculateArea() > other.calculateArea();
    }

    Shape* operator+(const Shape& other) const {
        return new Rectangle(calculateArea() + other.calculateArea(), 1.0);
    }
};
class Circle : public Shape {
public:
    Circle(double radius)
    {
        this->radius = radius;
    }
    ~Circle() override {}
    double calculateArea() const override { return M_PI * radius * radius; }
    void displayInfo() const override {
        cout << "Circle (ID: " << getID() << "), Radius: " << radius << ", Area: " << calculateArea() << endl;
    }
    void describe() const { cout << "This is a 2D circle." << endl; }

    string getType() const override { return "Circle"; }

protected:
    double radius;
};
class Sphere : public Circle {
public:
    Sphere(double radius) : Circle(radius) {}
    ~Sphere() override {}
    double calculateVolume() const override {
        return (4.0 / 3.0) * M_PI * radius * radius * radius;
    }
    void displayInfo() const override {
        cout << "Sphere (ID: " << getID() << "), Radius: " << radius << ", Area: " << calculateArea() << ", Volume: " << calculateVolume() << endl;
    }
};
class Rectangle : public Shape {
public:
    Rectangle(double width, double height)
    {
        this->width = width;
        this->height = height;
    }
    ~Rectangle() override {}
    double calculateArea() const override { return width * height; }
    void displayInfo() const override {
        cout << "Rectangle (ID: " << getID() << "), Width: " << width << ", Height: " << height << ", Area: " << calculateArea() << endl;
    }
    void stretch() const { cout << "Rectangle is stretched." << endl; }

    string getType() const override { return "Rectangle"; }

protected:
    double width;
    double height;
};

class Cuboid : public Rectangle {
public:
    Cuboid(double width, double height, double depth)
        : Rectangle(width, height), depth(depth) {
    }
    ~Cuboid() override {}
    double calculateVolume() const override { return width * height * depth; }
    void displayInfo() const override {
        cout << "Cuboid (ID: " << getID() << "), Width: " << width << ", Height: " << height << ", Depth: " << depth << ", Volume: " << calculateVolume() << endl;
    }

private:
    double depth;
};

int main() {
    vector<Shape*> shapes;
    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(4.0, 6.0));
    shapes.push_back(new Sphere(3.0));
    shapes.push_back(new Cuboid(2.0, 3.0, 4.0));
    shapes.push_back(new Rectangle(5, 5));

    int choice;
    do {
        cout << "\nShape Menu:\n";
        cout << "1. Display all shapes\n";
        cout << "2. Compare shapes\n";
        cout << "3. Add shapes (area)\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1:
            for (auto* shape : shapes) {
                shape->displayInfo();
            }
            break;

        case 2: {
            if (shapes.size() < 2) {
                cout << "Not enough shapes to compare.\n";
                break;
            }
            int index1, index2;
            cout << "Enter two indices to compare: ";
            cin >> index1 >> index2;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid input. Please enter numbers.\n";
                break;
            }

            if (index1 >= 0 && index1 < shapes.size() && index2 >= 0 &&
                index2 < shapes.size()) {
                if (*shapes[index1] > *shapes[index2]) {
                    cout << "Shape " << index1 << " is larger than shape " << index2 << endl;
                }
                else {
                    cout << "Shape " << index2 << " is larger than or equal to shape " << index1 << endl;
                }
            }
            else {
                cout << "Invalid indices.\n";
            }
            break;
        }

        case 3: {
            if (shapes.size() < 2) {
                cout << "Not enough shapes to add.\n";
                break;
            }

            int index1, index2;
            cout << "Enter two indices to add: ";
            cin >> index1 >> index2;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid input. Please enter numbers.\n";
                break;
            }

            if (index1 >= 0 && index1 < shapes.size() && index2 >= 0 &&
                index2 < shapes.size()) {
                Shape* combined = *shapes[index1] + *shapes[index2];
                combined->displayInfo();
                delete combined;
            }
            else {
                cout << "Invalid indices.\n";
            }
            break;
        }

        case 0:
            cout << "Exiting.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    for (auto* shape : shapes) {
        delete shape;
    }
    shapes.clear();
}