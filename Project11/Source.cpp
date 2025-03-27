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











#include <iostream>  // Подключает библиотеку для ввода/вывода (cout, cin)
#include <string>    // Подключает библиотеку для работы со строками (string, to_string)
#include <algorithm> // Подключает библиотеку с различными алгоритмами (sort, unique)
#include <vector>    // Подключает библиотеку для работы с динамическими массивами (vector)
using namespace std; // Использует пространство имен std, чтобы не писать std:: перед каждым объектом (cout, string и т.д.)

// Абстрактный класс, определяющий интерфейс для подсчета чего-либо в числе
class NumberCounter {
public:
    // Чисто виртуальная функция. Каждый класс, наследующий от NumberCounter, должен реализовать эту функцию.
    virtual int count(int number) = 0;
    // Виртуальный деструктор. Необходим для корректного удаления объектов производных классов через указатель на базовый класс.
    virtual ~NumberCounter() {}
};

// Класс, подсчитывающий количество цифр в числе
class DigitCounter : public NumberCounter {
public:
    // Переопределяет метод count из базового класса NumberCounter
    int count(int number) override
    {
        // Преобразует число в строку
        string numStr = to_string(number);
        // Возвращает длину строки, что равно количеству цифр в числе
        return numStr.length();
    }
};

// Класс, подсчитывающий количество различных простых множителей числа
class PrimeFactorCounter : public NumberCounter {
public:
    // Переопределяет метод count из базового класса NumberCounter
    int count(int number) override
    {
        // Если число меньше или равно 1, то у него нет простых множителей.
        if (number <= 1) return 0;

        // Вектор для хранения простых множителей
        vector<int> primeFactors;
        // Временная переменная для хранения числа, чтобы не менять исходное
        int temp = number;

        // Находим простые множители
        for (int i = 2; i * i <= temp; i++)
        {
            // Пока temp делится на i без остатка, добавляем i в список простых множителей и делим temp на i.
            while (temp % i == 0) {
                primeFactors.push_back(i);
                temp /= i;
            }
        }

        // Если после цикла temp > 1, то это оставшийся простой множитель (например, если число было простым).
        if (temp > 1)
        {
            primeFactors.push_back(temp);
        }

        // Сортируем вектор простых множителей
        sort(primeFactors.begin(), primeFactors.end());
        // Удаляем повторяющиеся элементы
        primeFactors.erase(unique(primeFactors.begin(), primeFactors.end()), primeFactors.end());

        // Возвращаем количество различных простых множителей
        return primeFactors.size();
    }
};

int main() {
    setlocale(LC_ALL, "ru"); // Устанавливает локаль для вывода русских символов

    int number; // Переменная для хранения введенного числа

    cout << "Введите число: "; // Выводит сообщение на экран
    cin >> number; // Считывает число, введенное пользователем

    DigitCounter digitCounter; // Создает объект класса DigitCounter
    PrimeFactorCounter primeFactorCounter; // Создает объект класса PrimeFactorCounter

    cout << "Количество цифр: " << digitCounter.count(number) << endl; // Выводит количество цифр в числе
    cout << "Количество различных простых множителей: " << primeFactorCounter.count(number) << endl; // Выводит количество различных простых множителей числа
}


//абстрактные классы — это мощный инструмент для создания гибких и расширяемых иерархий классов в C++.
// Они позволяют определить общий интерфейс и обеспечить полиморфизм, что упрощает разработку и поддержку кода.


//to_string() – это функция в C++, которая преобразует различные числовые типы данных (целые числа, числа с плавающей запятой) в объекты типа

//count - это метод работающий с подсчетом количества элементов(в зависимости от контекста)