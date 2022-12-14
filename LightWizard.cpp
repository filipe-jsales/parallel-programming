#include "LightWizard.h"
#include "Wizard.h"

#include <iostream>
#include <cmath>
#include <iostream>
#include <typeinfo>
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
    if (typeid(skills) != typeid(string))
    {
        cout << "Skill must be a string." << '\n';
        return;
    }
    this->skills = skills;
}
void LightWizard::setLightningSpeed(int lightningSpeed)
{
    if (typeid(lightningSpeed) != typeid(int))
    {
        cout << "Lightning speed must be an integer." << '\n';
        return;
    }
    this->lightningSpeed = lightningSpeed;
}
void LightWizard::setDirection(int direction)
{
    if (typeid(direction) != typeid(int))
    {
        cout << "Direction must be an integer." << '\n';
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

    if (typeid(lightWizard) == typeid(LightWizard))
    {
        out << "Light wizard skills: " << lightWizard.skills << '\n';
        out << "Lightning speed: " << lightWizard.lightningSpeed << '\n';
        out << "Direction: " << lightWizard.direction << '\n';
        return out;
    }
}

void LightWizard::operator=(const LightWizard &lightWizard)
{
    // return static_cast<Wizard>(*this) = static_cast<Wizard>(lightWizard);
    if (typeid(lightWizard) == typeid(LightWizard) && this == &lightWizard)
    {
        this->skills = lightWizard.skills;
        return;
    }
}
bool LightWizard::operator==(const LightWizard &lightWizard) const
{
    if (typeid(lightWizard) == typeid(LightWizard) && this == &lightWizard)
    {
        cout << "Light wizard skills are equal." << '\n';
        return true;
    }
    cout << "Light wizard skills are not equal." << '\n';
    return false;
}
bool LightWizard::operator!=(const LightWizard &lightWizard) const
{
    if (typeid(lightWizard) == typeid(LightWizard) && this == &lightWizard)
    {
        cout << "Light wizard skills are equal." << '\n';
        return true;
    }
    cout << "Light wizard skills are not equal." << '\n';
    return false;
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

//method using dynamic_cast
void LightWizard::showAttackStyle(const string &characterStyle)
{
    if (characterStyle == "Wizard")
    {
        LightWizard *lightWizard = dynamic_cast<LightWizard *>(this);
        if (lightWizard != nullptr)
        {
            cout << "Wizard attack style: " << lightWizard->attackStyle[0] << '\n';
        } 
    }
    else
    {
        cout << "Invalid attack style" << '\n';
    }
}

