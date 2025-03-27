#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class NumberCounter {
public:
    virtual int count(int number) = 0;
    virtual ~NumberCounter() {}
};
class DigitCounter : public NumberCounter {
public:
    int count(int number) override
    {
        string numStr = to_string(number);
        return numStr.length();
    }
};
class PrimeFactorCounter : public NumberCounter {
public:
    int count(int number) override
    {
        if (number <= 1) return 0;

        vector<int> primeFactors;
        int temp = number;

        for (int i = 2; i * i <= temp; i++)
        {
            while (temp % i == 0) {
                primeFactors.push_back(i);
                temp /= i;
            }
        }

        if (temp > 1)
        {
            primeFactors.push_back(temp);
        }

        sort(primeFactors.begin(), primeFactors.end());
        primeFactors.erase(unique(primeFactors.begin(), primeFactors.end()), primeFactors.end());

        return primeFactors.size();
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    int number;

    cout << "������� �����: ";
    cin >> number;

    DigitCounter digitCounter;
    PrimeFactorCounter primeFactorCounter;

    cout << "���������� ����: " << digitCounter.count(number) << endl;
    cout << "���������� ��������� ������� ����������: " << primeFactorCounter.count(number) << endl;
}











#include <iostream>  // ���������� ���������� ��� �����/������ (cout, cin)
#include <string>    // ���������� ���������� ��� ������ �� �������� (string, to_string)
#include <algorithm> // ���������� ���������� � ���������� ����������� (sort, unique)
#include <vector>    // ���������� ���������� ��� ������ � ������������� ��������� (vector)
using namespace std; // ���������� ������������ ���� std, ����� �� ������ std:: ����� ������ �������� (cout, string � �.�.)

// ����������� �����, ������������ ��������� ��� �������� ����-���� � �����
class NumberCounter {
public:
    // ����� ����������� �������. ������ �����, ����������� �� NumberCounter, ������ ����������� ��� �������.
    virtual int count(int number) = 0;
    // ����������� ����������. ��������� ��� ����������� �������� �������� ����������� ������� ����� ��������� �� ������� �����.
    virtual ~NumberCounter() {}
};

// �����, �������������� ���������� ���� � �����
class DigitCounter : public NumberCounter {
public:
    // �������������� ����� count �� �������� ������ NumberCounter
    int count(int number) override
    {
        // ����������� ����� � ������
        string numStr = to_string(number);
        // ���������� ����� ������, ��� ����� ���������� ���� � �����
        return numStr.length();
    }
};

// �����, �������������� ���������� ��������� ������� ���������� �����
class PrimeFactorCounter : public NumberCounter {
public:
    // �������������� ����� count �� �������� ������ NumberCounter
    int count(int number) override
    {
        // ���� ����� ������ ��� ����� 1, �� � ���� ��� ������� ����������.
        if (number <= 1) return 0;

        // ������ ��� �������� ������� ����������
        vector<int> primeFactors;
        // ��������� ���������� ��� �������� �����, ����� �� ������ ��������
        int temp = number;

        // ������� ������� ���������
        for (int i = 2; i * i <= temp; i++)
        {
            // ���� temp ������� �� i ��� �������, ��������� i � ������ ������� ���������� � ����� temp �� i.
            while (temp % i == 0) {
                primeFactors.push_back(i);
                temp /= i;
            }
        }

        // ���� ����� ����� temp > 1, �� ��� ���������� ������� ��������� (��������, ���� ����� ���� �������).
        if (temp > 1)
        {
            primeFactors.push_back(temp);
        }

        // ��������� ������ ������� ����������
        sort(primeFactors.begin(), primeFactors.end());
        // ������� ������������� ��������
        primeFactors.erase(unique(primeFactors.begin(), primeFactors.end()), primeFactors.end());

        // ���������� ���������� ��������� ������� ����������
        return primeFactors.size();
    }
};

int main() {
    setlocale(LC_ALL, "ru"); // ������������� ������ ��� ������ ������� ��������

    int number; // ���������� ��� �������� ���������� �����

    cout << "������� �����: "; // ������� ��������� �� �����
    cin >> number; // ��������� �����, ��������� �������������

    DigitCounter digitCounter; // ������� ������ ������ DigitCounter
    PrimeFactorCounter primeFactorCounter; // ������� ������ ������ PrimeFactorCounter

    cout << "���������� ����: " << digitCounter.count(number) << endl; // ������� ���������� ���� � �����
    cout << "���������� ��������� ������� ����������: " << primeFactorCounter.count(number) << endl; // ������� ���������� ��������� ������� ���������� �����
}


//����������� ������ � ��� ������ ���������� ��� �������� ������ � ����������� �������� ������� � C++.
// ��� ��������� ���������� ����� ��������� � ���������� �����������, ��� �������� ���������� � ��������� ����.


//to_string() � ��� ������� � C++, ������� ����������� ��������� �������� ���� ������ (����� �����, ����� � ��������� �������) � ������� ����

//count - ��� ����� ���������� � ��������� ���������� ���������(� ����������� �� ���������)