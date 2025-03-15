#include <iostream>
using namespace std;
// Абстрактный базовый класс BaseEnemy
class BaseEnemy {
public:
    // Чисто виртуальные методы 
    virtual void DoDamage() = 0; // Наносит урон
    virtual void Die() = 0;       // Умирает
    virtual void ChasePlayer() = 0; // Преследует игрока

    // Виртуальный деструктор 
    virtual ~BaseEnemy() {}
};

// Производный класс Goblin
class Goblin : public BaseEnemy {
public:
    void DoDamage() override {
        std::cout << "Гоблин наносит урон!" << std::endl;
    }

    void Die() override {
        std::cout << "Гоблин умирает с воплем!" << std::endl;
    }

    void ChasePlayer() override {
        std::cout << "Гоблин преследует игрока, спотыкаясь!" << std::endl;
    }
};

// Производный класс Orc
class Orc : public BaseEnemy {
public:
    void DoDamage() override {
        std::cout << "Орк бьет дубиной!" << std::endl;
    }
    void Die() override {
        std::cout << "Орк падает замертво с предсмертным хрипом." << std::endl;
    }
    void ChasePlayer() override {
        std::cout << "Орк бежит за игроком, сотрясая землю!" << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "Ru");
    BaseEnemy* goblin = new Goblin();
    goblin->DoDamage();    
    goblin->ChasePlayer(); 
    goblin->Die();       

    BaseEnemy* orc = new Orc();
    orc->DoDamage();     
    orc->ChasePlayer();  
    orc->Die();        

    delete goblin;
    delete orc;
}