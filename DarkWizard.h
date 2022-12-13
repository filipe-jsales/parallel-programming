#ifndef DARKWIZARD_H
#define DARKWIZARD_H

#include "Wizard.h"
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::ostream;

class DarkWizard: public Wizard
{
    friend ostream &operator<<( ostream &, const DarkWizard & );
public:
    DarkWizard();
    DarkWizard(const string &,const string &,const int, const int ,const string&);
    DarkWizard(const DarkWizard &,const string &,const string &,const int, int, const string&);
    ~DarkWizard();

    string getTypeofRage()const;
    int getDarkMagic()const;
    void getRage( const string &);
    void setDarkMagic( int);
    void darkShieldSkill();
    void shadowCastSkill();
 
    void operator=(const DarkWizard &);
    bool operator==(const DarkWizard &)const;
    bool operator!=(const DarkWizard &)const;
    void operator!();
 
private:
  
   string typeofRage;
   int magicLevel;
};

#endif // DARKWIZARD_H