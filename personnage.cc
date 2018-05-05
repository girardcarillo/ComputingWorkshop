#include <personnage.h>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

personnage::personnage()
{
  SetVieMaximum();
}

personnage::~personnage(){}


bool personnage::is_dead()
{
  if (_vie_courante <= 0)
    {
      return true;
    }
}

int SetPuissanceArme(int puissance_arme)
{
  _puissance_arme = puissance_arme;
}

void SetPuissanceArmure(int puissance_armure)
{
  _puissance_armure = puissance_armure;
}

void DefoncerTranquille(personnage* a_personnage)
{
  a_personnage->SeFaireDefoncer(_puissance_arme);
}

void SeFaireDefoncer(int degats)
{
  vie_courante -= (degats / puissance_armure);
}

virtual int SetVieMaximum() = 0;
virtual int SetVieCourante() = 0;
virtual int SetArmure() = 0;
virtual int SetArme() = 0;
virtual int DefonceSpeciale(personnage* a_personnage) = 0;
virtual string* GetPersonnageType const() = 0;// Penser à enum

int _puissance_armure = 0;
int _puissance_arme = 0;
int _vie_courante = 0;
int _vie_maximum = 0;
string _personnage_type = 0;


// class personnage(){

 // public:
 //  personnage(){
 //    SetVieMaximum ();
 //  };
 //  ~personnage(){};

  // bool is_dead(){
  //   if (_vie_courante <= 0) {
  //     return true;
  //   }
  // }

  // int SetPuissanceArme(int puissance_arme){
  //   _puissance_arme = puissance_arme;
  // }

  // void SetPuissanceArmure(int puissance_armure) {
  //   _puissance_armure = puissance_armure;
  // }

  // void DefoncerTranquille(personnage* a_personnage){
  //   a_personnage->SeFaireDefoncer(_puissance_arme);
  // }

  // void SeFaireDefoncer(int degats){
  //   vie_courante -= (degats / puissance_armure);
  // }

  virtual int SetVieMaximum() = 0;
  virtual int SetVieCourante() = 0;
  virtual int SetArmure() = 0;
  virtual int SetArme() = 0;
  virtual int DefonceSpeciale(personnage* a_personnage) = 0;
  virtual string* GetPersonnageType const() = 0;// Penser à enum

 // protected:
 //  int _puissance_armure;
 //  int _puissance_arme;
 //  int _vie_courante;
 //  int _vie_maximum;
 //  string _personnage_type;

};
