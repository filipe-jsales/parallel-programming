#include "LightWizard.h"
#include "Wizard.h"

#include <iostream>
#include <cmath>
#include <iostream>

using std::cout;

LightWizard::LightWizard() : Wizard() {}

LightWizard::LightWizard(const string &name, const string &attackStyle, const int idade, const int quantityPowers, const string &skills) : Wizard(name, attackStyle, idade, quantityPowers)
{
    this->skills = skills;
}

LightWizard::LightWizard(const LightWizard &other, const string &name, const string &attackStyle, const int idade, const int quantityPowers, const string &tipoTemperaemnto) : Wizard(name, attackStyle, idade, quantityPowers)
{
    this->skills = other.skills;
}
LightWizard::~LightWizard()
{
    cout << "Light wizard destroyed." << '\n';
}

string LightWizard::getSkill() const
{
    return skills;
}
int LightWizard::getLightningSpeed() const
{
    return lightningSpeed;
}
int LightWizard::getDirection() const
{
    return direction;
}
void LightWizard::setSkill(const string &skills)
{
    this->skills = skills;
}
void LightWizard::setLightningSpeed(int lightningSpeed)
{
    if (lightningSpeed < 0)
    {
        lightningSpeed = 0;
        return;
    }
    this->lightningSpeed = lightningSpeed;
}
void LightWizard::setDirection(int direction)
{
    if (direction < 0)
    {
        cout << "Direction must be positive. Setting it to zero." << '\n';
        direction = 0;
        return;
    }
    this->direction = direction;
}
void LightWizard::flashBang()
{
    if (ageValidator(getAge()))
    {
        cout << "Could not use flash bang" << '\n';
        evolve();
    }
}
int LightWizard::lightningAttack()
{
    if (ageValidator(getAge()))
    {
        cout << "Could not use lightning attack" << '\n';
        evolve();
    }
    return lightningSpeed * direction;
}
ostream &operator<<(ostream &out, const LightWizard &lightWizard)
{

    out << static_cast<Wizard>(lightWizard);
    out << "Skills: " << '\n';
    out << lightWizard.skills << '\n';

    out << '\n';
    return out;
}

void LightWizard::operator=(const LightWizard &lightWizard)
{
    return static_cast<Wizard>(*this) = static_cast<Wizard>(lightWizard);
    if (this != &lightWizard)
    {
        cout << "Light wizard skills assigned." << '\n';
        this->skills = lightWizard.skills;
    }
}
bool LightWizard::operator==(const LightWizard &lightWizard) const
{
    if (static_cast<Wizard>(*this) == static_cast<Wizard>(lightWizard))
    {
        cout << "The wizards are the same." << '\n';
        return true;
    }

    return false;
}
bool LightWizard::operator!=(const LightWizard &lightWizard) const
{
    if (static_cast<Wizard>(*this) != static_cast<Wizard>(lightWizard))
    {
        cout << "The wizards are different." << '\n';
        return true;
    }
    return !(*this == lightWizard);
}

void LightWizard::operator!()
{
    if (ageValidator(getAge()))
    {
        cout << "Could not use ! operator" << '\n';
        evolve();
    }
    else
    {
        cout << "Could use ! operator" << '\n';
    }
}