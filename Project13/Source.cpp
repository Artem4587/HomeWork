#include <iostream> 
#include <string>   
#include <iomanip> //��� ���������������� ������ 

using namespace std;

class MobilePhone {
private:
    int ram;
    double displaySize;
    string model;
    string os;

public:

    // ����������� �� ���������
    MobilePhone()
    {
        int ram = 0;
        double displaySize = 0;
        string model = "NONE";
        string os = "NONE";
    }

    // ����������� � �����������
    MobilePhone(int ram, double displaySize, string model, string os)
    {
        this->ram = ram;
        this->displaySize = displaySize;
        this->model = model;
        this->os = os;
    };

    // ������ ������� (�������)
    int getRam() { return ram; }
    double getDisplaySize() { return displaySize; }
    string getModel() { return model; }
    string getOs() { return os; }

    // ������ ��������� (�������)
    void setRam(int ram) { this->ram = ram; }
    void setDisplaySize(double displaySize) { this->displaySize = displaySize; }
    void setModel(string model) { this->model = model; }
    void setOs(string os) { this->os = os; }

    string calculateUsabilityRating() const { // �����, ����������� ������� �������� �������������
        if (ram < 2048 && displaySize < 5.0) {
            return "������ ������������������";
        }
        else if (ram >= 4096 && displaySize >= 6.0) {
            return "������� ������������������";
        }
        else { // �����
            return "������� ������������������";
        }
    }

    // ����� ��� ������ ���������� �� �������
    void Info() const {
        cout << "������: " << model << endl;
        cout << "��: " << os << endl;
        cout << "RAM: " << ram << " MB" << endl;
        cout << "������ ������: " << fixed << setprecision(1) << displaySize << " ������" << endl;
        cout << "������������������: " << calculateUsabilityRating() << endl;
        cout << "------------------------" << endl;
    }
};


void Menu() {
    cout << "\n����:" << endl;
    cout << "1. �������� ������ ������" << endl;
    cout << "2. �������� ������ � �������" << endl;
    cout << "3. ������������� ������" << endl;
    cout << "4. ������� ���������� ��� ���� ��������" << endl;
    cout << "5. ����������� ������� �� RAM" << endl;
    cout << "6. �����" << endl;
    cout << "�������� ��������: ";
}

int main() {
    setlocale(LC_ALL, "RU");

    const int MAX_PHONES = 10;

    MobilePhone phones[MAX_PHONES];

    int phoneCount = 0;
    int choice;

    do {

        Menu();

        cin >> choice;

        if (cin.fail())
        {
            cin.clear(); // ������� ���� ������ cin

            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ����� �����, ����� ������ ��������� ����
        }

        switch (choice) {
        case 1: {
            if (phoneCount < MAX_PHONES) {
                phones[phoneCount] = MobilePhone();
                cout << "������ ��������." << endl;
            }
            else {
                cout << "������ ��������, ���������� �������� ����� ������." << endl;
            }
            break;
        }
        case 2: {
            if (phoneCount < MAX_PHONES) {
                int ram;
                double displaySize;
                string model, os;

                cout << "������� RAM (MB): ";
                cin >> ram;

                cout << "������� ������ ������ (�����): ";
                cin >> displaySize;

                cin.ignore();

                cout << "������� ������: ";
                getline(cin, model);

                cout << "������� ��: ";
                getline(cin, os);

                phones[phoneCount] = MobilePhone(ram, displaySize, model, os);
                phoneCount++;
                cout << "������ ��������." << endl;
            }
            else {
                cout << "������ ��������, ���������� �������� ����� ������." << endl;
            }
            break;
        }
        case 3: {
            if (phoneCount > 0) {
                int index;

                cout << "������� ������ ������� ��� �������������� (0-" << phoneCount - 1 << "): ";
                cin >> index;

                if (index >= 0 && index < phoneCount) {
                    int fieldChoice;

                    cout << "����� ���� �� ������ ��������?" << endl;
                    cout << "1. RAM" << endl;
                    cout << "2. ������ ������" << endl;
                    cout << "3. ������" << endl;
                    cout << "4. ��" << endl;
                    cout << "�������� ����: ";
                    cin >> fieldChoice;

                    switch (fieldChoice) {
                    case 1: {
                        int ram;
                        cout << "������� ����� �������� RAM: ";
                        cin >> ram;
                        phones[index].setRam(ram);
                        break;
                    }
                    case 2: {
                        double displaySize;
                        cout << "������� ����� ������ ������: ";
                        cin >> displaySize;
                        phones[index].setDisplaySize(displaySize);
                        break;
                    }
                    case 3: {
                        string model;
                        cin.ignore();
                        cout << "������� ����� ������: ";
                        getline(cin, model);
                        phones[index].setModel(model);
                        break;
                    }
                    case 4: {
                        string os;
                        cin.ignore();
                        cout << "������� ����� ��: ";
                        getline(cin, os);
                        phones[index].setOs(os);
                        break;
                    }
                    default:
                        cout << "�������� ����� ����." << endl;
                    }
                }
                else {
                    cout << "�������� ������ �������." << endl;
                }
            }
            else {
                cout << "� ������� ��� ��������." << endl;
            }
            break;
        }
        case 4: {
            if (phoneCount > 0) {
                cout << "���������� ��� ���� ��������:" << endl;
                for (int i = 0; i < phoneCount; i++) {
                    phones[i].Info();
                }
            }
            else {
                cout << "� ������� ��� ��������." << endl;
            }
            break;
        }
        case 5: {
            if (phoneCount > 0) {
                for (int i = 0; i < phoneCount - 1; i++) {
                    for (int j = 0; j < phoneCount - i - 1; j++) {
                        if (phones[j].getRam() > phones[j + 1].getRam()) {
                            swap(phones[j], phones[j + 1]);
                        }
                    }
                }
                cout << "������� ������������� �� RAM." << endl;
            }
            else {
                cout << "� ������� ��� ��������." << endl;
            }
            break;
        }
        case 6: {
            cout << "���������� ������ ���������." << endl;
            break;
        }
        default: {
            cout << "�������� �����. ���������� ��� ���." << endl;
            break;
        }
        }
    } while (choice != 6);
}