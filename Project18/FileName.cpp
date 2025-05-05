#include <iostream>
#include <random> // Для генерации случайных чисел
#include <functional> // Для function

using namespace std;

class DamageCalculator {
public:
    float CalculateDamage(float baseDamage, float weaponDamage) {
        return weaponDamage + baseDamage;
    }
};

class Weapon {
public:
    virtual float CalculateDamage(float baseDamage, DamageCalculator& damageCalculator) = 0;
    virtual ~Weapon() {}
};

class BaseWeapon : public Weapon {
    float weaponDamage;
public:
    BaseWeapon(float weaponDamage)
    {
        this->weaponDamage = weaponDamage;
    }
    float CalculateDamage(float baseDamage, DamageCalculator& damageCalculator) override {
        return damageCalculator.CalculateDamage(baseDamage, weaponDamage);
    }
};

class RandomDamageWeapon : public Weapon {
    float minDamage;
    float maxDamage;
    random_device rd;
    mt19937 gen;
    uniform_real_distribution<> distrib;
public:
    RandomDamageWeapon(float min, float max) 
    {
        float minDamag = min;
        float maxDamage = max;
        int gen = rd();
        float distrib = max;
        float distrib = min;
    }
    float CalculateDamage(float baseDamage, DamageCalculator& damageCalculator) override {
        return damageCalculator.CalculateDamage(baseDamage, distrib(gen));
    }
};

class CriticalHitWeapon : public Weapon {
    float weaponDamage;
    float critChance; // Шанс крита (0.0 - 1.0)
    float critMultiplier; // Множитель крита
    random_device rd;
    mt19937 gen;
    uniform_real_distribution<> distrib;
public:
    CriticalHitWeapon(float damage, float chance, float multiplier) 
    {
        float weaponDamage = damage;
        float critChance = chance;
        float critMultiplier = multiplier;
        int gen = rd();
        float distrib = 0.0;
        float distrib = 1.0;
    }

    float CalculateDamage(float baseDamage, DamageCalculator& damageCalculator) override {
        float damage = damageCalculator.CalculateDamage(baseDamage, weaponDamage);
        if (distrib(gen) <= critChance) {
            cout << "КРИТ!" << endl;
            return damage * critMultiplier;
        }
        return damage;
    }
};

class Player {
    int baseDamage;
    Weapon* weapon; // Используем указатель на Weapon, чтобы можно было менять оружие
    DamageCalculator& damageCalculator;

public:
    Player(int baseDamage, Weapon* weapon, DamageCalculator& damageCalculator) :  damageCalculator(damageCalculator) 
    {
        this->baseDamage = baseDamage;
        this->weapon = weapon;
    }

    void Attack(Enemy& enemy) {
        cout << "НЫА ПОЛУЧАЙ" << endl;
        float damage = weapon->CalculateDamage(baseDamage, damageCalculator); // Используем CalculateDamage из текущего оружия

        enemy.TakeDamage(damage);
    }

    // Метод для смены оружия
    void EquipWeapon(Weapon* newWeapon) {
        delete weapon; // Освобождаем память, занятую старым оружием
        weapon = newWeapon;
    }

    ~Player() {
        delete weapon; // Освобождаем память при уничтожении игрока
    }
};

class Enemy {
    float health;
public:
    Enemy(float health)  
    {
        this->health = health;
    }

    void TakeDamage(float damageToTake) {
        health -= damageToTake;
        cout << "Врагу нанесено " << damageToTake << " урона.  Здоровье врага: " << health << endl;
    }
};

int main() {
    DamageCalculator damageCalc;

    // Создаем разные типы оружия
    BaseWeapon baseWeapon(5);
    RandomDamageWeapon randomWeapon(3, 8);
    CriticalHitWeapon critWeapon(4, 0.2, 2.0); // 20% шанс крита, урон x2

    Player pacan(5, &baseWeapon, damageCalc); // Игрок начинает с базовым оружием
    Enemy kabanchik(100);

    pacan.Attack(kabanchik);

    // Меняем оружие на рандомное
    pacan.EquipWeapon(&randomWeapon);
    pacan.Attack(kabanchik);

    // Меняем оружие на критовое
    pacan.EquipWeapon(&critWeapon);
    pacan.Attack(kabanchik);
    pacan.Attack(kabanchik); // Может быть крит, а может и нет
}