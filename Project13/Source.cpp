#include <iostream> 
#include <string>   
#include <iomanip> //для форматированного вывода 

using namespace std;

class MobilePhone {
private:
    int ram;
    double displaySize;
    string model;
    string os;

public:

    // Конструктор по умолчанию
    MobilePhone()
    {
        int ram = 0;
        double displaySize = 0;
        string model = "NONE";
        string os = "NONE";
    }

    // Конструктор с параметрами
    MobilePhone(int ram, double displaySize, string model, string os)
    {
        this->ram = ram;
        this->displaySize = displaySize;
        this->model = model;
        this->os = os;
    };

    // Методы доступа (геттеры)
    int getRam() { return ram; }
    double getDisplaySize() { return displaySize; }
    string getModel() { return model; }
    string getOs() { return os; }

    // Методы установки (сеттеры)
    void setRam(int ram) { this->ram = ram; }
    void setDisplaySize(double displaySize) { this->displaySize = displaySize; }
    void setModel(string model) { this->model = model; }
    void setOs(string os) { this->os = os; }

    string calculateUsabilityRating() const { // Метод, вычисляющий рейтинг удобства использования
        if (ram < 2048 && displaySize < 5.0) {
            return "Низкая производительность";
        }
        else if (ram >= 4096 && displaySize >= 6.0) {
            return "Высокая производительность";
        }
        else { // Иначе
            return "Средняя производительность";
        }
    }

    // Метод для вывода информации об объекте
    void Info() const {
        cout << "Модель: " << model << endl;
        cout << "ОС: " << os << endl;
        cout << "RAM: " << ram << " MB" << endl;
        cout << "Размер экрана: " << fixed << setprecision(1) << displaySize << " дюймов" << endl;
        cout << "Производительность: " << calculateUsabilityRating() << endl;
        cout << "------------------------" << endl;
    }
};


void Menu() {
    cout << "\nМеню:" << endl;
    cout << "1. Добавить пустой объект" << endl;
    cout << "2. Добавить объект с данными" << endl;
    cout << "3. Редактировать объект" << endl;
    cout << "4. Вывести информацию обо всех объектах" << endl;
    cout << "5. Сортировать объекты по RAM" << endl;
    cout << "6. Выйти" << endl;
    cout << "Выберите действие: ";
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
            cin.clear(); // Очищаем флаг ошибки cin

            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода, чтобы убрать ошибочный ввод
        }

        switch (choice) {
        case 1: {
            if (phoneCount < MAX_PHONES) {
                phones[phoneCount] = MobilePhone();
                cout << "Объект добавлен." << endl;
            }
            else {
                cout << "Массив заполнен, невозможно добавить новый объект." << endl;
            }
            break;
        }
        case 2: {
            if (phoneCount < MAX_PHONES) {
                int ram;
                double displaySize;
                string model, os;

                cout << "Введите RAM (MB): ";
                cin >> ram;

                cout << "Введите размер экрана (дюймы): ";
                cin >> displaySize;

                cin.ignore();

                cout << "Введите модель: ";
                getline(cin, model);

                cout << "Введите ОС: ";
                getline(cin, os);

                phones[phoneCount] = MobilePhone(ram, displaySize, model, os);
                phoneCount++;
                cout << "Объект добавлен." << endl;
            }
            else {
                cout << "Массив заполнен, невозможно добавить новый объект." << endl;
            }
            break;
        }
        case 3: {
            if (phoneCount > 0) {
                int index;

                cout << "Введите индекс объекта для редактирования (0-" << phoneCount - 1 << "): ";
                cin >> index;

                if (index >= 0 && index < phoneCount) {
                    int fieldChoice;

                    cout << "Какое поле вы хотите изменить?" << endl;
                    cout << "1. RAM" << endl;
                    cout << "2. Размер экрана" << endl;
                    cout << "3. Модель" << endl;
                    cout << "4. ОС" << endl;
                    cout << "Выберите поле: ";
                    cin >> fieldChoice;

                    switch (fieldChoice) {
                    case 1: {
                        int ram;
                        cout << "Введите новое значение RAM: ";
                        cin >> ram;
                        phones[index].setRam(ram);
                        break;
                    }
                    case 2: {
                        double displaySize;
                        cout << "Введите новый размер экрана: ";
                        cin >> displaySize;
                        phones[index].setDisplaySize(displaySize);
                        break;
                    }
                    case 3: {
                        string model;
                        cin.ignore();
                        cout << "Введите новую модель: ";
                        getline(cin, model);
                        phones[index].setModel(model);
                        break;
                    }
                    case 4: {
                        string os;
                        cin.ignore();
                        cout << "Введите новую ОС: ";
                        getline(cin, os);
                        phones[index].setOs(os);
                        break;
                    }
                    default:
                        cout << "Неверный выбор поля." << endl;
                    }
                }
                else {
                    cout << "Неверный индекс объекта." << endl;
                }
            }
            else {
                cout << "В массиве нет объектов." << endl;
            }
            break;
        }
        case 4: {
            if (phoneCount > 0) {
                cout << "Информация обо всех объектах:" << endl;
                for (int i = 0; i < phoneCount; i++) {
                    phones[i].Info();
                }
            }
            else {
                cout << "В массиве нет объектов." << endl;
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
                cout << "Объекты отсортированы по RAM." << endl;
            }
            else {
                cout << "В массиве нет объектов." << endl;
            }
            break;
        }
        case 6: {
            cout << "Завершение работы программы." << endl;
            break;
        }
        default: {
            cout << "Неверный выбор. Попробуйте еще раз." << endl;
            break;
        }
        }
    } while (choice != 6);
}