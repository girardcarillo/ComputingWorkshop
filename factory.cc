#ifndef __FACTORY__H__
#define __FACTORY__H__

#include "singleton.h"
#include "personnage.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

//on veut que la class factory hérite des propriétés de la class singleton avec un template de type factory

class factory : public singleton<factory>{
  //avec ça la class singleton<factory> aura accès au constructeur et au destructeur de la class factory
  friend class singleton<factory>;

private:

  factory(){};
  ~factory(){};

  //la factory créé les personnages, demande à l'utilisateur le nom des personnages et leur type, et
  //le stocke dans une map.
  //clé->nom du personnage
  //dictionnaire->type du personnage
  //!vérifier si le nom a déjà été utilisé

  map<string,personnage*> _personnage_map_;

public:

  void LecturePersonnage(){

    string nom_personnage;
    string type_personnage;
    int nombre_personnage;

    cout << "Entrez le nombre de combattants" << endl;
    cin >> nombre_personnage; cin.ignore();

    for (int i = 0; i < nombre_personnage+1; ++i) {
      cout << "Entrer le nom de votre personnage" << endl;
      cin >> nom_personnage; cin.ignore();
      cout << "Entrer le type de votre personnage, magicien/guerrier" << endl;
      cin >> type_personnage; cin.ignore();

      if (_personnage_map_.count(nom_personnage) < 1){
        if (type_personnage == "guerrier")
          _personnage_map_[nom_personnage] = new guerrier();
        else if (type_personnage == "magicien")
          _personnage_map_[nom_personnage] = new magicien();
        else
          cout << "Ce nom n'existe pas" << endl;
      }
      else{
        cout << "Ce nom existe déjà, MERDE !" << endl;
      }
    }


    //Une méthode qui renvoie une liste de noms de personnages (liste des clés de la map)
    list<string> GetPersonnagesName const(){
      list<string> list_noms_personnages;
      for (auto const& element_list : _personnage_map_) {
        list_noms_personnages.push_back(element_list.first);
      }
      return list_noms_personnages;
    }

    //Une méthode qui renvoie le type du personnage
    string GetPersonnageType(string nom_personnage){
      //string my_personnage_type = personnage::GetPersonnageType();
      if (_personnage_map_.count(nom_personnage) == 1) {
        return _personnage_map_[nom_personnage]->GetPersonnageType();
      }
      else {
        cout << "Ce nom n'existe pas !"
      }
    }

    //On veut avoir accès aux objets créés
    //Il faut créer une class GetObjet qui prenne en argument la clé (le string nom_personnage) et qui
    //renvoie l'objet de la map
    list<personnage*> GetPersonnages (list<string> list_noms_personnages){
      list<personnage*> to_return;
      for (auto const& element_list : list_noms_personnages) {
        to_return.push_back(GetPersonnage (element_list));
      }
      return to_return;
    }

    personnage* GetPersonnage (string nom_personnage){
      if (_personnage_map_.count(nom_personnage) == 1) {
        return _personnage_map_[nom_personnage];
      }
      else {
        cout << "Ce nom n'existe pas !" << endl;
      }
    }


  }
};

#endif
