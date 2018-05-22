#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/


template<typename T>
class singleton
{

protected:

  //Constructor
  singleton(){};

  //Destructor
  ~singleton(){};

  //Le template représentera la class fille
  //Dans la class singleton on stocke un pointeur static vers la class fille T*
  static T* _my_singleton_;

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

template<typename T>
T* singleton<T>::_my_singleton_ = 0;

class data : public singleton<data>
{
  friend class singleton<data>;

private:

  data(){};
  ~data(){};

  int _unitCount_;

public:

  struct StructDataTour{
    int myScore;
    int enemyScore1;
    int enemyScore2;
    int myRage;
    int enemyRage1;
    int enemyRage2;
  };

  struct StructDataPlayer{
    int unitId;
    int unitType;
    int playerId;
    float mass;
    int radius;
    int x;
    int y;
    int vx;
    int vy;
    int capa;
    int capa2;
  };

  StructDataTour _DataTour_;
  vector <StructDataPlayer> _VectorDataPlayer_;

  void DataReading()
  {

    cin >> _DataTour_.myScore; cin.ignore();
    cin >> _DataTour_.enemyScore1; cin.ignore();
    cin >> _DataTour_.enemyScore2; cin.ignore();
    cin >> _DataTour_.myRage; cin.ignore();
    cin >> _DataTour_.enemyRage1; cin.ignore();
    cin >> _DataTour_.enemyRage2; cin.ignore();

    cin >> _unitCount_; cin.ignore();

    _VectorDataPlayer_.resize(_unitCount_);
    for (int i = 0; i < _unitCount_; i++) {
      cin >> _VectorDataPlayer_[i].unitId >>
        _VectorDataPlayer_[i].unitType >>
        _VectorDataPlayer_[i].playerId >>
        _VectorDataPlayer_[i].mass >>
        _VectorDataPlayer_[i].radius >>
        _VectorDataPlayer_[i].x >>
        _VectorDataPlayer_[i].y >>
        _VectorDataPlayer_[i].vx >>
        _VectorDataPlayer_[i].vy >>
        _VectorDataPlayer_[i].capa >>
        _VectorDataPlayer_[i].capa2; cin.ignore();
    }
  }

  const StructDataTour& GetDataTour() const
  {
    return _DataTour_;
  }

  const vector <StructDataPlayer>& GetDataPlayer() const
  {
    return _VectorDataPlayer_;
  }

};

class Entity
{

public:

  Entity(){};
  ~Entity(){};

  void SetUnitId(int unitId)
  {
    _unitId=unitId;
  }

  void SetPlayerId(int playerId)
  {
    _playerId=playerId;
  }

  void SetRadius(int radius)
  {
    _radius=radius;
  }

  void SetXY(int x, int y)
  {
    _x=x;
    _y=y;
  }

  int GetUnitId() const
  {
    return _unitId;
  }

  int GetPlayerId() const
  {
    return _playerId;
  }

  int GetRadius() const
  {
    return _radius;
  }

  int GetXY(int &x, int &y) const
  {
    x=_x;
    y=_y;
  }

  float GetDistance(const Entity & a_entity) const
  {
    float distance;
    distance = sqrt(pow(_x-a_entity._x,2)+pow(_y-a_entity._y,2));
    return distance;
  }

  virtual string GetType() const = 0;


protected:
  int _unitId;
  int _playerId;
  int _unitType;
  int _radius;
  int _x;
  int _y;
};

class Water : public Entity
{

public:

  Water(){};
  ~Water(){};

  void SetWaterContent(int waterContent)
  {
    _waterContent=waterContent;
  }

  int GetWaterContent()
  {
    return _waterContent;
  }

protected:
  int _waterContent;

};

class Vehicle : public Entity
{

public:
  Vehicle(){};
  ~Vehicle(){};

  void SetVxVy(int Vx, int Vy)
  {
    _Vx=Vx;
    _Vy=Vy;
  }

  int GetVxVy(int &Vx, int &Vy)
  {
    Vx=_Vx;
    Vy=_Vy;
  }

  virtual int GetThrottle() const = 0;
  virtual float GetFriction() const = 0;
  virtual float GetMass() const = 0;

protected:
  int _Vx;
  int _Vy;

};

class Wreck : public Water
{

public:
  Wreck(){};
  ~Wreck(){};

  string GetType() const
  {
    return "Wreck";
  }

};

class Reaper : public Vehicle
{
public:
  Reaper(){};
  ~Reaper(){};

  int GetThrottle() const
  {
    return 300;//to set
  }

  float GetFriction() const
  {
    return 0.2;
  }

  float GetMass() const
  {
    return 0.5;
  }

  string GetType() const
  {
    return "Reaper";
  }


};


class factory : public singleton<factory>
{
  friend class singleton<factory>;

private:

  factory(){};
  ~factory(){};

  vector<Water*> _water_entity_;
  vector<Vehicle*> _player1_entity_;
  vector<Vehicle*> _player2_entity_;
  vector<Vehicle*> _player3_entity_;

  int _counter_wreck_;
  int _counter_player1_;
  int _counter_player2_;
  int _counter_player3_;

  //const vector <Data::StructDataPlayer>& RawDataVect=a_data->GetDataPlayer();

public:

  void UpdateEntity(const data::StructDataPlayer* a_data_player, Entity* a_entity)
  {
    a_entity->SetUnitId(a_data_player->unitId);
    a_entity->SetRadius(a_data_player->radius);
    a_entity->SetXY(a_data_player->x,a_data_player->y);
  }

  void UpdateWater(const data::StructDataPlayer* a_data_player, Water* a_water)
  {
    UpdateEntity(a_data_player,a_water);
    a_water->SetWaterContent(a_data_player->capa);
  }

  void UpdateVehicle(const data::StructDataPlayer* a_data_player, Vehicle* a_vehicle)
  {
    UpdateEntity(a_data_player,a_vehicle);
    a_vehicle->SetVxVy(a_data_player->vx,a_data_player->vy);
  }

  void UpdateReaper(const data::StructDataPlayer* a_data_player, Reaper* a_reaper)
  {
    UpdateEntity(a_data_player,a_reaper);
    UpdateVehicle(a_data_player,a_reaper);
  }

  void UpdateWreck(const data::StructDataPlayer* a_data_player, Wreck* a_wreck)
  {
    UpdateEntity(a_data_player,a_wreck);
    UpdateWater(a_data_player,a_wreck);
  }

  void MakeEntity()
  {// & : pas copie, va directement chercher l'objet
    for (const auto &entity: data::GetSingleton()->GetDataPlayer())
      {
        if (entity.unitType == 0)
          {
            Vehicle* a_entity = new Reaper();
            if (entity.playerId == 1)
              {
                _player1_entity_.push_back(a_entity);
                _counter_player1_++;
              }
            else if (entity.playerId == 2)
              {
                _player2_entity_.push_back(a_entity);
                _counter_player2_++;
              }
            else if (entity.playerId == 3)
              {
                _player3_entity_.push_back(a_entity);
                _counter_player3_++;
              }
          }
        else if (entity.unitType == 4)
          {
            Water* a_entity = new Wreck();
            _water_entity_.push_back(a_entity);
            _counter_wreck_++;
          }
      }
  }

  void UpdateEntity()
  {
    int counter_wreck = 0;
    int counter_player1 = 0;
    int counter_player2 = 0;
    int counter_player3 = 0;
    for (const auto &entity: data::GetSingleton()->GetDataPlayer())
      {
        if (entity.unitType == 0)//if l'objet n'exite pas !!!!!!!
          {
            if (entity.playerId == 1)
              {
                UpdateVehicle(&entity,_player1_entity_[counter_player1]);
                counter_player1++;
              }
            else if (entity.playerId == 2)
              {
                UpdateVehicle(&entity,_player2_entity_[counter_player2]);
                counter_player2++;
              }
            else if (entity.playerId == 3)
              {
                UpdateVehicle(&entity,_player3_entity_[counter_player3]);
                counter_player3++;
              }
          }
        else if (entity.unitType == 4)
          {
            if (_water_entity_.size() < counter_wreck)
              {
                Water* a_entity = new Wreck();
                _water_entity_.push_back(a_entity);
                UpdateWater(&entity,_water_entity_[counter_wreck]);
              }

            UpdateWater(&entity,_water_entity_[counter_wreck]);
            counter_wreck++;
          }
      }
    _counter_wreck_=counter_wreck;
  }

  vector <const Water*> GetWater(string string_water)
  {
    vector<const Water*> water_coll;
    for (int i = 0; i < _counter_wreck_; ++i)
      {
        const string a_string = _water_entity_[i]->GetType();
        if (a_string == string_water)
          {
            water_coll.push_back(_water_entity_[i]);
          }
      }
    return water_coll;
  }

  vector <const Vehicle*> GetVehicle(string string_vehicle, int a_player_id)
  {
    vector<const Vehicle*> vehicle_coll;
    {
      if (a_player_id == 1)
        {
          for (int i = 0; i < _counter_player1_; ++i)
            {
              const string a_string = _player1_entity_[i]->GetType();
              if (a_string == string_vehicle)
                vehicle_coll.push_back(_player1_entity_[i]);
            }
        }
      if (a_player_id == 2)
        {
          for (int i= 0; i < _counter_player2_; ++i)
            {
              const string a_string = _player2_entity_[i]->GetType();
              if (a_string == string_vehicle)
                vehicle_coll.push_back(_player2_entity_[i]);
            }
        }
      if (a_player_id == 3)
        {
          for (int i= 0; i < _counter_player3_; ++i)
            {
              const string a_string = _player3_entity_[i]->GetType();
              if (a_string == string_vehicle)
                vehicle_coll.push_back(_player3_entity_[i]);
            }
        }
    }
    return vehicle_coll;
  }
};


class decision : public singleton<decision>
{
  friend class singleton<decision>;

private:
  decision(){};
  ~decision(){};

public:

  struct struct_outpute
  {
    int x = 0;
    int y = 0;
    float acc = 300; //acc = T/m
  };

  struct_outpute a_outpute;

  /*
    Une méthode qui détermine la flaque la plus proche
    Cette méthode doit
    -prendre en entrée un véhicule
    -retourner la position (x,y) de la flaque la plus proche de ce véhicule
  */
  void FlaqueProche()
  {
    vector <float> vector_distance;
    vector <const Vehicle*> vector_vehicle = factory::GetSingleton()->GetVehicle("Reaper",1);
    vector <const Water*> vector_water = factory::GetSingleton()->GetWater("Wreck");

    for (int i = 0; i < vector_vehicle.size(); ++i)
      {
        for (int j = 0; j < vector_water.size(); ++j)
          {
            float distance = vector_vehicle[i]->Entity::GetDistance(*vector_water[j]);
            vector_distance.push_back(distance);
          }
      }

    //float smallest = vector_distance[0];
    // for (int i = 0; i < vector_distance.size()-1; ++i)
    //   {
    //     if (vector_distance[i]<=smallest && i!=vector_distance.size()-1)
    //       {
    //         smallest=vector_distance[i];
    //       }
    //     else if (vector_distance[i]<= smallest && i==vector_distance.size()-1)
    //       {
    //         smallest=vector_distance[i];
    //         cout << smallest << endl;
    //       }
    //   }

    auto min_distance = min_element(vector_distance.begin(),vector_distance.end()) - vector_distance.begin();
    vector_water[min_distance]->Entity::GetXY(a_outpute.x, a_outpute.y);
  }

  void FlaqueGrosse()
  {

  }

  //à terme ce serait bien de faire deux méthodes : une qui détermine le point le plus proche, une
  //qui permet déaller à un point de la map

  //une méthode qui détermine l'accélération optimale
  float Acceleration()
  {

  }

  //la classe qui choisi la stratégie, et qui output
  void Strategie()
  {
    FlaqueProche();
    OutPute();
  }

  //implémente l'output dont va se servir strategie
  void OutPute()
  {
    cout << a_outpute.x<< " " << a_outpute.y << " " << a_outpute.acc << endl;
    cout << "WAIT" << endl;
    cout << "WAIT" << endl;
  }//normalement outpute dans une class singleton séparée

};

//rafinery : une class qui transforme des données brutes non exploitables en données mises en formes
//créer une méthode qui calcul la distance entre deux entités dans la class entity

int main()
{
  data::GetSingleton()->DataReading();
  factory::GetSingleton()->MakeEntity ();
  while (1)
    {
      decision::GetSingleton()->Strategie();
      data::GetSingleton()->DataReading();
      factory::GetSingleton()->UpdateEntity();
    }
}
