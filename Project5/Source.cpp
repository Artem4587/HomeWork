#include <iostream>
#include <string>
using namespace std;
class BattleUnit {
private:
    int health;       // Здоровье единицы
    int damage;       // Наносимый урон
    string unitType; // Тип единицы (например, пехотинец, лучник)

    // Статические поля
    static int totalHealth; // Общее количество здоровья всех единиц
    static int totalDamage; // Общий наносимый урон всех единиц

public:
    // Конструктор по умолчанию
    BattleUnit()
    {
        health = 100;
        damage = 10;
        unitType = "Unknown";
        UpdateStaticFields(); 
    }

    // Конструктор с параметрами
    BattleUnit(int health, int damage, const string& unitType)
    {
        this->health = health;
        this->damage = damage;
        this->unitType = unitType;
        UpdateStaticFields(); // Обновляем статические поля при создании объекта
    }

    // Деструктор (важно уменьшить статические поля при удалении объекта)
    ~BattleUnit() {
        totalHealth -= health;
        totalDamage -= damage;
    }

    // Геттеры
    int getHealth() const { return health; }
    int getDamage() const { return damage; }
    string getUnitType() const { return unitType; }
    static int getTotalHealth() { return totalHealth; } // Статический геттер
    static int getTotalDamage() { return totalDamage; } // Статический геттер

    // Сеттеры 
    void setHealth(int newHealth) {
        totalHealth -= health; 
        health = newHealth;    
        totalHealth += health; 
    }

    void setDamage(int newDamage) {
        totalDamage -= damage; 
        damage = newDamage;    
        totalDamage += damage; 
    }

    // Метод для нанесения урона 
    void takeDamage(int damageTaken) {
        int oldHealth = health; 
        health -= damageTaken;
        if (health < 0) {
            health = 0; 
        }
        totalHealth -= (oldHealth - health); 
    }

    // Метод для увеличения урона
    void increaseDamage(int damageIncrease) {
        totalDamage -= damage; 
        damage += damageIncrease;
        totalDamage += damage; 
    }

private:
    void UpdateStaticFields() {
        totalHealth += health;
        totalDamage += damage;
    }
};

int BattleUnit::totalHealth = 0;
int BattleUnit::totalDamage = 0;

int main() {
    BattleUnit unit1(150, 20, "Пехотинец");
    BattleUnit unit2(80, 30, "Лучник");

    cout << "Unit 1: Health = " << unit1.getHealth() << ", Damage = " << unit1.getDamage() << ", Type = " << unit1.getUnitType() << endl;
    cout << "Unit 2: Health = " << unit2.getHealth() << ", Damage = " << unit2.getDamage() << ", Type = " << unit2.getUnitType() << std::endl;
    cout << "Total Health: " << BattleUnit::getTotalHealth() << endl;
    cout << "Total Damage: " << BattleUnit::getTotalDamage() << endl;

    // Изменяем здоровье и урон одной из единиц
    unit1.setHealth(200);
    unit2.increaseDamage(10);

    // Выводим обновленную информацию
    cout << "\nAfter updating Unit 1 health and Unit 2 damage:" << endl;
    cout << "Unit 1: Health = " << unit1.getHealth() << ", Damage = " << unit1.getDamage() << ", Type = " << unit1.getUnitType() << endl;
    cout << "Unit 2: Health = " << unit2.getHealth() << ", Damage = " << unit2.getDamage() << ", Type = " << unit2.getUnitType() << endl;
    cout << "Total Health: " << BattleUnit::getTotalHealth() << endl;
    cout << "Total Damage: " << BattleUnit::getTotalDamage() << endl;

    // Пример нанесения урона
    unit1.takeDamage(50);
    cout << "\nUnit 1 takes 50 damage:" << endl;
    cout << "Unit 1: Health = " << unit1.getHealth() << ", Damage = " << unit1.getDamage() << ", Type = " << unit1.getUnitType() << endl;
    cout << "Total Health: " << BattleUnit::getTotalHealth() << endl;
}