#include "Elemental.h"
#include <iostream>

using std::cout;
using std::string;

Elemental::Elemental() : Creature()
{
    appendages = 4;
    height = 7;
    weight = 250;
    health = 300;
    this->isLeader = false;

    identity = "Storm Elemental ";
}

Elemental::Elemental(int limbs, int ht, int wt, int life, COLOR hideColor, string name)
{
    appendages = limbs;
    height = ht;
    weight = wt;
    health = life;
    skin = hideColor;
    // this->isLeader = leader;

    identity = name;
}
Elemental::Elemental(const Elemental &otherElemental)
{
    appendages = otherElemental.appendages;
    height = otherElemental.height;
    weight = otherElemental.weight;
    health = otherElemental.health;
    skin = otherElemental.skin;
    this->isLeader = otherElemental.isLeader;

    identity = otherElemental.identity;
}

Elemental::~Elemental()
{
    cout << "Elemental " << identity << " has been destroyed.";
}

int Elemental::getLimbs() const
{
    return appendages;
}
int Elemental::getHeight() const
{
    return height;
}
int Elemental::getWeight() const
{
    return weight;
}
int Elemental::getHealth() const
{
    return health;
}
COLOR Elemental::getColor() const
{
    return skin;
}
string Elemental::getName() const
{
    return identity;
}

bool Elemental::setLimbs(int limbs)
{
    bool validLimbs = (limbs > 0);
    if (validLimbs)
    {
        appendages = limbs;
    }
    return validLimbs;
}

bool Elemental::setHeight(int ht)
{
    bool validHeight = (ht > 0);
    if (validHeight)
    {
        height = ht;
    }
    return validHeight;
}
bool Elemental::setWeight(int wt)
{
    bool validWeight = (wt > 0);
    if (validWeight)
    {
        weight = wt;
    }
    return validWeight;
}
bool Elemental::setHealth(int life)
{
    bool validHealth = (life > 0);
    if (validHealth)
    {
        health = life;
    }
    return validHealth;
}
bool Elemental::setColor(COLOR hideColor)
{
    bool validColor = (hideColor >= 1) && (hideColor <= 10);
    if (validColor)
    {

        skin = hideColor;
    }
    return validColor;
}
string Elemental::setName(string name)
{
    identity = name;
    return name;
}

void Elemental::operator=(const Elemental &otherElemental)
{

    cout << "You have encountered a " << identity;
    appendages = otherElemental.appendages;
    height = otherElemental.height;
    weight = otherElemental.weight;
    health = otherElemental.health;
    skin = otherElemental.skin;
    this->isLeader = otherElemental.isLeader;
    identity = otherElemental.identity;
}
bool Elemental::operator==(const Elemental &otherElemental) const
{
    if (static_cast<const Creature &>(*this) == static_cast<const Creature &>(otherElemental))
    {
        return true;
    }
}

bool Elemental::operator!=(const Elemental &otherElemental) const
{
    if (static_cast<const Creature &>(*this) != static_cast<const Creature &>(otherElemental))
    {
        return true;
    }
    return !(*this == otherElemental);
}

void Elemental::operator!()
{
    cout << "You have killed the " << identity << "Elemental."
         << "\n";
    health = 0;
}

bool Elemental::tauntPlayer() const
{
    bool taunt = false;
    int tauntChance = rand() % 100 + 1;
    if (tauntChance <= 50)
    {
        cout << "The " << identity << "Elemental taunts you."
             << "\n";
        taunt = true;
    }
    cout << "The " << identity << "Elemental has " << health << " health left."
         << "\n";
    return taunt;
}

void Elemental::fightWith(Elemental &otherElemental)
{
    int damage = 0;
    int attackChance = rand() % 100 + 1;
    if (attackChance <= 50)
    {
        // Random damage between 1 and 100 the Elemental can do
        damage = rand() % 100 + 1;
        otherElemental.setHealth(otherElemental.getHealth() - damage);
        cout << "The " << identity << "Elemental attacks you for " << damage << " damage."
             << "\n";
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            if (otherElemental.tauntPlayer())
            {
                damage = rand() % 100 + 1;
                otherElemental.setHealth(otherElemental.getHealth() - damage);
                cout << "The " << identity << "Elemental attacks you for " << damage << " damage."
                     << "\n";
            }
        }
    }
}

void Elemental::defineLeader(Elemental &Elemental)
{
    Elemental.isLeader = true;
}

bool Elemental::tauntPlayer() const
{
    if (rand() % 2 == 0) // 50% chance
    {
        std::cout << "It works! The player feels weak!\n";
        return true;
    }
    std::cout << "It fails! The player feels awkward!\n";
    return false;
}

void Elemental::print() const
{
    cout << "Elemental " << identity << " has " << appendages << " limbs, is " << height << " feet tall, weighs " << weight << " pounds, has " << health << " health, and is " << skin << " colored."
         << "\n";
    cout << "Elemental " << identity << " is a " << (isLeader ? "leader" : "follower") << "."
         << "\n";
}
