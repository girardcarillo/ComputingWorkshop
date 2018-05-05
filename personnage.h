#ifndef __PERSONNAGE__H__
#define __PERSONNAGE__H__

class personnage{

public:
  personnage();
  ~personnage();

  bool is_dead();

  int SetPuissanceArme(int puissance_arme);

  void SetPuissanceArmure(int puissance_armure);

  void DefoncerTranquille(personnage* a_personnage);

  void SeFaireDefoncer(int degats);

  virtual int SetVieMaximum();

  virtual int SetVieCourante();

  virtual int SetArmure();

  virtual int SetArme();

  virtual int DefonceSpeciale(personnage* a_personnage);

  virtual string* GetPersonnageType const();

protected:
  int _puissance_armure;
  int _puissance_arme;
  int _vie_courante;
  int _vie_maximum;
  string _personnage_type;

};

#endif
