#include <iostream>
using namespace std;
// ����������� ������� ����� BaseEnemy
class BaseEnemy {
public:
    // ����� ����������� ������ 
    virtual void DoDamage() = 0; // ������� ����
    virtual void Die() = 0;       // �������
    virtual void ChasePlayer() = 0; // ���������� ������

    // ����������� ���������� 
    virtual ~BaseEnemy() {}
};

// ����������� ����� Goblin
class Goblin : public BaseEnemy {
public:
    void DoDamage() override {
        std::cout << "������ ������� ����!" << std::endl;
    }

    void Die() override {
        std::cout << "������ ������� � ������!" << std::endl;
    }

    void ChasePlayer() override {
        std::cout << "������ ���������� ������, ����������!" << std::endl;
    }
};

// ����������� ����� Orc
class Orc : public BaseEnemy {
public:
    void DoDamage() override {
        std::cout << "��� ���� �������!" << std::endl;
    }
    void Die() override {
        std::cout << "��� ������ �������� � ������������ ������." << std::endl;
    }
    void ChasePlayer() override {
        std::cout << "��� ����� �� �������, �������� �����!" << std::endl;
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