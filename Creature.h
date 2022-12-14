#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>
#include <time.h>
#include <cstdlib>
#include "Warrior.h"

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

class Creature : public Warrior
{
	friend std::ostream &operator<<(std::ostream &, const Creature &);

public:
	Creature();
	Creature(int , int , int , int , COLOR , string );
	Creature(const Creature &);
	~Creature();

	int getLimbs() const;
	int getHeight() const;
	int getWeight() const;
	int getHealth() const;
	COLOR getColor() const;
	string getName() const;
	bool tauntPlayer() const;
    bool isALeader() const;
    static void defineLeader(Creature &);
	void showType() const; 

	bool setLimbs(int );
	bool setHeight(int );
	bool setWeight(int );
	bool setHealth(int );
	bool setColor(COLOR );
	string setName(string );
	virtual void fightWith(Creature &);

	void operator=(const Creature &);
	bool operator==(const Creature &) const;
	bool operator!=(const Creature &) const;
	void operator!();

private:
	int appendages;
	int height;
	int weight;
	int health;
	COLOR skin;
	string identity;
	bool isLeader;
};
#endif // CREATURE_H