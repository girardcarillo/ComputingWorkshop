//on lit uniquement si ce fichier .h n'a pas déjà été déclaré ailleurs
#ifndef __SINGLETON__H__
#define __SINGLETON__H__

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//template de type T
template<typename T>
class singleton(){

 private:

  //Constructor
  singleton(){};

  //Destructor
  ~singleton(){};

  static singleton* _my_singleton_;

 public:

  //on veut que le singleton soit accessible de l'extérieur *sans avoir à créer l'objet*

  //static : objet crée à l'endroit de la compilation, qu'une seule fois, avec la même adresse (d'où
  //le côté static)

  static T* GetSingleton(){
    if (_my_singleton_ == 0) {
      //le singleton créé un template de type T
      _my_singleton_ = new T();
    }
    //on cast l'attribut vers la class fille
    return (T*)_my_singleton_;
  }

};

//On ne peut pas déclarer _my_singleton_=0 dans la class singleton() car sinon on définirait
//plusieurs fois _my_singleton_ alors qu'on l'a déclaré en static, et le compilateur ne gère pas ça.
singleton::_my_singleton_ = 0;

#endif
