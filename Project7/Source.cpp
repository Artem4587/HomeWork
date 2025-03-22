#include <iostream>
#include <vector>
using namespace std;

// Функция логирования (простая)
void logMessage(const string& message) {
    cout << "[LOG] " << message << endl;
}
class Vehicle {
public:
    // Конструктор по умолчанию
    Vehicle()
    {
        model = "Unknown";
        year = 2000;
        logMessage("Vehicle created (default)");
    }
    Vehicle(const string& model, int year) 
    {
        this->model = model;
        this->year = year;
        logMessage("Vehicle created: " + model);
    }

    virtual ~Vehicle() {
        logMessage("Vehicle destroyed: " + model);
    }

    virtual void displayInfo() const {
        cout << "Vehicle: " << model << ", Year: " << year << endl;
    }

protected:
    string model;
    int year;
};
class Car : public Vehicle {
public:
    Car(const string& model, int year, int numDoors)
    {
        this->model = model;
        this->year = year;
        this->numDoors = numDoors;
        logMessage("Car created: " + model);
    }

    ~Car() override {
        logMessage("Car destroyed: " + model);
    }

    void displayInfo() const override {
        cout << "Car: " << model << ", Year: " << year << ", Doors: " << numDoors << endl;
    }

private:
    int numDoors;
};
class Bike : public Vehicle {
public:
    Bike(const string& model, int year, bool hasBasket)
    {
        this->model = model;
        this->year = year;
        this->hasBasket = hasBasket;
        logMessage("Bike created: " + model);
    }

    ~Bike() override {
        logMessage("Bike destroyed: " + model);
    }

    void displayInfo() const override {
        cout << "Bike: " << model << ", Year: " << year << ", Basket: " << (hasBasket ? "Yes" : "No") << endl;
    }

private:
    bool hasBasket;
};

int main() {
    vector<Vehicle*> vehicles;

    // Динамически выделяем объекты Car и Bike
    vehicles.push_back(new Car("Toyota Camry", 2022, 4));
    vehicles.push_back(new Bike("Giant Talon", 2021, true));
    vehicles.push_back(new Car("Honda Civic", 2023, 2));
    vehicles.push_back(new Vehicle("Generic Vehicle", 2020)); // Пример создания базового класса

    for (Vehicle* vehicle : vehicles) {
        vehicle->displayInfo();
    }

    // Освобождаем выделенную память
    for (Vehicle* vehicle : vehicles) {
        delete vehicle;
    }
    vehicles.clear(); 

    logMessage("Program finished");
}