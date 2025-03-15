#include <iostream>
using namespace std;
// Àáñòðàêòíûé áàçîâûé êëàññ BaseEnemy
class BaseEnemy {
public:
    // ×èñòî âèðòóàëüíûå ìåòîäû 
    virtual void DoDamage() = 0; // Íàíîñèò óðîí
    virtual void Die() = 0;       // Óìèðàåò
    virtual void ChasePlayer() = 0; // Ïðåñëåäóåò èãðîêà

    // Âèðòóàëüíûé äåñòðóêòîð 
    virtual ~BaseEnemy() {}
};

// Ïðîèçâîäíûé êëàññ Goblin
class Goblin : public BaseEnemy {
public:
    void DoDamage() override {
        cout << "Ãîáëèí íàíîñèò óðîí!" << endl;
    }

    void Die() override {
        cout << "Ãîáëèí óìèðàåò ñ âîïëåì!" << endl;
    }

    void ChasePlayer() override {
        cout << "Ãîáëèí ïðåñëåäóåò èãðîêà, ñïîòûêàÿñü!" << endl;
    }
};

// Ïðîèçâîäíûé êëàññ Orc
class Orc : public BaseEnemy {
public:
    void DoDamage() override {
        cout << "Îðê áüåò äóáèíîé!" << endl;
    }
    void Die() override {
        cout << "Îðê ïàäàåò çàìåðòâî ñ ïðåäñìåðòíûì õðèïîì." << endl;
    }
    void ChasePlayer() override {
        cout << "Îðê áåæèò çà èãðîêîì, ñîòðÿñàÿ çåìëþ!" << endl;
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
