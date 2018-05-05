#ifndef __RACE__H__
#define __RACE__H__

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class race(){

 public:
  race(){};
  ~race(){};

  virtual float SetTailleRace() = 0;
  virtual int SetResistance() = 0;

 protected:
  float _taille_race;
  int _resistance;

};

#endif
