#include "Creature.h"
#include "Warrior.h"
#include <iostream>
#include <typeinfo>

using std::cout;
using std::string;

Creature::Creature() : identity("Creature"), isLeader(false), Warrior()
{
    appendages = 4;
    height = 7;
    weight = 250;
    health = 300;
    skin = Gray;
    this->isLeader = false;
}

Creature::Creature(int limbs, int ht, int wt, int life, COLOR hideColor, string name) : identity(name), isLeader(false), Warrior()
{
    appendages = limbs;
    height = ht;
    weight = wt;
    health = life;
    skin = hideColor;

    identity = name;
}
Creature::Creature(const Creature &otherCreature)
{
    appendages = otherCreature.appendages;
    height = otherCreature.height;
    weight = otherCreature.weight;
    health = otherCreature.health;
    skin = otherCreature.skin;
    this->isLeader = otherCreature.isLeader;

    identity = otherCreature.identity;
}

Creature::~Creature()
{
    cout << "Creature " << identity << " has been destroyed.";
}

int Creature::getLimbs() const
{
    if (typeid(*this) == typeid(Warrior))
    {
        return appendages;
    }
}
int Creature::getHeight() const
{
    if (typeid(*this) == typeid(Warrior))
    {
        return height;
    }
}
int Creature::getWeight() const
{
    if (typeid(*this) == typeid(Warrior))
    {
        return weight;
    }
}
int Creature::getHealth() const
{
    if (typeid(*this) == typeid(Warrior))
    {
        return health;
    }
}
COLOR Creature::getColor() const
{
    if (typeid(*this) == typeid(Warrior))
    {
        return skin;
    }
}
string Creature::getName() const
{
    if (typeid(*this) == typeid(Warrior))
    {
        return identity;
    }
}

bool Creature::setLimbs(int limbs)
{
    if (typeid(*this) == typeid(Warrior))
    {
        bool validLimbs = (limbs > 0);
        if (validLimbs)
        {
            appendages = limbs;
        }
        return validLimbs;
    }
}

bool Creature::setHeight(int ht)
{
    if (typeid(*this) == typeid(Warrior))
    {
        bool validHeight = (ht > 0);
        if (validHeight)
        {
            height = ht;
        }
        return validHeight;
    }
}
bool Creature::setWeight(int wt)
{
    if (typeid(*this) == typeid(Warrior))
    {
        bool validWeight = (wt > 0);
        if (validWeight)
        {
            weight = wt;
        }
        return validWeight;
    }
}
bool Creature::setHealth(int life)
{
    if (typeid(*this) == typeid(Warrior))
    {
        bool validHealth = (life > 0);
        if (validHealth)
        {
            health = life;
        }
        return validHealth;
    }
}
bool Creature::setColor(COLOR hideColor)
{
    if (typeid(*this) == typeid(Warrior))
    {
        bool validColor = (hideColor >= 1) && (hideColor <= 10);
        if (validColor)
        {

            skin = hideColor;
        }
        return validColor;
    }
}
string Creature::setName(string name)
{
    if (typeid(*this) == typeid(Warrior))
    {
        identity = name;
    }
}

void Creature::operator=(const Creature &otherCreature)
{

    cout << "You have encountered a " << identity;
    appendages = otherCreature.appendages;
    height = otherCreature.height;
    weight = otherCreature.weight;
    health = otherCreature.health;
    skin = otherCreature.skin;
    this->isLeader = otherCreature.isLeader;
    identity = otherCreature.identity;
}
bool Creature::operator==(const Creature &otherCreature) const
{
    if (static_cast<const Warrior &>(*this) == static_cast<const Warrior &>(otherCreature))
    {
        if (appendages == otherCreature.appendages && height == otherCreature.height && weight == otherCreature.weight && health == otherCreature.health && skin == otherCreature.skin && identity == otherCreature.identity)
        {
            cout << "The " << identity << "creature is the same as the other creature."
                 << "\n";
            return true;
        }
        else
        {
            cout << "The " << identity << "creature is not the same as the other creature."
                 << "\n";
            return false;
        }
    }
}

bool Creature::operator!=(const Creature &otherCreature) const
{
    if (static_cast<const Warrior &>(*this) != static_cast<const Warrior &>(otherCreature))
    {
        return true;
    }
    return !(*this == otherCreature);
}

void Creature::operator!()
{
    cout << "You have killed the " << identity << "creature."
         << "\n";
    health = 0;
    typeid(*this).name();
}

bool Creature::tauntPlayer() const
{
    bool taunt = false;
    int tauntChance = rand() % 100 + 1;
    if (tauntChance <= 50)
    {
        cout << "The " << identity << "creature taunts you."
             << "\n";
        taunt = true;
    }
    cout << "The " << identity << "creature has " << health << " health left."
         << "\n";
    return taunt;
}

void Creature::fightWith(Creature &otherCreature)
{
    int damage = 0;
    int attackChance = rand() % 100 + 1;
    if (attackChance <= 50)
    {
        // Random damage between 1 and 100 the creature can do
        damage = rand() % 100 + 1;
        otherCreature.setHealth(otherCreature.getHealth() - damage);
        cout << "The " << identity << "creature attacks you for " << damage << " damage."
             << "\n";

        // typeid examples
    }
    else
    {
        cout << "The " << identity << "creature misses you."
             << "\n";
    }
}

void Creature::defineLeader(Creature &creature)
{
    creature.isLeader = true;
}

// method to show typeid of object
void Creature::showType() const
{
    cout << "The " << identity << "creature is a " << typeid(*this).name() << "."
         << "\n";
    if (typeid(*this) == typeid(Warrior))
    {
        cout << "The " << identity << "creature is an Warrior."
             << "\n";
    }
    else if (typeid(*this) == typeid(Creature))
    {
        cout << "The " << identity << "creature is a Creature."
             << "\n";
    }
    else
    {
        cout << "The " << identity << "creature is not an Warrior or Creature."
             << "\n";
    }
}

ostream &operator<<(ostream &out, const Creature &creature)
{
    out << "The " << creature.identity << "creature has " << creature.health << " health left."
        << "\n";
    return out;
}

bool Creature::isALeader() const
{
    return isLeader;
}