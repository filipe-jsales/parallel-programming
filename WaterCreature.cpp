#include "WaterCreature.h"
#include <iostream>

using std::cout;
using std::string;

WaterCreature::WaterCreature(): Creature()
{
    appendages = 4;
    height = 12;
    weight = 500;
    health = 230;
    this->isLeader = false;

    identity = "Orc-Clone ";
}


WaterCreature::WaterCreature(int limbs, int ht, int wt, int life, COLOR hideColor, string name)
{
    appendages = limbs;
    height = ht;
    weight = wt;
    health = life;
    skin = hideColor;

    identity = name;
}
WaterCreature::WaterCreature(const WaterCreature &otherWaterCreature)
{
    appendages = otherWaterCreature.appendages;
    weight = otherWaterCreature.weight;
    skin = otherWaterCreature.skin;
    this->isLeader = otherWaterCreature.isLeader;
    identity = otherWaterCreature.identity;
}

WaterCreature::~WaterCreature()
{
    cout << "WaterCreature " << identity << " has been destroyed.";
}

int WaterCreature::getLimbs() const
{
    return appendages;
}
int WaterCreature::getHeight() const
{
    return height;
}
int WaterCreature::getWeight() const
{
    return weight;
}
int WaterCreature::getHealth() const
{
    return health;
}
COLOR WaterCreature::getColor() const
{
    return skin;
}
string WaterCreature::getName() const
{
    return identity;
}

bool WaterCreature::setLimbs(int limbs)
{
    bool validLimbs = (limbs > 0);
    if (validLimbs)
    {
        appendages = limbs;
    }
    return validLimbs;
}

bool WaterCreature::setHeight(int ht)
{
    bool validHeight = (ht > 0);
    if (validHeight)
    {
        height = ht;
    }
    return validHeight;
}
bool WaterCreature::setWeight(int wt)
{
    bool validWeight = (wt > 0);
    if (validWeight)
    {
        weight = wt;
    }
    return validWeight;
}
bool WaterCreature::setHealth(int life)
{
    bool validHealth = (life > 0);
    if (validHealth)
    {
        health = life;
    }
    return validHealth;
}
bool WaterCreature::setColor(COLOR hideColor)
{
    bool validColor = (hideColor >= 1) && (hideColor <= 10);
    if (validColor)
    {

        skin = hideColor;
    }
    return validColor;
}
string WaterCreature::setName(string name)
{
    identity = name;
    return name;
}

void WaterCreature::operator=(const WaterCreature &otherWaterCreature)
{

    cout << "You have encountered a " << identity;
    appendages = otherWaterCreature.appendages;
    weight = otherWaterCreature.weight;
    skin = otherWaterCreature.skin;
    this->isLeader = otherWaterCreature.isLeader;
    identity = otherWaterCreature.identity;
}
bool WaterCreature::operator==(const WaterCreature &otherWaterCreature) const
{
    if (static_cast<const Creature &>(*this) == static_cast<const Creature &>(otherWaterCreature))
    {
        return true;
    }
}

bool WaterCreature::operator!=(const WaterCreature &otherWaterCreature) const
{
    if (static_cast<const Creature &>(*this) != static_cast<const Creature &>(otherWaterCreature))
    {
        return true;
    }
    return !(*this == otherWaterCreature);
}

void WaterCreature::operator!()
{
    cout << "You have killed the " << identity << "WaterCreature."
         << "\n";
    health = 0;
}

bool WaterCreature::tauntPlayer() const
{
    bool taunt = false;
    int tauntChance = rand() % 100 + 1;
    if (tauntChance <= 50)
    {
        cout << "The " << identity << "WaterCreature taunts you."
             << "\n";
        taunt = true;
    }
    cout << "The " << identity << "WaterCreature has " << health << " health left."
         << "\n";
    return taunt;
}

void WaterCreature::fightWith(WaterCreature &otherWaterCreature)
{
    int damage = 0;
    int attackChance = rand() % 100 + 1;
    if (attackChance <= 50)
    {
        //Random damage between 1 and 100 the WaterCreature can do
        damage = rand() % 100 + 1;
        otherWaterCreature.setHealth(otherWaterCreature.getHealth() - damage);
        cout << "The " << identity << "WaterCreature attacks you for " << damage << " damage."
             << "\n";
    }
    else
    {
        cout << "The " << identity << "WaterCreature misses you."
             << "\n";
    }
}

void WaterCreature::defineLeader(WaterCreature &WaterCreature)
{
    WaterCreature.isLeader = true;
}

bool WaterCreature::tauntPlayer() const
{
    if (rand() % 2 == 0) // 50% chance
    {
        std::cout << "It works! The player feels weak!\n";
        return true;
    }   
    std::cout << "It fails! The player feels awkward!\n";
    return false;
}
