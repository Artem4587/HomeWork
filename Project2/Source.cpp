#include <iostream>
using namespace std;
class Pudge
{
public:
    int health;
    int armour;
    Pudge(int initialhealth, int initialarmour)
    {
        health = initialhealth;
        armour = initialarmour;
    }

    void Healing_potion(int healthIncrease, int armourIncrease)
    {
        health += healthIncrease;
        armour += armourIncrease;
    }
    int getHealth() const {
        return health;
    }

    int getArmour() const {
        return armour;
    }
    void setHealth(int newHealth)
    {
        health = newHealth;
    }

    void setArmour(int newArmour)
    {
        armour = newArmour;
    }
};
int main()
{
    setlocale(LC_ALL, "RU");
    Pudge pudge(500, 5);

    cout << "Initial Health: " << pudge.getHealth() << endl;
    cout << "Initial Armour: " << pudge.getArmour() << endl;

    pudge.Healing_potion(100, 2);

    cout << "Health after Healing_potion: " << pudge.getHealth() << endl;
    cout << "Armour after Healing_potion: " << pudge.getArmour() << endl;
}