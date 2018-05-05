#ifndef __NAIN__H__
#define __NAIN__H__

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class nain : public race{
public:
  nain(){};
  ~nain(){};

  void SetTailleRace(){
    _taille_race = 80;
  }

  void SetResistance(){
    _resistance = 10;
  }

};

#endif
