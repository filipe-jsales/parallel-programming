#ifndef WIZARD_H
#define WIZARD_H

#include "WarCraftCharacter.h"
#include <string>
#include <vector>
using std::ostream;
using std::string;
using std::vector;

struct Witcher
{
    string name;
    string typeofPower;
    double attackStrength;
    //vector attackStyle;

};
class Wizard : public WarCraftCharacter
{
    friend ostream &operator<<(ostream &, const Wizard &);

public:
    Wizard();
    Wizard(int);
    Wizard(const string &, const string &, const int, int);
    Wizard(const Wizard &, const string &, const string &, const int, int);
    ~Wizard();

    int getPowers() const;
    void setPowers(int);

    string getPowerName() const;
    static int getWizardPowers();
    void setWizards(int);
    int getWizards() const;

    void setPowerName(const string &);
    virtual void registerWizardsPower(const string &);
    virtual void registerWizards(int);
    void printInfo() const;

    virtual void setAttackStyle(const string &);
    void evolve();
    void showWitcherStatus(Witcher);
    void getWitcherPower(Witcher);
    void showAttackStyle(const string &);

    void wizardWarning();

    // bool operator!=(const Wizard &) const;
    // bool operator==(const Wizard &) const;
    // bool operator!() const;
    // void operator=(const Wizard &);

private:
    int powers;
    int powersRegistered;
    vector<string *> vectorPowers;
    int nextEntrieInWizards;
    void allocateWizards(int);

    vector<string> attackStyle;
    string powerName;
    static int quantityPowers;
    const float STRENGTH;
    int wizards;
    int *wizardPtr;
    int wizardSize;

    string magicDescription;
};

#endif // WIZARD_H