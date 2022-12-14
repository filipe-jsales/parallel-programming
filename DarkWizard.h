#ifndef DARKWIZARD_H
#define DARKWIZARD_H

#include "Wizard.h"
#include <string>
#include <vector>
using std::ostream;
using std::string;
using std::vector;

class DarkWizard : public Wizard
{
    friend ostream &operator<<(ostream &, const DarkWizard &);

public:
    DarkWizard();
    DarkWizard(const string &, const string &, const int, const int, const string &);
    DarkWizard(const DarkWizard &, const string &, const string &, const int, int, const string &);
    DarkWizard(const DarkWizard &);
    ~DarkWizard();

    string getTypeofRage() const;
    int getDarkMagic() const;
    void getRage(const string &);
    void setDarkMagic(int);
    void darkShieldSkill();
    void shadowCastSkill();

    virtual void setAttackStyle(const string &);
    virtual void setTypesOfRage(const string &);

    void getTypesOfRage() const;
    void getAttackStyle() const;
    void operator=(const DarkWizard &);
    bool operator==(const DarkWizard &) const;
    bool operator!=(const DarkWizard &) const;
    void operator!();
    void printInfo() const;
    bool verifySpell(const string &);

private:
    // vector of attack style
    vector<string> attackStyle;
    //vector of type of rage
    vector<string> typesofRage;
    string typeofRage;
    int magicLevel;
};

#endif // DARKWIZARD_H