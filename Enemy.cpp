#include "Enemy.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <typeinfo>

int Enemy::numEnemies = 0;
const string Enemy::ENEMY_TYPE = "Generic Enemy";
const string Enemy::BODY_PARTS[3] = {"Head", "Body", "Feet"};
using std::ostream;
using std::string;
using std::vector;
using std::cout;

Enemy::Enemy()
{

    this->setHP(10);
    this->setDefensePoints(10);
    this->setAttackPoints(3);
    this->equippedWeaponPtr = 0;
    srand(time(0));
    Enemy::numEnemies++;
}

Enemy::Enemy( const string &name, int healthPoints, bool leader) {
    this->setHP(healthPoints);
    this->setDefensePoints(10);
    this->setAttackPoints(3);
    this->equippedWeaponPtr = 0;
    srand(time(0));
    Enemy::numEnemies++;    
}

// Enemy::Enemy(const string &name, int healthPoints, int defensePoints, int attackPoints, bool leader)
// {
//     this->setHP(healthPoints);
//     this->setDefensePoints(defensePoints);
//     this->setAttackPoints(attackPoints);
//     this->equippedWeaponPtr = 0;
//     srand(time(0));
//     Enemy::numEnemies++;
// }

Enemy::Enemy(const Enemy &otherEnemy)
{
    this->setHP(otherEnemy.healthPoints);
    this->setDefensePoints(otherEnemy.defensePoints);
    this->setAttackPoints(otherEnemy.attackPoints);
    this->equippedWeaponPtr = 0;
    srand(time(0));
    Enemy::numEnemies++;
}

Enemy::~Enemy()
{
    std::cout << "Destroying " << this->name << " from memory\n";
    delete this->equippedWeaponPtr;
    Enemy::numEnemies--;
}

void Enemy::catchWeapon(const string &weapon)
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

void Enemy::equipWeapon(int weaponIndexOnInventory)
{
    if (weaponIndexOnInventory > this->weaponInventorySize)
    {
        this->equippedWeaponPtr = 0;
        return;
    }
    this->equippedWeaponPtr = &this->weapons[weaponIndexOnInventory];
}

void Enemy::attack(Enemy &otherEnemy)
{
    int randomNumber = rand() % 3;
    if (otherEnemy.healthPoints <= 0)
    {
        std::cout << otherEnemy.name << " is already dead.\n";
        return;
    }
    std::cout << this->name << " attacks " << otherEnemy.name << " in the " << otherEnemy.BODY_PARTS[randomNumber] << " by " << this->attackPoints << " HP!\n";
    otherEnemy.decreaseHP(this->attackPoints);
}

void Enemy::fightWith(Enemy &otherEnemy)
{
    while ((this->healthPoints > 0) && (otherEnemy.healthPoints > 0))
    {
        this->attack(otherEnemy); // This enemy attacks another
        otherEnemy.attack(*this); // The other enemy attacks this one
    }
    string winner = this->healthPoints > otherEnemy.healthPoints ? this->name : otherEnemy.name;
    std::cout << "The winner is " << winner << "!\n";
}

// Print all enemy status
void Enemy::printStatus() const
{
    std::cout << "===============================\n";
    std::cout << "Enemy: " << this->name << "\n";
    std::cout << "Health Points: " << this->healthPoints << "\n";
    std::cout << "Defense Points: " << this->defensePoints << "\n";
    std::cout << "Attack Points: " << this->attackPoints << "\n";
    std::cout << "===============================\n";
}

void Enemy::say(const string &phrase) const
{
    std::cout << this->name << " says: " << phrase << "\n";
}



// When enemy takes damage
void Enemy::decreaseHP(int damage)
{
    this->healthPoints -= damage;
}

// Is the enemy hurt?
bool Enemy::isHurt() const
{
    return this->healthPoints < 5 ? true : false;
}

// The enemy uses his strength to scare the player!
// If the enemy's defense points are the 10th part of its maximum, he succeeds!



void Enemy::setHP(int healthPoints)
{
    if ((healthPoints < 0) && (healthPoints > MAX_HEALTH_POINTS))
    {
        std::cout << "HP invalid!\n";
        return;
    }
    this->healthPoints = healthPoints;
}

void Enemy::setDefensePoints(int defensePoints)
{
    if ((defensePoints < 0) && (defensePoints > this->MAX_DEFENSE_POINTS))
    {
        std::cout << "Defense points invalid!\n";
        return;
    }
    this->defensePoints = defensePoints;
}

void Enemy::setAttackPoints(int attackPoints)
{
    if (attackPoints < 0)
    {
        this->attackPoints = 1;
        return;
    }
    this->attackPoints = attackPoints;
}

int Enemy::getHP() const
{
    return this->healthPoints;
}

int Enemy::getAttackPoints() const
{
    return this->attackPoints;
}

int Enemy::getMaxDefensePoints() const
{
    return MAX_DEFENSE_POINTS;
}

int Enemy::getMaxHP() const
{
    return MAX_HEALTH_POINTS;
}

int Enemy::getDefensePoints() const
{
    return this->defensePoints;
}

bool Enemy::operator==(const Enemy &otherEnemy) const
{
    return this->name == otherEnemy.name;
}

bool Enemy::operator!=(const Enemy &otherEnemy) const
{
    return this->name != otherEnemy.name;
}

void Enemy::operator=(const Enemy &otherEnemy)
{
    this->setHP(otherEnemy.healthPoints);
    this->setDefensePoints(otherEnemy.defensePoints);
    this->setAttackPoints(otherEnemy.attackPoints);
    this->equippedWeaponPtr = 0;
}

void Enemy::operator!()
{
    std::cout << this->name << " is dead!\n";
    this->healthPoints = 0;
}

void Enemy::showWeapons() const
{
    std::cout << this->name << "'s weapons:\n";
    for (int i = 0; i < this->weaponInventorySize; i++)
    {
        std::cout << this->weapons[i] << "\n";
    }
}

//method to show typeid of object
void Enemy::showType() const
{
    std::cout << "Type of object: " << typeid(*this).name() << "\n";
}
