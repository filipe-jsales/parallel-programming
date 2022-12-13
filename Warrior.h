#ifndef WARRIOR_H
#define WARRIOR_H

#include <string>
#include <vector>
#include "WarCraftCharacter.h"
using std::ostream;
using std::string;
using std::vector;
class Warrior : public WarCraftCharacter
{
    friend ostream &operator<<(ostream &, const Warrior &);

public:
    Warrior();
    Warrior(int);
    Warrior(const string &, const string &, const int, int);
    Warrior(const Warrior &, const string &, const string &, const int, int);
    ~Warrior();

    int getQuantityWeapons() const;
    int getAttackPoints() const;
    string getWeapon() const;
    static int getBackpackSize();
    void setWeaponsQuantity(int);
    void setDamagePoints(int);
    void setWeapon(const string &);
    void registerNewWeaponsWarrior(const string &);

    void registerNewAttacks(int);

    void verifyState();

    bool operator!=(const Warrior &) const;
    bool operator==(const Warrior &) const;
    bool operator!() const;
    void operator=(const Warrior &);

private:
    int weaponsRegistered;
    vector<string *> weapons;
    int quantityWeapons;
    int damagePoints;
    int ataquesSize;
    string weapon;
    static int backpack;
    int nextEntrieInAttack;
    void allocateAttack(int);
    int *attacksPointer;
};

#endif // WARRIOR_H