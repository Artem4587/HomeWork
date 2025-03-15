#include <iostream>
#include <string>
#include <sstream> // ��� �������������� ������ � �����
#include <vector> //  ��� ������ � ������������ ��������
#include <limits> // ��� numeric_limits
using namespace std;
class Room {
protected:
    int area;
    string name;
public:
    // ������������
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

    // �������
    int getArea() const { return area; }
    string getName() const { return name; }

    // ������ � ��������� ���������
    void setArea(int area) {
        if (area >= 0) {
            this->area = area;
        }
        else {
            cout << "������: ������������ �������. ����������� �������� 0." << endl;
            this->area = 0;
        }
    }
    // ����������� ����� ��� ������ ����������
    virtual void display() {
        cout << "���������: �������� = " << name << ", ������� = " << area << endl;
    }

    // ��������� ���������
    bool operator==(const Room& other) {
        return area == other.area && name == other.name;
    }

    // �������� �������� (������)
    Room operator+(const Room& other) {
        return Room(area + other.area, name + " + " + other.name);
    }

    // �������� ����������
    Room& operator++() { // ���������� ���������
        area++;
        return *this;
    }
    Room operator++(int) { // ����������� ���������
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
    // ������������
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
    // �������
    int getCapacity() { return capacity; }
    string getSubject() { return subject; }

    // ������ � ��������� ���������
    void setCapacity(int capacity) {
        if (capacity >= 0) {
            this->capacity = capacity;
        }
        else {
            cout << "������: ������������ �����������. ����������� �������� 0." << endl;
            this->capacity = 0;
        }
    }

    void display() override {
        cout << "������� ���������: �������� = " << getName() << ", ������� = " << getArea()
            << ", ����������� = " << capacity << ", ������� = " << subject << endl;
    }

    // ��������� ���������
    bool operator==(The_classroom& other) {
        return Room::operator==(other) && capacity == other.capacity && subject == other.subject;
    }
};
class Office : public Room {
private:
    int numComputers;
    string department;
public:
    // ������������
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

    // �������
    int getNumComputers() { return numComputers; }
    string getDepartment() { return department; }

    // ������ � ��������� ���������
    void setNumComputers(int numComputers) {
        if (numComputers >= 0) {
            this->numComputers = numComputers;
        }
        else {
            cout << "������: ������������ ���������� �����������. ����������� �������� 0." << endl;
            this->numComputers = 0;
        }
    }

    void display() override {
        cout << "�������: �������� = " << getName() << ", ������� = " << getArea()
            << ", ����������� = " << numComputers << ", ����� = " << department << endl;
    }

    // ��������� ���������
    bool operator==(Office& other) {
        return Room::operator==(other) && numComputers == other.numComputers && department == other.department;
    }
};
class Gym : public Room {
private:
    int numRacks;
    string sportType;
public:
    // ������������
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

    // �������
    int getNumRacks() { return numRacks; }
    string getSportType() { return sportType; }

    // ������ � ��������� ���������
    void setNumRacks(int numRacks) {
        if (numRacks >= 0) {
            this->numRacks = numRacks;
        }
        else {
            cout << "������: ������������ ���������� �����. ����������� �������� 0." << endl;
            this->numRacks = 0;
        }
    }

    void display() override {
        cout << "��������: �������� = " << getName() << ", ������� = " << getArea()
            << ", ����� = " << numRacks << ", ��� ������ = " << sportType << endl;
    }

    // ��������� ���������
    bool operator==(Gym& other) {
        return Room::operator==(other) && numRacks == other.numRacks && sportType == other.sportType;
    }
};
// ��������������� ������� ��� ����� ������ ����� � ��������� 
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
        cout << "������������ ����. ����������, ������� ����� �����." << endl;
    }
}
int main() {
    setlocale(LC_ALL, "RU");
    vector<Room*> rooms;
    int choice;

    do {
        cout << "\n--- ���� ---" << endl;
        cout << "1. �������� ���������" << endl;
        cout << "2. ������� ���������" << endl;
        cout << "3. ������� ��� ���������" << endl;
        cout << "4. �������� ���������" << endl;
        cout << "5. �����" << endl;
        choice = getIntInput("�������� ����� ����: ");

        switch (choice) {
        case 1: {
            int typeChoice = getIntInput("�������� ��� ��������� (1 - ���������, 2 - ���������, 3 - �������, 4 - ��������): ");
            int area;
            string name;

            if (typeChoice < 1 || typeChoice > 4) {
                cout << "�������� ��� ���������." << endl;
                break;
            }

            area = getIntInput("������� �������: ");
            cout << "������� ��������: ";
            getline(cin >> ws, name);

            switch (typeChoice) {
            case 1: {
                rooms.push_back(new Room(area, name));
                cout << "��������� ���������." << endl;
                break;
            }
            case 2: {
                int capacity = getIntInput("������� ����������� ���������: ");
                cout << "������� �������: ";
                string subject;
                getline(cin >> ws, subject);
                rooms.push_back(new The_classroom(area, name, capacity, subject));
                cout << "��������� ���������." << endl;
                break;
            }
            case 3: {
                int numComputers = getIntInput("������� ���������� ����������� � ��������: ");
                cout << "������� �����: ";
                string department;
                getline(cin >> ws, department);
                rooms.push_back(new Office(area, name, numComputers, department));
                cout << "������� ��������." << endl;
                break;
            }
            case 4: {
                int numRacks = getIntInput("������� ���������� ����� � ���������: ");
                cout << "������� ��� ������: ";
                string sportType;
                getline(cin >> ws, sportType);
                rooms.push_back(new Gym(area, name, numRacks, sportType));
                cout << "�������� ��������." << endl;
                break;
            }
            }
            break;
        }
        case 2: {
            if (rooms.empty()) {
                cout << "������ ��������� ����." << endl;
                break;
            }
            int index = getIntInput("������� ������ ��������� ��� ��������: ");
            if (index >= 0 && index < rooms.size()) {
                delete rooms[index]; // ����������� ������
                rooms.erase(rooms.begin() + index);
                cout << "��������� �������." << endl;
            }
            else {
                cout << "�������� ������." << endl;
            }
            break;
        }
        case 3: {
            if (rooms.empty()) {
                cout << "������ ��������� ����." << endl;
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
                cout << "���������� ������� ��� ��������� ��� ���������." << endl;
                break;
            }
            int index1 = getIntInput("������� ������ ������� ���������: ");
            int index2 = getIntInput("������� ������ ������� ���������: ");

            if (index1 >= 0 && index1 < rooms.size() && index2 >= 0 && index2 < rooms.size()) {
                if (*rooms[index1] == *rooms[index2]) {
                    cout << "��������� �����." << endl;
                }
                else {
                    cout << "��������� �� �����." << endl;
                }
            }
            else {
                cout << "�������� ������." << endl;
            }
            break;
        }
        case 5: {
            cout << "����� �� ���������." << endl;
            // ����������� ������
            for (Room* room : rooms) {
                delete room;
            }
            rooms.clear(); // ������� ������
            break;
        }
        default:
            cout << "�������� ����� ����." << endl;
        }
    } while (choice != 5);
}
