#include <iostream>
#include <string>
#include <random>
using namespace std;

class Tank
{
private:
    string name;
    int Life = 0;
    int damage = 0;
    bool isCheating = false;
    string* abilities;
    int abilitiesCount;
public:

    int GetLife() { return Life; }

    Tank(string nameValue, int LifeValue, int damageValue, bool isCheatingValue, string* abilitiesValue, int abilitiesCountValue)
    {
        name = nameValue;
        Life = LifeValue;
        damage = damageValue;
        isCheating = isCheatingValue;
        abilitiesCount = abilitiesCountValue;
        abilities = new string[abilitiesCount];
        
        for (int i = 0; i < abilitiesCount; ++i) 
        {
            abilities[i] = abilitiesValue[i];
        }
    }
    ~Tank() 
    {
        delete[] abilities;     
    }

    void ShowInfo()
    {
        cout << "\nНазвание: " << name
            << "\nЖизнь: " << Life
            << "\nУрон: " << damage
            << "\nЧитер ли: " << isCheating << endl;
    }

    void RandomAbility() {
        if (abilitiesCount == 0) {
            cout << "У танка нет способностей." ;
            return;
        }
        random_device rd;// Генерация случайного индекса(списал)
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(0, abilitiesCount - 1);
        int randomIndex = distrib(gen);

        cout << "Случайная способность: " << abilities[randomIndex] << endl;
    }

    int CalculateDamage(int statValue, string abilityName) {
        int DamageMultiplier = 1;

        for (int i = 0; i < abilitiesCount; ++i) {
            if (abilities[i] == abilityName) {
                DamageMultiplier = 2; // Для простоты, если способность найдена урон увеличивается в два раза
                break;
            }
        }

        return statValue * DamageMultiplier;
    }
};

int main()
{
    setlocale(LC_ALL, "Ru");

    string E5Arr[] = { "Точный выстрел", "Усиленная броня",  };
    int E5Count = sizeof(E5Arr) / sizeof(E5Arr[0]);

    Tank T110E5("T110E5", 2400, 400, true, E5Arr, E5Count);
    T110E5.ShowInfo();
    T110E5.RandomAbility();

    int stat = 100; 
    string ability = "Точный выстрел";
    int damage = T110E5.CalculateDamage(stat, ability);
    cout << "Увеличеный урон: " << damage << endl;

    string E3Arr[] = { "Защита", "Маскировка" };
    int E3Count = sizeof(E3Arr) / sizeof(E3Arr[0]);

    Tank T110E3("T110E3", 2000, 790, false, E3Arr, E3Count);
    T110E3.ShowInfo();
    T110E3.RandomAbility();

}