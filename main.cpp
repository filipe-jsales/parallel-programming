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
#include "Enemy.cpp"
#include "Enemy.h"
// #include "Creature.h"
// #include "Creature.cpp"
#include <iostream>
#include <vector>
using std::cout;
using std::string;
using std::vector;

int main()
{

  // Escola fate;

  Wizard wizard1;
  Wizard wizard2;
  Wizard wizard3;
  DarkWizard wizard4;
  LightWizard wizard5;
  Warrior warrior;

  Enemy enemy;
  enemy.showType();

  WarCraftCharacter personagem;

  string nome1 = "Rhonin";
  string nome2 = "Medith";
  string nome3 = "Jaina Proudmore";

  string poder1 = "Darkness";
  string poder2 = "Psycho";
  string poder3 = "Awareness";

  string arma1 = "Knife";
  string arma2 = "Sword";
  personagem.setName("Aegwynn");

  personagem.setAge(15);
  wizard1.setCharacterStyle("Long Range");
  warrior.setName("Varian Wrynn");
  warrior.setCharacterStyle("Short Range");
  wizard1.setAge(18);
  wizard4.getRage("Darkness");
  wizard5.setSkill("Blinding Light");
  warrior.setAge(24);
  wizard4.setDarkMagic(100);
  wizard4.shadowCastSkill();
  wizard5.wizardWarning();
  wizard5.setLightningSpeed(20);
  wizard5.setDirection(40);
  wizard5.lightningAttack();
  vector<string *> alunos;
  wizard1.setName(nome1);

  alunos.push_back(new string(wizard1.getName()));
  wizard2.setName(nome2);
  alunos.push_back(new string(wizard2.getName()));
  wizard3.setName(nome3);
  alunos.push_back(new string(wizard3.getName()));

  for (int i = 0; i < alunos.size(); i++)
    // fate.cadastrarAlunoFate(*alunos[i]);

    wizard1.registerWizards(alunos.size());

  // fate.registerProfessores("Andreas");
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
  vector<string *> armas;
  warrior.setWeapon(arma1);
  armas.push_back(new string(warrior.getWeapon()));
  warrior.setWeapon(arma2);
  armas.push_back(new string(warrior.getWeapon()));
  for (int i = 0; i < armas.size(); i++)
    warrior.registerNewWeaponsWarrior(*armas[i]);

  warrior.verifyState();

  Witcher bruxo;
  bruxo.name = "Isobel";
  bruxo.typeofPower = "gelo";
  bruxo.attackStrength = 75;
  wizard1.getWitcherPower(bruxo);
  cout << "Character Style: " << wizard1.getCharacterStyle() << '\n';
  // cout << fate;
  cout << wizard1;
  cout << warrior;
  cout << personagem;

  for (int i = 0; i < alunos.size(); i++)
    delete alunos[i];
  for (int i = 0; i < armas.size(); i++)
    delete armas[i];
  for (int i = 0; i < poderes.size(); i++)
    delete poderes[i];

  return 0;
}