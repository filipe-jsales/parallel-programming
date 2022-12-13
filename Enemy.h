#ifndef ENEMY_H
#define ENEMY_H

#include "ostream"
#include <string>
#include <vector>
using std::ostream;
using std::string;
using std::vector;

#include <string>

using std::string;

class Enemy
{
    // friend ostream &operator<<(ostream &, const Enemy &);

public:
    Enemy();
    // Enemy(const string &, int = 10, int = 10, int = 3, bool = false);
    Enemy(const string &, int, bool);
    Enemy(const Enemy &);
    ~Enemy();

    void printStatus() const;
    bool isHurt() const;
    void say(const string &) const;
    void decreaseHP(int);
    void catchWeapon(const string &);
    void attack(Enemy &);
    void fightWith(Enemy &);
    void equipWeapon(int);
    void operator=(const Enemy &);
    bool operator==(const Enemy &) const;
    bool operator!=(const Enemy &) const;
    void operator!();
    void showWeapons() const;
    void showEquippedWeapon() const;
    void showType() const;

    string getName() const { return this->name; }
    int getHP() const;
    int getDefensePoints() const;
    int getMaxHP() const;
    string getEnemyType() const { return this->ENEMY_TYPE; }
    static int getNumEnemiesInArea() { return Enemy::numEnemies; }
    static const string *getBodyParts() { return Enemy::BODY_PARTS; }
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
    static const string ENEMY_TYPE;
    static int numEnemies;
    std::string name;
    std::string weapons[Enemy::INITIAL_NUM_WEAPONS];
    std::string *equippedWeaponPtr;
    int healthPoints;
    int defensePoints;
    int attackPoints;
    int weaponInventorySize = Enemy::INITIAL_NUM_WEAPONS;
    // bool isLeader;
};

#endif // ENEMY_H