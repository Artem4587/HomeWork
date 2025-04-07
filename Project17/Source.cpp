#include <iostream>
using namespace std;
// Базовый класс для электромобилей
class ElectricVehicle {
public:
    ElectricVehicle(int batteryLevel)
    {
        this->batteryLevel_ = batteryLevel;
    }

    void charge(int amount) {
        batteryLevel_ += amount;
        cout << "Charged " << amount << " units. Battery level: " << batteryLevel_ << endl;
    }

    void showBattery() const {
        cout << "Battery level: " << batteryLevel_ << endl;
    }

protected:
    int batteryLevel_;
};

// Базовый класс для наземного транспорта
class LandTransport {
public:
    LandTransport(int speed)
    {
        this->speed_ = speed;
    }

    void accelerate(int value) {
        speed_ += value;
        cout << "Accelerated by " << value << ". Speed: " << speed_ << endl;
    }

    void brake(int value) {
        speed_ -= value;
        cout << "Braked by " << value << ". Speed: " << speed_ << endl;
    }

protected:
    int speed_;
};

// Базовый класс для водного транспорта
class WaterTransport {
public:
    WaterTransport(int depth)
    {
        this->depth_ = depth;
    }

    void dive(int value) {
        depth_ += value;
        cout << "Dived by " << value << ". Depth: " << depth_ << endl;
    }

    void surface(int value) {
        depth_ -= value;
        cout << "Surfaced by " << value << ". Depth: " << depth_ << endl;
    }

protected:
    int depth_;
};

// Класс ElectricCar, наследуемый от ElectricVehicle и LandTransport
class ElectricCar : public ElectricVehicle, public LandTransport {
public:
    ElectricCar(int batteryLevel, int speed) : ElectricVehicle(batteryLevel), LandTransport(speed) {}

    void drive() {
        cout << "Driving at speed: " << speed_ << ", Battery level: " << batteryLevel_ << endl;
    }
};

// Класс ElectricBoat, наследуемый от ElectricVehicle и WaterTransport
class ElectricBoat : public ElectricVehicle, public WaterTransport {
public:
    ElectricBoat(int batteryLevel, int depth) : ElectricVehicle(batteryLevel), WaterTransport(depth) {}

    void sail() {
        cout << "Sailing at depth: " << depth_ << ", Battery level: " << batteryLevel_ << endl;
    }
};

// Класс AmphibiousVehicle, наследуемый от ElectricVehicle, LandTransport и WaterTransport
class AmphibiousVehicle : public ElectricVehicle, public LandTransport, public WaterTransport {
public:
    AmphibiousVehicle(int batteryLevel, int speed, int depth) : ElectricVehicle(batteryLevel), LandTransport(speed), WaterTransport(depth), landMode_(true) {}

    void switchToLandMode() {
        if (!landMode_) {
            cout << "Switching to land mode." << endl;
            landMode_ = true;
        }
        else {
            cout << "Already in land mode." << endl;
        }
    }

    void switchToWaterMode() {
        if (landMode_) {
            cout << "Switching to water mode." << endl;
            landMode_ = false;
        }
        else {
            cout << "Already in water mode." << endl;
        }
    }

    void drive() {
        if (landMode_) {
            cout << "Driving on land at speed: " << speed_ << ", Battery level: " << batteryLevel_ << endl;
        }
        else {
            cout << "Cannot drive on land while in water mode." << endl;
        }
    }

    void sail() {
        if (!landMode_) {
            cout << "Sailing in water at depth: " << depth_ << ", Battery level: " << batteryLevel_ << endl;
        }
        else {
            cout << "Cannot sail in water while in land mode." << endl;
        }
    }

private:
    bool landMode_;
};

int main() {
    ElectricCar car(50, 60);
    car.charge(20);
    car.drive();
    car.accelerate(10);
    car.brake(5);
    car.showBattery();

    ElectricBoat boat(40, 5);
    boat.charge(30);
    boat.sail();
    boat.dive(2);
    boat.surface(1);
    boat.showBattery();

    AmphibiousVehicle amphibian(70, 30, 2);
    amphibian.showBattery();
    amphibian.drive();
    amphibian.sail();
    amphibian.switchToWaterMode();
    amphibian.sail();
    amphibian.dive(3);
    amphibian.surface(2);
    amphibian.switchToLandMode();
    amphibian.drive();
    amphibian.accelerate(20);
    amphibian.brake(10);
}