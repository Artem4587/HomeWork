#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;
class Character {
public:
    Character(int strength, int agility, int intelligence)
    {
        this->strength = strength;
        this->agility = agility;
        this->intelligence = intelligence;
        this->abilities = nullptr;
        this->numAbilities = 0;
    }

    ~Character() {
        delete[] abilities; // Освобождаем динамический массив
    }

    void addAbility(const string& ability) {
        string* newAbilities = new string[numAbilities + 1];

        // Копируем старые способности в новый массив
        for (int i = 0; i < numAbilities; i++) {
            newAbilities[i] = abilities[i];
        }

        newAbilities[numAbilities] = ability; 
        delete[] abilities; // Освобождаем старый массив
        abilities = newAbilities;
        numAbilities++;
    }

    void displayRandomAbility() const {
        if (numAbilities > 0) {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> distrib(0, numAbilities - 1);

            int randomIndex = distrib(gen);
            cout << "Random ability: " << abilities[randomIndex] << endl;
        }
        else {
            cout << "No abilities available." << endl;
        }
    }

    int calculateDamage(const string& statUsed) const {
        int damage = 0;

        if (statUsed == "strength") {
            damage = strength * 2;
        }
        else if (statUsed == "agility") {
            damage = agility * 3;
        }
        else if (statUsed == "intelligence") {
            damage = intelligence * 4;
        }
        else {
            cout << "Invalid stat." << endl;
            return 0;
        }
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(1, 10); 

        damage += distrib(gen);

        return damage;
    }

private:
    int strength;
    int agility;
    int intelligence;
    string* abilities; 
    int numAbilities; 
};

int main() {
    Character hero(15, 10, 5);
    Character mage(5, 8, 17);
    Character rogue(8, 16, 6);

    hero.addAbility("Power Strike");
    hero.addAbility("Shield Bash");

    mage.addAbility("Fireball");
    mage.addAbility("Ice Bolt");
    mage.addAbility("Arcane Missile");

    rogue.addAbility("Sneak Attack");
    rogue.addAbility("Poisoned Dagger");

    cout << "Hero: ";
    hero.displayRandomAbility();

    cout << "Mage: ";
    mage.displayRandomAbility();

    cout << "Rogue: ";
    rogue.displayRandomAbility();

    cout << "Hero damage (strength): " << hero.calculateDamage("strength") << endl;
    cout << "Mage damage (intelligence): " << mage.calculateDamage("intelligence") << endl;
    cout << "Rogue damage (agility): " << rogue.calculateDamage("agility") << endl;
}