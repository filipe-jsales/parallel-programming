#include "DarkWizard.h"
#include "Wizard.h"

#include <iostream>
#include <cmath>
#include <iostream>
#include <typeinfo>

using std::cout;
using std::string;
using std::vector;

DarkWizard::DarkWizard() : Wizard() {
    this->typeofRage = "Darkness";
    this->magicLevel = 0;
    this->setDarkMagic(0);
    static_cast<Wizard *>(this)->setPowers(0);
    static_cast<Wizard *>(this)->setAttackStyle("Long Range");
    this->setAge(0);
    this->setName("Dark Wizard");
}

DarkWizard::DarkWizard(const string &name, const string &attackStyle, const int age, const int quantityPowers, const string &typeofRage) : Wizard(name, attackStyle, age, quantityPowers)
{
    this->typeofRage = typeofRage;
    this->magicLevel = 0;
}

DarkWizard::DarkWizard(const DarkWizard &other, const string &name, const string &attackStyle, const int age, const int quantityPowers, const string &tipoTemperaemnto) : Wizard(name, attackStyle, age, quantityPowers)
{
    this->typeofRage = other.typeofRage;
    this->magicLevel = other.magicLevel;
}
DarkWizard::DarkWizard(const DarkWizard &other) : Wizard(other)
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
ostream &operator<<(ostream &out, DarkWizard &darkWizard)
{
    if ( typeid(darkWizard) == typeid(DarkWizard) && darkWizard.getAge() < 0)
    {
        cout << "Age must be positive. Setting it to zero." << '\n';
        darkWizard.setAge(0);
    }
    

    return out;
}

void DarkWizard::operator=(const DarkWizard &character)
{
    if (typeid(character) == typeid(DarkWizard) && this == &character)
    {
        cout << "Dark Wizard assigned" << '\n';
        this->typeofRage = character.typeofRage;
        return;
    }
    cout << "Dark Wizard not assigned" << '\n';
}

bool DarkWizard::operator==(const DarkWizard &character) const
{
    if (typeid(character) == typeid(DarkWizard) && this->typeofRage == character.typeofRage)
    {
        cout << "Dark Wizard equal rage levels" << '\n';
        return true;
    }
    cout << "Dark Wizard not equal rage levels" << '\n';
    return true;
}
bool DarkWizard::operator!=(const DarkWizard &character) const
{
    if (typeid(character) == typeid(DarkWizard) && this->typeofRage != character.typeofRage)
    {
        cout << "Dark Wizard not equal rage levels" << '\n';
        return true;
    }
    return true;
}

void DarkWizard::operator!()
{

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

void DarkWizard::setAttackStyle(const string &attackStyle)
{
    //set attack style to vector
    if ( typeid(attackStyle) == typeid(string) && attackStyle == "Dark fire"|| attackStyle == "Blinding light" || attackStyle == "Shadow cast")
    {
        this->attackStyle.push_back(attackStyle);
    }
    else
    {
        cout << "Invalid attack style" << '\n';
    }
}

void DarkWizard::getAttackStyle() const
{
    //get attack style from vector
    for (int i = 0; i < attackStyle.size(); i++)
    {
        cout << attackStyle[i] << '\n';
    }
}

void DarkWizard::setTypesOfRage(const string &typeofRage)
{
    //set type of rage to vector
    if ( typeid(typeofRage) == typeid(string)  && typeofRage == "Low" || typeofRage == "Moderate" || typeofRage == "High")
    {
        this->typesofRage.push_back(typeofRage);
    }
    else
    {
        cout << "Invalid type of rage" << '\n';
    }
}

void DarkWizard::getTypesOfRage() const
{
    //get type of rage from vector
    for (int i = 0; i < typesofRage.size(); i++)
    {
        cout << typesofRage[i] << '\n';
    }
}

void DarkWizard::printInfo() const
{
    cout << "Name: " << getName() << '\n';
    cout << "Age: " << getAge() << '\n';
    cout << "Type of Rage: " << getTypeofRage() << '\n';
    cout << "Magic Level: " << getDarkMagic() << '\n';
    cout << "Powers: " << getPowers() << '\n';
}

//verify if the spell is valid using typeid
bool DarkWizard::verifySpell(const string &spell)
{
    if (typeid(spell) == typeid(string) && spell == "Dark fire" || spell == "Blinding light" || spell == "Shadow cast")
    {
        cout << "Spell valid" << '\n';
        return true;
    }
    cout << "Spell invalid" << '\n';
    return false;
}