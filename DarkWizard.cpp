#include "DarkWizard.h"
#include "Wizard.h"

#include <iostream>
#include <cmath>
#include <iostream>

using std::cout;

DarkWizard::DarkWizard() : Wizard() {}

DarkWizard::DarkWizard(const string &name, const string &attackStyle, const int age, const int quantityPowers, const string &typeofRage) : Wizard(name, attackStyle, age, quantityPowers)
{
    this->typeofRage = typeofRage;
}

DarkWizard::DarkWizard(const DarkWizard &other, const string &name, const string &attackStyle, const int age, const int quantityPowers, const string &tipoTemperaemnto) : Wizard(name, attackStyle, age, quantityPowers)
{
    this->typeofRage = other.typeofRage;
}
DarkWizard::~DarkWizard()
{

    cout << "Dark Wizard destroyed" << '\n';
}

string DarkWizard::getTypeofRage() const
{
    return typeofRage;
}
int DarkWizard::getDarkMagic() const
{
    return magicLevel;
}

void DarkWizard::getRage(const string &typeofRage)
{
    this->typeofRage = typeofRage;
}
void DarkWizard::setDarkMagic(int magicLevel)
{
    if (magicLevel < 0)
    {
        magicLevel = 0;
        return;
    }
    this->magicLevel = magicLevel;
}
void DarkWizard::darkShieldSkill()
{
    if (ageValidator(getAge()))
    {
        cout << "Dark shield active" << '\n';
        evolve();
    }
}
void DarkWizard::shadowCastSkill()
{
    if (ageValidator(getAge()))
    {
        cout << "Shadow cast active" << '\n';
        evolve();
    }
    else
    {
        cout << "You are too young to use this skill" << '\n';
    }
}
ostream &operator<<(ostream &out, const DarkWizard &darkWizard)
{

    if (static_cast<Wizard>(darkWizard).getAge() < 18)
    {
        cout << "You are too young to use this skill" << '\n';
        return out;
    }
    out << static_cast<Wizard>(darkWizard);
    out << '\n';
    return out;
}

void DarkWizard::operator=(const DarkWizard &character)
{
    if (static_cast<Wizard>(*this) == static_cast<Wizard>(character))
    {
        cout << "Not possible to assign to the same character." << '\n';
        return;
    }
    static_cast<Wizard>(*this) = static_cast<Wizard>(character);
    this->typeofRage = character.typeofRage;
    cout << "Dark Wizard assigned" << '\n';
}

bool DarkWizard::operator==(const DarkWizard &character) const
{
    if (static_cast<Wizard>(*this) == static_cast<Wizard>(character))
    {
        cout << "Dark Wizard equal rage levels" << '\n';
        return false;
    }
    cout << "Dark Wizard not equal rage levels" << '\n';
    return true;
}
bool DarkWizard::operator!=(const DarkWizard &character) const
{
    if (static_cast<Wizard>(*this) == static_cast<Wizard>(character))
    {
        return false;
    }
    return true;
}

void DarkWizard::operator!()
{
    if (static_cast<Wizard>(*this).getAge() < 18)
    {
        cout << "You are too young to use this skill" << '\n';
        return;
    }
    if (static_cast<Wizard>(*this).getAge() >= 18)
    {
        cout << "Dark shield active" << '\n';
        evolve();
    }
    if (typeofRage == "Furia")
    {
        typeofRage = "Calm";
        cout << "Calm" << '\n';
    }
    else if (typeofRage == "Calm")
    {
        typeofRage = "Furia";
        cout << "Furia" << '\n';
    }
}
