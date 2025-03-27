#include <iostream>
#include <stdexcept>
#include <limits> // Для numeric_limits
using namespace std;
double divide(double numerator, double denominator) {
    if (denominator == 0) {
        throw runtime_error("Деление на ноль не допускается.");
    }
    return numerator / denominator;
}

int main() {
    double num1, num2;

    try {
        cout << "Введите числитель: ";
        cin >> num1;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Неверный ввод числителя. Пж, введите число.");
        }
        cout << "Введите знаменатель: ";
        cin >> num2;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Неверный ввод знаменателя. Пж, введите число.");
        }
        double result = divide(num1, num2);
        cout << "Результат разделения: " << result << endl;
    }
    catch (const runtime_error& error) {
        cerr << "Ошибка выполнения: " << error.what() << endl;
    }
    catch (const invalid_argument& error) {
        cerr << "Ошибка в недопустимом аргументе: " << error.what() << endl;
    }
    catch (...) {
        cerr << "Произошла ошибка" << endl;
    }
}