#include "DwarfWarrior.h"
#include "Warrior.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <typeinfo>

int DwarfWarrior::numEnemies = 0;
const string DwarfWarrior::DWARF_TYPE = "Generic DwarfWarrior";
const string DwarfWarrior::BODY_PARTS[3] = {"Head", "Body", "Feet"};
using std::cout;
using std::ostream;
using std::string;
using std::vector;

DwarfWarrior::DwarfWarrior()
{

    this->setHP(10);
    this->setDefensePoints(10);
    this->setAttackPoints(3);
    this->equippedWeaponPtr = 0;
    srand(time(0));
    DwarfWarrior::numEnemies++;
}

DwarfWarrior::DwarfWarrior(const string &name, int healthPoints, bool leader)
{
    this->setHP(healthPoints);
    this->setDefensePoints(10);
    this->setAttackPoints(3);
    this->equippedWeaponPtr = 0;
    srand(time(0));
    DwarfWarrior::numEnemies++;
}

DwarfWarrior::DwarfWarrior(const string &name, int healthPoints, int defensePoints, int attackPoints, bool leader)
{
    this->setHP(healthPoints);
    this->setDefensePoints(defensePoints);
    this->setAttackPoints(attackPoints);
    this->equippedWeaponPtr = 0;
    srand(time(0));
    DwarfWarrior::numEnemies++;
}

DwarfWarrior::DwarfWarrior(const DwarfWarrior &otherDwarf)
{
    this->setHP(otherDwarf.healthPoints);
    this->setDefensePoints(otherDwarf.defensePoints);
    this->setAttackPoints(otherDwarf.attackPoints);
    this->equippedWeaponPtr = 0;
    srand(time(0));
    DwarfWarrior::numEnemies++;
}

DwarfWarrior::~DwarfWarrior()
{
    std::cout << "Destroying " << this->name << " from memory\n";
    delete this->equippedWeaponPtr;
    DwarfWarrior::numEnemies--;
}

void DwarfWarrior::catchWeapon(const string &weapon)
{
    // Verify which position is empty and store it there
    for (int i = 0; i < 5; i++)
    {
        if (this->weapons[i] == "")
        {
            this->weapons[i] = weapon;
            std::cout << this->name << " catches " << weapon << "!\n";
            return;
        }
    }
    std::cout << this->name << "'s pockets are full! He leaves " << weapon << "!\n";
}

void DwarfWarrior::equipWeapon(int weaponIndexOnInventory)
{
    if (weaponIndexOnInventory > this->weaponInventorySize)
    {
        this->equippedWeaponPtr = 0;
        return;
    }
    this->equippedWeaponPtr = &this->weapons[weaponIndexOnInventory];
}

void DwarfWarrior::attack(DwarfWarrior &otherDwarf)
{
    int randomNumber = rand() % 3;
    if (otherDwarf.healthPoints <= 0)
    {
        std::cout << otherDwarf.name << " is already dead.\n";
        return;
    }
    std::cout << this->name << " attacks " << otherDwarf.name << " in the " << otherDwarf.BODY_PARTS[randomNumber] << " by " << this->attackPoints << " HP!\n";
    otherDwarf.decreaseHP(this->attackPoints);
}

void DwarfWarrior::fightWith(DwarfWarrior &otherDwarf)
{
    while ((this->healthPoints > 0) && (otherDwarf.healthPoints > 0))
    {
        this->attack(otherDwarf); // This dwarf attacks another
        otherDwarf.attack(*this); // The other dwarf attacks this one
    }
    string winner = this->healthPoints > otherDwarf.healthPoints ? this->name : otherDwarf.name;
    std::cout << "The winner is " << winner << "!\n";
}

// Print all dwarf status
void DwarfWarrior::printStatus() const
{
    std::cout << "===============================\n";
    std::cout << "DwarfWarrior: " << this->name << "\n";
    std::cout << "Health Points: " << this->healthPoints << "\n";
    std::cout << "Defense Points: " << this->defensePoints << "\n";
    std::cout << "Attack Points: " << this->attackPoints << "\n";
    std::cout << "===============================\n";
}

void DwarfWarrior::say(const string &phrase) const
{
    std::cout << this->name << " says: " << phrase << "\n";
}

// When dwarf takes damage
void DwarfWarrior::decreaseHP(int damage)
{
    this->healthPoints -= damage;
}

// Is the dwarf hurt?
bool DwarfWarrior::isHurt() const
{
    return this->healthPoints < 5 ? true : false;
}

// The dwarf uses his strength to scare the player!
// If the dwarf's defense points are the 10th part of its maximum, he succeeds!

void DwarfWarrior::setHP(int healthPoints)
{
    if ((healthPoints < 0) && (healthPoints > MAX_HEALTH_POINTS))
    {
        std::cout << "HP invalid!\n";
        return;
    }
    this->healthPoints = healthPoints;
}

void DwarfWarrior::setDefensePoints(int defensePoints)
{
    if ((defensePoints < 0) && (defensePoints > this->MAX_DEFENSE_POINTS))
    {
        std::cout << "Defense points invalid!\n";
        return;
    }
    this->defensePoints = defensePoints;
}

void DwarfWarrior::setAttackPoints(int attackPoints)
{
    if (attackPoints < 0)
    {
        this->attackPoints = 1;
        return;
    }
    this->attackPoints = attackPoints;
}

int DwarfWarrior::getHP() const
{
    return this->healthPoints;
}

int DwarfWarrior::getAttackPoints() const
{
    return this->attackPoints;
}

int DwarfWarrior::getMaxDefensePoints() const
{
    return MAX_DEFENSE_POINTS;
}

int DwarfWarrior::getMaxHP() const
{

    return MAX_HEALTH_POINTS;
}

int DwarfWarrior::getDefensePoints() const
{
    return this->defensePoints;
}

bool DwarfWarrior::operator==(const DwarfWarrior &otherDwarf) const
{
    return this->name == otherDwarf.name;
}

bool DwarfWarrior::operator!=(const DwarfWarrior &otherDwarf) const
{
    // check the typeid of the object
    if (typeid(*this) != typeid(otherDwarf))
        return this->name != otherDwarf.name;
}

void DwarfWarrior::operator=(const DwarfWarrior &otherDwarf)
{
    if (typeid(*this) != typeid(otherDwarf))
        this->setHP(otherDwarf.healthPoints);
    this->setDefensePoints(otherDwarf.defensePoints);
    this->setAttackPoints(otherDwarf.attackPoints);
    this->equippedWeaponPtr = 0;
    return;
}

void DwarfWarrior::operator!()
{
    if (typeid(*this) == typeid(DwarfWarrior))
    {
        std::cout << this->name << " is dead!\n";
        this->healthPoints = 0;
    }
}

void DwarfWarrior::showWeapons() const
{
    if (typeid(*this) == typeid(DwarfWarrior))
    {
        std::cout << this->name << " has no weapons!\n";
        for (int i = 0; i < this->weaponInventorySize; i++)
        {
            std::cout << this->weapons[i] << "\n";
        }
        return;
    }
}


void DwarfWarrior::printInfo() const
{
    std::cout << "===============================\n";
    std::cout << "DwarfWarrior: " << this->name << "\n";
    std::cout << "Health Points: " << this->healthPoints << "\n";
    std::cout << "Defense Points: " << this->defensePoints << "\n";
    std::cout << "Attack Points: " << this->attackPoints << "\n";
    std::cout << "===============================\n";
}

ostream &operator<<(ostream &out, const DwarfWarrior &dwarf)
{
    out << "===============================\n";
    out << "DwarfWarrior: " << dwarf.name << "\n";
    out << "Health Points: " << dwarf.healthPoints << "\n";
    out << "Defense Points: " << dwarf.defensePoints << "\n";
    out << "Attack Points: " << dwarf.attackPoints << "\n";
    out << "===============================\n";
    return out;
}