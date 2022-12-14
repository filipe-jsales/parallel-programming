#include "Wizard.h"
#include "Wizard.cpp"
#include "Warrior.h"
#include "Warrior.cpp"
#include "WarCraftCharacter.h"
#include "WarCraftCharacter.cpp"
#include "LightWizard.h"
#include "LightWizard.cpp"
#include "DarkWizard.h"
#include "DarkWizard.cpp"
#include "DwarfWarrior.cpp"
#include "DwarfWarrior.h"
// #include "Creature.h"
// #include "Creature.cpp"

#include <iostream>
#include <vector>
using std::cout;
using std::string;
using std::vector;

int main()
{

  Wizard wizard1;
  Wizard wizard2;
  Wizard wizard3;
  DarkWizard darkWizard;
  LightWizard lightWizard;
  Warrior warrior;
  DwarfWarrior dwarfWarrior;
  dwarfWarrior.setHP(10);
  dwarfWarrior.setDefensePoints(10);
  dwarfWarrior.setAttackPoints(3);
  
  dwarfWarrior.printInfo();

  string nome1 = "Rhonin";
  string nome2 = "Medith";
  string nome3 = "Jaina Proudmore";

  string poder1 = "Darkness";
  string poder2 = "Psycho";
  string poder3 = "Awareness";

  string arma1 = "Knife";
  string arma2 = "Sword";

  wizard1.setCharacterStyle("Long Range");
  wizard1.setAge(18);
  darkWizard.getRage("Darkness");
  lightWizard.setSkill("Blinding Light");
  darkWizard.setDarkMagic(100);
  darkWizard.shadowCastSkill();

  cout << "Dark Wizard Attacks style: " << darkWizard << "\n";
  darkWizard.setAttackStyle("Blindings light"); //errado
  darkWizard.setAttackStyle("Blinding light"); //errado
  darkWizard.setAttackStyle("Shadow cast");
  darkWizard.setAttackStyle("Dark fire");
  darkWizard.getAttackStyle();

  cout << "Dark Wizard Type of Rage: " << darkWizard << "\n";
  darkWizard.setTypesOfRage("Low");
  darkWizard.setTypesOfRage("Moderate");
  darkWizard.setTypesOfRage("High");
  darkWizard.getTypesOfRage();

  darkWizard.verifySpell("Darkness");



  lightWizard.wizardWarning();
  lightWizard.setLightningSpeed(20);
  lightWizard.setDirection(40);
  lightWizard.lightningAttack();
  vector<string *> magicians;
      wizard1.setName(nome1);

  lightWizard.showAttackStyle("Wizard");

  wizard1.printInfo();

  magicians.push_back(new string(wizard1.getName()));
  wizard2.setName(nome2);
  magicians.push_back(new string(wizard2.getName()));
  wizard3.setName(nome3);
  magicians.push_back(new string(wizard3.getName()));


  vector<string *> poderes;
  wizard1.setPowerName(poder1);
  poderes.push_back(new string(wizard1.getPowerName()));
  wizard2.setPowerName(poder2);
  poderes.push_back(new string(wizard2.getPowerName()));
  wizard3.setPowerName(poder3);
  poderes.push_back(new string(wizard3.getPowerName()));

  for (int i = 0; i < poderes.size(); i++)
    wizard1.registerWizardsPower(*poderes[i]);

  wizard1.evolve();

  
  warrior.setName("Varian Wrynn");
  warrior.setAge(24);
  warrior.setCharacterStyle("Short Range");
  warrior.printInfo();


  vector<string *> armas;
  warrior.setWeapon(arma1);
  armas.push_back(new string(warrior.getWeapon()));
  warrior.setWeapon(arma2);
  armas.push_back(new string(warrior.getWeapon()));
  for (int i = 0; i < armas.size(); i++)
    warrior.registerNewWeaponsWarrior(*armas[i]);

  warrior.verifyState();

  cout<<"VECTOR DE PONTEIROS"<< '\n';
  //Vector de ponteiro sem Dynamic e sem o typeId
  vector<Wizard > wizards;

  wizards.push_back(lightWizard);
  wizards.push_back(darkWizard);
  wizards.push_back(wizard1);
  wizards.push_back(wizard2);
  wizards.push_back(wizard3);

  for (int i = 0; i < wizards.size(); i++)
    cout << wizards[i].getName() << '\n';

  //delete dos ponteiros
  for (int i = 0; i < wizards.size(); i++)
    delete magicians[i];

  for (int i = 0; i < magicians.size(); i++)
    delete magicians[i];
  for (int i = 0; i < armas.size(); i++)
    delete armas[i];
  for (int i = 0; i < poderes.size(); i++)
    delete poderes[i];



  return 0;
}