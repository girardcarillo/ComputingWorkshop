#ifndef __HUMAIN__H__
#define __HUMAIN__H__

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class humain : public race{
public:
  humain(){};
  ~humain(){};

  void SetTailleRace(){
    _taille_race = 170;
  }

  void SetResistance(){
    _resistance = 2;
  }

};


#endif
