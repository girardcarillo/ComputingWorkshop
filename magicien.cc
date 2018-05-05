#ifndef __MAGICIEN__H__
#define __MAGICIEN__H__

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class magicien : public personnage{

public:
  magicien(){};
  ~magicien(){};

  void SetVieMaximum() {
    _vie_maximum = 100;
  }

  void SetVieCourante() {
    _vie_courante = _vie_maximum;
  }

  void SetArmure(){
    _puissance_armure = 5;
  }

  void SetArme(){
    _puissance_arme = 2;
  }

  void DefonceSpeciale(personnage* a_personnage){
    puissance_arme *= puissance_arme;
    a_personnage->SeFaireDefoncer(puissance_arme);
  }

  string* GetPersonnageType const(){
    _personnage_type = "magicien";
    return _personnage_type;
  }

};

#endif
