#ifndef WATERCREATURE_H
#define WATERCREATURE_H
#include <iostream>
#include "Creature.h"

#include <iostream>
#include <time.h>
#include <cstdlib>
#include "WaterCreature.h"

using std::string;
// enum is creating my own type simiular to how int is a type.
enum COLOR
{
	Red,
	Blue,
	Green,
	Orange,
	Yellow,
	Black,
	Teal,
	White,
	Gray,
	Perrywinkle,
	Pink
};

class WaterCreature : public Creature
{

public:
	WaterCreature();
	WaterCreature(int limbs, int ht, int wt, int life, COLOR hideColor, string name);
	WaterCreature(const WaterCreature &otherWaterCreature);

	int getLimbs() const;
	int getHeight() const;
	int getWeight() const;
	int getHealth() const;
	COLOR getColor() const;
	string getName() const;
	bool tauntPlayer() const;
    bool isALeader() const { return this->isLeader; }
    static void defineLeader(WaterCreature &);
    bool tauntPlayer() const;


	bool setLimbs(int limbs);
	bool setHeight(int ht);
	bool setWeight(int wt);
	bool setHealth(int life);
	bool setColor(COLOR hideColor);
	string setName(string name);
	virtual void fightWith(WaterCreature &);

	void operator=(const WaterCreature &);
	bool operator==(const WaterCreature &) const;
	bool operator!=(const WaterCreature &) const;
	void operator!();

	// I choose to use ints for the data fields because they are simplier than floats and easier to
	// keep track of.
private:
	int appendages;
	int height;
	int weight;
	int health;
	COLOR skin;
	string identity;
	bool isLeader;
};
#endif // WATERCREATURE_H