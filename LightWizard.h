#ifndef LIGHT_WIZARD_H
#define LIGHT_WIZARD_H

#include "Wizard.h"
#include <string>
#include <vector>
using std::ostream;
using std::string;
using std::vector;

class LightWizard : public Wizard
{
    friend ostream &operator<<(ostream &, const LightWizard &);

public:
    LightWizard();
    LightWizard(const string &, const string &, const int, const int, const string &);
    LightWizard(const LightWizard &, const string &, const string &, const int, int, const string &);
    ~LightWizard();

    string getSkill() const;
    int getLightningSpeed() const;
    int getDirection() const;
    void setSkill(const string &);
    void setLightningSpeed(int);
    void setDirection(int);
    void flashBang();
    int lightningAttack();
    void operator=(const LightWizard &);
    bool operator==(const LightWizard &) const;
    bool operator!=(const LightWizard &) const;
    void operator!();

private:
    string skills;
    int lightningSpeed;
    int direction;
};

#endif // LIGHT_WIZARD_H