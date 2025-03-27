#include <iostream>
#include <stdexcept>
#include <limits> // ��� numeric_limits
using namespace std;
double divide(double numerator, double denominator) {
    if (denominator == 0) {
        throw runtime_error("������� �� ���� �� �����������.");
    }
    return numerator / denominator;
}

int main() {
    double num1, num2;

    try {
        cout << "������� ���������: ";
        cin >> num1;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("�������� ���� ���������. ��, ������� �����.");
        }
        cout << "������� �����������: ";
        cin >> num2;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("�������� ���� �����������. ��, ������� �����.");
        }
        double result = divide(num1, num2);
        cout << "��������� ����������: " << result << endl;
    }
    catch (const runtime_error& error) {
        cerr << "������ ����������: " << error.what() << endl;
    }
    catch (const invalid_argument& error) {
        cerr << "������ � ������������ ���������: " << error.what() << endl;
    }
    catch (...) {
        cerr << "��������� ������" << endl;
    }
}