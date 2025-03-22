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

    cout << "Введите число: ";
    cin >> number;

    DigitCounter digitCounter;
    PrimeFactorCounter primeFactorCounter;

    cout << "Количество цифр: " << digitCounter.count(number) << endl;
    cout << "Количество различных простых множителей: " << primeFactorCounter.count(number) << endl;
}