#ifndef DWARFWARRIOR_H
#define DWARFWARRIOR_H
#include "Warrior.h"
#include "ostream"
#include <string>
#include <vector>
using std::ostream;
using std::string;
using std::vector;

#include <string>

using std::string;

class DwarfWarrior: public Warrior
{
    friend ostream &operator<<(ostream &, const DwarfWarrior &);

public:
    DwarfWarrior();
    DwarfWarrior(const string &, int = 10, int = 10, int = 3, bool = false);
    DwarfWarrior(const string &, int, bool);
    DwarfWarrior(const DwarfWarrior &);
    ~DwarfWarrior();

    void printStatus() const;
    bool isHurt() const;
    void say(const string &) const;
    void decreaseHP(int);
    void catchWeapon(const string &);
    void attack(DwarfWarrior &);
    void fightWith(DwarfWarrior &);
    void equipWeapon(int);
    void operator=(const DwarfWarrior &);
    bool operator==(const DwarfWarrior &) const;
    bool operator!=(const DwarfWarrior &) const;
    void operator!();
    void showWeapons() const;
    void printInfo() const;

    string getName() const { return this->name; }
    int getHP() const;
    int getDefensePoints() const;
    int getMaxHP() const;
    string getDwarfType() const { return this->DWARF_TYPE; }
    static int getNumEnemiesInArea() { return DwarfWarrior::numEnemies; }
    static const string *getBodyParts() { return DwarfWarrior::BODY_PARTS; }
    const string *getWeapons() const { return this->weapons; }
    const string *getEquippedWeapon() const { return this->equippedWeaponPtr; }
    int getMaxDefensePoints() const;
    int getAttackPoints() const;
    int getWeaponInventorySize() const { return this->weaponInventorySize; }
    void setHP(int);
    void setDefensePoints(int);
    void setAttackPoints(int);

private:
    const int MAX_HEALTH_POINTS = 150;
    const int MAX_DEFENSE_POINTS = 200;
    static const int INITIAL_NUM_WEAPONS = 3;
    static const string BODY_PARTS[3];
    static const string DWARF_TYPE;
    static int numEnemies;
    std::string name;
    std::string weapons[DwarfWarrior::INITIAL_NUM_WEAPONS];
    std::string *equippedWeaponPtr;
    int healthPoints;
    int defensePoints;
    int attackPoints;
    int weaponInventorySize = DwarfWarrior::INITIAL_NUM_WEAPONS;
    // bool isLeader;
};

#endif // DWARFWARRIOR_H