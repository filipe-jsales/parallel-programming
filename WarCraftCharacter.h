#ifndef WARCRAFTCHARACTER_H
#define WARCRAFTCHARACTER_H

#include "ostream"
#include <string>
#include <vector>
using std::ostream;
using std::string;
using std::vector;
class WarCraftCharacter
{
    // friend ostream &operator<<(ostream &, const WarCraftCharacter &);

public:
    WarCraftCharacter();
    WarCraftCharacter(const string &, const string &, int);
    WarCraftCharacter(const WarCraftCharacter &);
    ~WarCraftCharacter();
    string getName() const;

    int getAge() const;
    string getCharacterStyle() const;
    void setName(const string &);
    void setAge(int);
    void setCharacterStyle(const string &);
    virtual bool ageValidator(int);
    virtual void attackStyle(const string &);
    void printInfo();


private:
    string name;
    string characterStyle;
    int age;
};

#endif // WARCRAFTCHARACTER_H