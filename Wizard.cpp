#include "Wizard.h"
#include "WarCraftCharacter.h"

#include <cmath>
#include <iostream>
using std::cout;
//abstrata
int Wizard::quantityPowers = 0;
int Wizard::getWizardPowers()
{
    return quantityPowers;
}
Wizard::Wizard() : powersRegistered(0), STRENGTH(50.0), WarCraftCharacter()
{
    nextEntrieInWizards = 0;
    wizardSize = 0;
    wizards++;
}
Wizard ::Wizard(int powers) : powersRegistered(0), STRENGTH(50.0)
{
    this->powers = powers;
    nextEntrieInWizards = 0;
    wizardSize = 0;
    wizards++;
}

Wizard::Wizard(const string &name, const string &characterStyle, const int age, int powers) : powersRegistered(0), STRENGTH(50.0), WarCraftCharacter(name, characterStyle, age)
{

    setPowers(powers);
    nextEntrieInWizards = 0;
    wizardSize = 0;
    wizards++;
    setWizards(wizards);

}
Wizard::Wizard(const Wizard &other, const string &name, const string &characterStyle, const int age, int powers) : powersRegistered(0), STRENGTH(50.0), WarCraftCharacter(name, characterStyle, age)
{
    powers++;
    wizards++;

    setPowers(other.powers);

    this->vectorPowers.resize(other.vectorPowers.size());
    for (auto i = 0; i < other.vectorPowers.size(); i++)
        this->vectorPowers[i] = other.vectorPowers[i];

    this->wizardSize = other.wizardSize;
    this->nextEntrieInWizards = other.nextEntrieInWizards;
    this->wizardPtr = new int[this->wizardSize];
    for (int i = 0; i < nextEntrieInWizards; i++)
        this->wizardPtr[i] = other.wizardPtr[i];
}
Wizard::~Wizard()
{
    powers--;
    wizards--;

    delete[] wizardPtr;
    for (auto i = 0; i < vectorPowers.size(); i++)
        delete this->vectorPowers[i];
    this->vectorPowers.clear();

}
int Wizard::getPowers() const
{
    return powers;
}
int Wizard::getWizards() const
{
    return wizards;
}

string Wizard::getPowerName() const
{
    return magicDescription;
}
void Wizard::setPowers(int powers)
{
    if (Wizard::quantityPowers > 0)
        Wizard::quantityPowers -= this->powers;

    if (powers <= 0)
    {
        powers = 0;
        return;
    }

    this->powers = powers;
    Wizard::quantityPowers += this->powers;
}
void Wizard::setWizards(int wizards)
{
    if (wizards < 0)
    {
        wizards = 0;
        return;
    }
    this->wizards = wizards;
    registerWizards(wizards);
}

void Wizard::setPowerName(const string &magicDescription)
{
    this->magicDescription = magicDescription;
}
void Wizard::registerWizardsPower(const string &novoPoder)
{

    powersRegistered++;
    vectorPowers.push_back(new string(novoPoder));
    return;
}
void Wizard::registerWizards(int wizards)
{
    cout << "Wizards actual: " << wizards << '\n';
    if (nextEntrieInWizards < wizardSize)
    {
        wizardPtr[nextEntrieInWizards++] = wizards;
        return;
    }

    if (wizardSize == 0)
    {
        wizardSize = 1;
        wizardPtr = new int[wizardSize];
        wizardPtr[nextEntrieInWizards++] = wizards;
        return;
    }

    allocateWizards(wizards);
}

void Wizard::allocateWizards(int newWizard)
{

    int *wizardsTempVariable = new int[wizardSize];
    for (int i = 0; i < nextEntrieInWizards; i++)
        wizardsTempVariable[i] = wizardPtr[i];

    delete[] wizardPtr;

    // Raise the size of the array by 50%
    wizardSize += int(ceil(wizardSize * 0.5));
    wizardPtr = new int[wizardSize];
    for (int i = 0; i < nextEntrieInWizards; i++)
        wizardPtr[i] = wizardsTempVariable[i];
    wizardPtr[nextEntrieInWizards++] = (newWizard);

    delete[] wizardsTempVariable;
}

void Wizard::evolve()
{
    if (nextEntrieInWizards >= 1)
    {
        if (powers != 0)
        {
            cout<< "Evolved to a new power level." << '\n';
        }
    }
}

void Wizard::showWitcherStatus(Witcher witcher)
{
    cout << "Name: " << witcher.name << '\n';
    cout << "Power Description: " << witcher.typeofPower << '\n';
    cout << "Attack Level: " << witcher.attackStrength << '\n';
}
void Wizard::getWitcherPower(Witcher witcher)
{
    if (witcher.attackStrength >= STRENGTH)
    {
        cout << "You have a new power!" << '\n';
        showWitcherStatus(witcher);
    }
}

void Wizard::wizardWarning()
{
    if (powersRegistered > 0)
    {
        cout << "You have registered " << powersRegistered << " powers." << '\n';
    }
    else
    {
        cout << "You have not registered any powers." << '\n';
    }
    // attackStyle(getCharacterStyle());
}

void Wizard::printInfo() const
{
    cout << "Name: " << getName() << '\n';
    cout << "Character Style: " << getCharacterStyle() << '\n';
    cout << "Age: " << getAge() << '\n';
    cout << "Powers: " << getPowers() << '\n';
    cout << "Wizards: " << getWizards() << '\n';

    cout << "vectorPowers list: " << '\n';
    for (int i = 0; i < vectorPowers.size(); i++)
        cout << vectorPowers[i] << '\t' << *vectorPowers[i] << '\n';

    cout << "\nWizards: " << '\n';
    for (int i = 0; i < nextEntrieInWizards; i++)
        cout << wizardPtr[i] << "\n";
}

void Wizard::setAttackStyle(const string &attackStyle)
{

    //set attack style to vector
    if (attackStyle == "Long Range" || attackStyle == "Short Range")
    {
        this->attackStyle.push_back(attackStyle);
    }
    else
    {
        cout << "Invalid attack style" << '\n';
    }
}

