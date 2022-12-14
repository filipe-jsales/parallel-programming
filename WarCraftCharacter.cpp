

#include <iostream>
#include "WarCraftCharacter.h"
using std::cout;

WarCraftCharacter::WarCraftCharacter() : characterStyle("Poderes") {}

WarCraftCharacter::WarCraftCharacter(const string &name, const string &characterStyle, int age)
{
    this->name = name;
    this->characterStyle = characterStyle;
    this->age = age;
}

WarCraftCharacter::~WarCraftCharacter()
{
}

WarCraftCharacter::WarCraftCharacter(const WarCraftCharacter &another)
{
    this->name = another.name;
    this->age = another.age;
}
string WarCraftCharacter::getName() const
{
    return name;
}

int WarCraftCharacter::getAge() const
{
    return age;
}
string WarCraftCharacter::getCharacterStyle() const
{
    return characterStyle;
}

void WarCraftCharacter::setName(const string &name)
{
    this->name = name;
}
void WarCraftCharacter::setAge(int age)
{
    if (age < 0)
    {
        cout << "Invalid age, setting to zero" << '\n';
        age = 0;
        return;
    }
    cout << "Age set to " << age << '\n';
    this->age = age;
}
void WarCraftCharacter::setCharacterStyle(const string &characterStyle)
{
    this->characterStyle = characterStyle;
}
bool WarCraftCharacter::ageValidator(int age)
{
    if (age >= 18)
    {
        cout << "Able to play World of Warcraft" << '\n';
        return true;
    }
    cout << "Unable to play World of Warcraft" << '\n';
    return false;
}
void WarCraftCharacter::attackStyle(const string &AttackStyle)
{
    if (AttackStyle == characterStyle)
    {
        cout << "It is a short range warrior" << '\n';
    }
    cout << "It is a long range warrior" << '\n';
}

void WarCraftCharacter::printInfo()
{
    cout << "Character name " << '\n';
    cout << name << '\n';
    cout << "Character age: " << '\n';
    cout << age << '\n';
    cout << "Attack Style: " << '\n';
    cout << characterStyle << '\n';
    if (age < 18)
    {
        cout << "The character is underage. " << '\n';
    }
    if (characterStyle == "")
    {
        cout << "No character attack style registered yet." << '\n';
    }
    if (characterStyle == "Poderes")
    {
        cout << "It is a short range warrior" << '\n';
    }
    else
    {
        cout << "It is a long range warrior" << '\n';
    }
}

// ostream &operator<<(ostream &out, const WarCraftCharacter &character)
// {
//     out << "Character name " << '\n';
//     out << character.name << '\n';
//     out << "Character age: " << '\n';
//     out << character.age << '\n';
//     out << "Attack Style: " << '\n';
//     out << character.characterStyle << '\n';
//     return out;
// }

// void WarCraftCharacter::operator=(const WarCraftCharacter &character)
// {
//     this->name = character.name;
//     this->age = character.age;
// }
// bool WarCraftCharacter::operator==(const WarCraftCharacter &character) const
// {
//     if (age < 18)
//     {
//         cout << "The character is underage " << '\n';
//         return true;
//     }
//     return false;
// }
// bool WarCraftCharacter::operator!=(const WarCraftCharacter &character) const
// {
//     return !(*this == character);
// }

// void WarCraftCharacter::operator!()
// {
//     if (characterStyle == "")
//     {
//         cout << "Needs to set a character attack style" << '\n';
//     }
// }
