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
    return appendages;
}
int Creature::getHeight() const
{
    return height;
}
int Creature::getWeight() const
{
    return weight;
}
int Creature::getHealth() const
{
    return health;
}
COLOR Creature::getColor() const
{
    return skin;
}
string Creature::getName() const
{
    return identity;
}

bool Creature::setLimbs(int limbs)
{
    bool validLimbs = (limbs > 0);
    if (validLimbs)
    {
        appendages = limbs;
    }
    return validLimbs;
}

bool Creature::setHeight(int ht)
{
    bool validHeight = (ht > 0);
    if (validHeight)
    {
        height = ht;
    }
    return validHeight;
}
bool Creature::setWeight(int wt)
{
    bool validWeight = (wt > 0);
    if (validWeight)
    {
        weight = wt;
    }
    return validWeight;
}
bool Creature::setHealth(int life)
{
    bool validHealth = (life > 0);
    if (validHealth)
    {
        health = life;
    }
    return validHealth;
}
bool Creature::setColor(COLOR hideColor)
{
    bool validColor = (hideColor >= 1) && (hideColor <= 10);
    if (validColor)
    {

        skin = hideColor;
    }
    return validColor;
}
string Creature::setName(string name)
{
    identity = name;
    return name;
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
        //typeid examples

        return true;
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

        //typeid examples

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

bool Creature::tauntPlayer() const
{

    //dynamic casting
    const Creature *creature = dynamic_cast<const Creature *>(this);
    if (creature)
    {
        cout << "The " << identity << "creature taunts you."
             << "\n";
        return creature->tauntPlayer();
    }
    return false;

}

//method to show typeid of object
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

