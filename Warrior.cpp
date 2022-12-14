#include "Warrior.h"
#include "WarCraftCharacter.h"
#include <typeinfo>
#include <iostream>
#include <cmath>
using std::cout;

int Warrior::backpack = 0;
int Warrior::getBackpackSize()
{
    return backpack;
}
Warrior::Warrior() : weaponsRegistered(0)
{
    nextEntrieInAttack = 0;
    ataquesSize = 0;
}
Warrior::Warrior(int quantityWeapons) : weaponsRegistered(0)
{
    this->quantityWeapons = quantityWeapons;
    nextEntrieInAttack = 0;
    ataquesSize = 0;
}

Warrior::Warrior(const string &name, const string &attackStyle, const int age, int quantityWeapons) : weaponsRegistered(0), WarCraftCharacter(name, attackStyle, age)
{
    nextEntrieInAttack = 0;
    ataquesSize = 0;
    damagePoints++;
    setDamagePoints(damagePoints);
    setWeaponsQuantity(quantityWeapons);

    cout << "Ready to fight" << '\n';
}
Warrior::Warrior(const Warrior &other, const string &name, const string &attackStyle, const int age, int quantityWeapons) : weaponsRegistered(0), WarCraftCharacter(name, attackStyle, age)
{
    quantityWeapons++;
    damagePoints++;

    setWeaponsQuantity(other.quantityWeapons);

    this->weapons.resize(other.weapons.size());
    for (auto i = 0; i < other.weapons.size(); i++)
        this->weapons[i] = other.weapons[i];

    this->nextEntrieInAttack = other.nextEntrieInAttack;
    this->attacksPointer = new int[this->ataquesSize];
    this->ataquesSize = other.ataquesSize;
    for (int i = 0; i < nextEntrieInAttack; i++)
        this->attacksPointer[i] = other.attacksPointer[i];
}

Warrior::~Warrior()
{
    quantityWeapons--;
    damagePoints--;
    delete[] attacksPointer;
    for (auto i = 0; i < weapons.size(); i++)
        delete this->weapons[i];
    this->weapons.clear();

    cout << "Warrior out" << '\n';
}

void Warrior::setWeaponsQuantity(int quantityWeapons)
{
    if (Warrior::backpack > 0)
        Warrior::backpack -= this->quantityWeapons;

    if (quantityWeapons <= 0)
    {
        quantityWeapons = 0;
        return;
    }

    this->quantityWeapons = quantityWeapons;
    Warrior::backpack += this->quantityWeapons;
}
void Warrior::setDamagePoints(int damagePoints)
{
    if (damagePoints < 0)
    {
        damagePoints = 0;
        return;
    }
    this->damagePoints = damagePoints;
    registerNewAttacks(damagePoints);
}
void Warrior::setWeapon(const string &weapon)
{
    this->weapon = weapon;
}
int Warrior::getQuantityWeapons() const
{
    return this->quantityWeapons;
}
int Warrior::getAttackPoints() const
{
    return damagePoints;
}

string Warrior::getWeapon() const
{
    return weapon;
}
void Warrior::registerNewWeaponsWarrior(const string &newWeapon)
{
    if (weaponsRegistered < quantityWeapons)
    {
        weapons.push_back(new string(newWeapon));
        weaponsRegistered++;
        return;
    }
    cout << "Could not store " << newWeapon << '.' << " Backpack is full.\n";

    return;
}

void Warrior::registerNewAttacks(int damagePoints)
{

    if (typeid(damagePoints) == typeid(int) && damagePoints < 0)
    {
        damagePoints = 0;
        return;
    }
    if (typeid(damagePoints) == typeid(int) && nextEntrieInAttack < ataquesSize)
    {
        attacksPointer[nextEntrieInAttack++] = damagePoints;
        return;
    }
    if (typeid(damagePoints) == typeid(int) && nextEntrieInAttack == ataquesSize || ataquesSize == 0 && nextEntrieInAttack < ataquesSize)
    {
        allocateAttack(damagePoints);
        return;
    }

    if (typeid(damagePoints) == typeid(int) && ataquesSize == 0 || nextEntrieInAttack == 0)
    {
        ataquesSize = 1;
        attacksPointer = new int[ataquesSize];
        attacksPointer[nextEntrieInAttack++] = damagePoints;
        return;
    }

    allocateAttack(damagePoints);
}

void Warrior::allocateAttack(int damagePoints)
{

    int *ataquesTemp = new int[ataquesSize];
    for (int i = 0; i < nextEntrieInAttack; i++)
        attacksPointer[i] = ataquesTemp[i];

    delete[] attacksPointer;

    // Raise the memory size by 50%
    ataquesSize += int(ceil(ataquesSize * 0.5));
    attacksPointer = new int[ataquesSize];
    for (int i = 0; i < nextEntrieInAttack; i++)
        attacksPointer[i] = ataquesTemp[i];
    attacksPointer[nextEntrieInAttack++] = (damagePoints);

    delete[] ataquesTemp;
}

void Warrior::verifyState()
{
    if (nextEntrieInAttack < 1)
    {
        cout << "Not enough weapons to fight" << '\n';
    }
    if (quantityWeapons < 10 && nextEntrieInAttack >= 1)
    {
        cout << "Few weapons to fight, we are gonna lose the war" << '\n';
    }
    if (ageValidator(getAge()))
        cout << "Able to fight for WarCraft" << '\n';
    else
        cout << "Not able to fight for WarCraft" << '\n';
    attackStyle(getCharacterStyle());
}

ostream &operator<<(ostream &out, const Warrior &warrior)
{
    out << "Weapons list: " << '\n';
    if (typeid(warrior) == typeid(Warrior))
    {

        for (int i = 0; i < warrior.weapons.size(); i++)
            out << warrior.weapons[i] << '\t' << *warrior.weapons[i] << '\n';

        out << '\n';
    }

    return out;
}

bool Warrior::operator!=(const Warrior &warrior) const
{
    if (typeid(warrior) == typeid(Warrior) && quantityWeapons == 0)
    {
        cout << "We are out of weapons  :(" << '\n';
        return false;
    }
    return true;
}
bool Warrior::operator==(const Warrior &quantityWeapons) const
{

    if (typeid(quantityWeapons) == typeid(Warrior) && this->quantityWeapons == quantityWeapons.quantityWeapons)
    {
        cout << "We have the same quantity of weapons" << '\n';
        return true;
    }
    return false;
}
bool Warrior::operator!() const
{
    if (!damagePoints > 0)
    {
        cout << "Warrior hurt" << '\n';
        return false;
    }

    return true;
}

void Warrior::operator=(const Warrior &other)
{
    setDamagePoints(other.damagePoints);
    setWeaponsQuantity(other.quantityWeapons);

    this->weapons.resize(other.weapons.size());
    this->weaponsRegistered = other.weaponsRegistered;
    for (auto i = 0; i < other.weapons.size(); i++)
        this->weapons[i] = other.weapons[i];

    this->nextEntrieInAttack = other.nextEntrieInAttack;
    this->attacksPointer = new int[this->ataquesSize];
    this->ataquesSize = other.ataquesSize;
    for (int i = 0; i < nextEntrieInAttack; i++)
        this->attacksPointer[i] = other.attacksPointer[i];
}

void Warrior::printInfo() const
{
    cout << "Warrior info: " << '\n';
    cout << "Name: " << getName() << '\n';
    cout << "Age: " << getAge() << '\n';
    cout << "Character style: " << getCharacterStyle() << '\n';
    cout << "Weapon: " << getWeapon() << '\n';
    cout << "Quantity of weapons: " << getQuantityWeapons() << '\n';
    cout << "Damage points: " << getAttackPoints() << '\n';
    cout << "Backpack: " << backpack << '\n';
    cout << "Weapons registered: " << weaponsRegistered << '\n';
    cout << "Next entrie in attack: " << nextEntrieInAttack << '\n';
    cout << "Attack size: " << ataquesSize << '\n';
    cout << "Attacks: " << '\n';
    for (int i = 0; i < nextEntrieInAttack; i++)
        cout << attacksPointer[i] << '\t';
    cout << '\n';
    cout << "Weapons: " << '\n';
    for (int i = 0; i < weapons.size(); i++)
        cout << weapons[i] << '\t' << *weapons[i] << '\n';
    cout << '\n';
}



