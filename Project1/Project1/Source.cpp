#include <iostream>
#include <string>
#include <sstream> // для преобразования строки в число
#include <vector> //  для работы с динамическим массивом
#include <limits> // для numeric_limits
using namespace std;
class Room {
protected:
    int area;
    string name;
public:
    // Конструкторы
    Room()
    {
        area = 0;
        name = "NONE";
    }
    Room(int area, const string& name) : area(area), name(name)
    {
        this->area = area;
        this->name = name;
    }
    virtual ~Room() {}

    // Геттеры
    int getArea() const { return area; }
    string getName() const { return name; }

    // Сеттер с проверкой диапазона
    void setArea(int area) {
        if (area >= 0) {
            this->area = area;
        }
        else {
            cout << "Ошибка: Некорректная площадь. Установлено значение 0." << endl;
            this->area = 0;
        }
    }
    // Виртуальный метод для вывода информации
    virtual void display() {
        cout << "Помещение: Название = " << name << ", Площадь = " << area << endl;
    }

    // Операторы сравнения
    bool operator==(const Room& other) {
        return area == other.area && name == other.name;
    }

    // Оператор сложения (пример)
    Room operator+(const Room& other) {
        return Room(area + other.area, name + " + " + other.name);
    }

    // Оператор инкремента
    Room& operator++() { // Префиксный инкремент
        area++;
        return *this;
    }
    Room operator++(int) { // Постфиксный инкремент
        Room temp = *this;
        area++;
        return temp;
    }
};
class The_classroom : public Room {
private:
    int capacity;
    string subject;
public:
    // Конструкторы
    The_classroom()
    {
        capacity = 0;
        subject = "NONE";
    }
    The_classroom(int area, const string& name, int capacity, const string& subject)
        : Room(area, name), capacity(capacity), subject(subject)
    {
        this->area = area;
        this->name = name;
        this->capacity = capacity;
        this->subject = subject;
    }
    // Геттеры
    int getCapacity() { return capacity; }
    string getSubject() { return subject; }

    // Сеттер с проверкой диапазона
    void setCapacity(int capacity) {
        if (capacity >= 0) {
            this->capacity = capacity;
        }
        else {
            cout << "Ошибка: Некорректная вместимость. Установлено значение 0." << endl;
            this->capacity = 0;
        }
    }

    void display() override {
        cout << "Учебная аудитория: Название = " << getName() << ", Площадь = " << getArea()
            << ", Вместимость = " << capacity << ", Предмет = " << subject << endl;
    }

    // Операторы сравнения
    bool operator==(The_classroom& other) {
        return Room::operator==(other) && capacity == other.capacity && subject == other.subject;
    }
};
class Office : public Room {
private:
    int numComputers;
    string department;
public:
    // Конструкторы
    Office()
    {
        numComputers = 0;
        department = "NONE";
    }
    Office(int area, const string& name, int numComputers, const string& department)
        : Room(area, name), numComputers(numComputers), department(department)
    {
        this->area = area;
        this->name = name;
        this->numComputers = numComputers;
        this->department = department;
    }

    // Геттеры
    int getNumComputers() { return numComputers; }
    string getDepartment() { return department; }

    // Сеттер с проверкой диапазона
    void setNumComputers(int numComputers) {
        if (numComputers >= 0) {
            this->numComputers = numComputers;
        }
        else {
            cout << "Ошибка: Некорректное количество компьютеров. Установлено значение 0." << endl;
            this->numComputers = 0;
        }
    }

    void display() override {
        cout << "Кабинет: Название = " << getName() << ", Площадь = " << getArea()
            << ", Компьютеров = " << numComputers << ", Отдел = " << department << endl;
    }

    // Операторы сравнения
    bool operator==(Office& other) {
        return Room::operator==(other) && numComputers == other.numComputers && department == other.department;
    }
};
class Gym : public Room {
private:
    int numRacks;
    string sportType;
public:
    // Конструкторы
    Gym()
    {
        numRacks = 0;
        sportType = "NONE";
    }
    Gym(int area, const string& name, int numRacks, const string& sportType)
        : Room(area, name), numRacks(numRacks), sportType(sportType)
    {
        this->area = area;
        this->name = name;
        this->numRacks = numRacks;
        this->sportType = sportType;
    }

    // Геттеры
    int getNumRacks() { return numRacks; }
    string getSportType() { return sportType; }

    // Сеттер с проверкой диапазона
    void setNumRacks(int numRacks) {
        if (numRacks >= 0) {
            this->numRacks = numRacks;
        }
        else {
            cout << "Ошибка: Некорректное количество стоек. Установлено значение 0." << endl;
            this->numRacks = 0;
        }
    }

    void display() override {
        cout << "Спортзал: Название = " << getName() << ", Площадь = " << getArea()
            << ", Стоек = " << numRacks << ", Тип спорта = " << sportType << endl;
    }

    // Операторы сравнения
    bool operator==(Gym& other) {
        return Room::operator==(other) && numRacks == other.numRacks && sportType == other.sportType;
    }
};
// Вспомогательная функция для ввода целого числа с проверкой 
int getIntInput(const string& prompt) {
    int value;
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        stringstream ss(input);
        if (ss >> value) {
            if (ss.eof()) {
                return value;
            }
        }
        cout << "Некорректный ввод. Пожалуйста, введите целое число." << endl;
    }
}
int main() {
    setlocale(LC_ALL, "RU");
    vector<Room*> rooms;
    int choice;

    do {
        cout << "\n--- Меню ---" << endl;
        cout << "1. Добавить помещение" << endl;
        cout << "2. Удалить помещение" << endl;
        cout << "3. Вывести все помещения" << endl;
        cout << "4. Сравнить помещения" << endl;
        cout << "5. Выход" << endl;
        choice = getIntInput("Выберите пункт меню: ");

        switch (choice) {
        case 1: {
            int typeChoice = getIntInput("Выберите тип помещения (1 - Помещение, 2 - Аудитория, 3 - Кабинет, 4 - Спортзал): ");
            int area;
            string name;

            if (typeChoice < 1 || typeChoice > 4) {
                cout << "Неверный тип помещения." << endl;
                break;
            }

            area = getIntInput("Введите площадь: ");
            cout << "Введите название: ";
            getline(cin >> ws, name);

            switch (typeChoice) {
            case 1: {
                rooms.push_back(new Room(area, name));
                cout << "Помещение добавлено." << endl;
                break;
            }
            case 2: {
                int capacity = getIntInput("Введите вместимость аудитории: ");
                cout << "Введите предмет: ";
                string subject;
                getline(cin >> ws, subject);
                rooms.push_back(new The_classroom(area, name, capacity, subject));
                cout << "Аудитория добавлена." << endl;
                break;
            }
            case 3: {
                int numComputers = getIntInput("Введите количество компьютеров в кабинете: ");
                cout << "Введите отдел: ";
                string department;
                getline(cin >> ws, department);
                rooms.push_back(new Office(area, name, numComputers, department));
                cout << "Кабинет добавлен." << endl;
                break;
            }
            case 4: {
                int numRacks = getIntInput("Введите количество стоек в спортзале: ");
                cout << "Введите тип спорта: ";
                string sportType;
                getline(cin >> ws, sportType);
                rooms.push_back(new Gym(area, name, numRacks, sportType));
                cout << "Спортзал добавлен." << endl;
                break;
            }
            }
            break;
        }
        case 2: {
            if (rooms.empty()) {
                cout << "Список помещений пуст." << endl;
                break;
            }
            int index = getIntInput("Введите индекс помещения для удаления: ");
            if (index >= 0 && index < rooms.size()) {
                delete rooms[index]; // Освобождаем память
                rooms.erase(rooms.begin() + index);
                cout << "Помещение удалено." << endl;
            }
            else {
                cout << "Неверный индекс." << endl;
            }
            break;
        }
        case 3: {
            if (rooms.empty()) {
                cout << "Список помещений пуст." << endl;
                break;
            }
            for (size_t i = 0; i < rooms.size(); i++) {
                cout << i << ": ";
                rooms[i]->display();
            }
            break;
        }
        case 4: {
            if (rooms.size() < 2) {
                cout << "Необходимо минимум два помещения для сравнения." << endl;
                break;
            }
            int index1 = getIntInput("Введите индекс первого помещения: ");
            int index2 = getIntInput("Введите индекс второго помещения: ");

            if (index1 >= 0 && index1 < rooms.size() && index2 >= 0 && index2 < rooms.size()) {
                if (*rooms[index1] == *rooms[index2]) {
                    cout << "Помещения равны." << endl;
                }
                else {
                    cout << "Помещения не равны." << endl;
                }
            }
            else {
                cout << "Неверный индекс." << endl;
            }
            break;
        }
        case 5: {
            cout << "Выход из программы." << endl;
            // Освобождаем память
            for (Room* room : rooms) {
                delete room;
            }
            rooms.clear(); // Очищаем вектор
            break;
        }
        default:
            cout << "Неверный пункт меню." << endl;
        }
    } while (choice != 5);
}
