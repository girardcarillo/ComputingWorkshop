#ifndef __GUERRIER__H__
#define __GUERRIER__H__

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class guerrier : public personnage{

public:
  guerrier(){};
  ~guerrier(){};

  void SetVieMaximum() {
    _vie_maximum = 150;
  }

  void SetVieCourante() {
    _vie_courante = _vie_maximum;
  }

  void SetArmure(){
    _puissance_armure = 2;
  }

  void SetArme(){
    _puissance_arme = 5;
  }

  void DefonceSpeciale(personnage* a_personnage){
    puissance_arme += puissance_arme;
    a_personnage->SeFaireDefoncer(puissance_arme);
  }

  string* GetPersonnageType const(){
    _personnage_type = "guerrier";
    return _personnage_type;
  }

};

#endif
