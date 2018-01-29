#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

class Data{

private:
  //Constructor
  Data(){};

  //Destructor
  ~Data(){};

  static Data* _MyData_;
  int _myScore_;
  int _enemyScore1_;
  int _enemyScore2_;
  int _myRage_;
  int _enemyRage1_;
  int _enemyRage2_;
  int _unitCount_;

public:
  static Data* GetData(){
    if (_MyData_ == 0) {
      _MyData_ = new Data();
    }
    return _MyData_;
  };

  struct UnitData {
    int unitId;
    int unitType;
    int player;
    float mass;
    int radius;
    int x;
    int y;
    int vx;
    int vy;
    int capa;
    int capa2;
  };

  vector <UnitData> _UnitDataVector_;

  void DataReading(){
    cin >> _myScore_; cin.ignore();
    cin >> _enemyScore1_; cin.ignore();
    cin >> _enemyScore2_; cin.ignore();
    cin >> _myRage_; cin.ignore();
    cin >> _enemyRage1_; cin.ignore();
    cin >> _enemyRage2_; cin.ignore();
    cin >> _unitCount_; cin.ignore();
    _UnitDataVector_.resize(_unitCount_);
    for (int i = 0; i < _unitCount_; i++) {
      cin >> _UnitDataVector_[i].unitId >> _UnitDataVector_[i].unitType >>
        _UnitDataVector_[i].player >> _UnitDataVector_[i].mass >>
        _UnitDataVector_[i].radius >> _UnitDataVector_[i].x >>
        _UnitDataVector_[i].y >> _UnitDataVector_[i].vx >>
        _UnitDataVector_[i].vy >> _UnitDataVector_[i].capa >>
        _UnitDataVector_[i].capa2; cin.ignore();
    }
  }

  const vector <UnitData>& GetUnitsData () const {
    return _UnitDataVector_;
  };
};

class ManipulatedObject{
public:
  ManipulatedObject(){};
  ~ManipulatedObject(){};

  void SetUnitId(int unitId){
    _unitId=unitId;
  }

  void SetUnitType(int unitType){
    _unitType=unitType;
  }

  void SetRadius(int radius){
    _radius=radius;
  }

  void SetXY(int x, int y){
    _x=x;
    _y=y;
  }

  void SetVxVy(int Vx, int Vy){
    _Vx=Vx;
    _Vy=Vy;
  }

  void SetMass(float mass){
    _mass=mass;
  }

  void SetThrottle(int throttle){
    _throttle=throttle;
  }

  void SetFriction(float friction){
    _friction=friction;
  }

  int GetUnitId() const{
    return _unitId;
  }

  int GetUnitType() const{
    return _unitType;
  }

  int GetRadius () const{
    return _radius;
  }

  void GetXY (int &x, int &y) const{
    y=_y;
    x=_x;
  }

  virtual float GetMass() const = 0;

  int GetThrottle(){
    return _throttle;
  }

  float GetFriction (){
    return _friction;
  };

protected:
  int _unitId;
  int _unitType;
  int _radius;
  int _x;
  int _y;
  int _Vx;
  int _Vy;
  float _mass;
  int _throttle;
  float _friction=0;
};

class UserManipulated : public ManipulatedObject{
public:
  UserManipulated(){};
  ~UserManipulated(){};

  void SetPlayer(int player){
    _player=player;
  };

  int GetPlayer() const{
    return _player;
  }

  float GetMass() const {
    return _mass;
  }

protected:
  int _player;
};

class RobotManipulated : public ManipulatedObject{
public:
  RobotManipulated(){};
  ~RobotManipulated(){};
};

class Reaper : public UserManipulated{
public:
  Reaper(){};
  ~Reaper(){};
};

class Destroyer : public UserManipulated{
public:
  Destroyer(){};
  ~Destroyer(){};
};

class Doof : public UserManipulated{
public:
  Doof(){};
  ~Doof(){};
};

class Tanker : public RobotManipulated{
public:
  Tanker()
  {
    _friction=0.4;
  };
  ~Tanker(){};

  float GetMass () const{
    int W = 0;//donné plus tard
    return 2.5+W/2;
  }

  float GetFriction () const{
    return _friction;
  }

};

class Wreck : public RobotManipulated{
public:
  Wreck(){};
  ~Wreck(){};

  float GetMass() const{
    return 0;
  }

  float GetFriction () const{
    return 0;
  }

protected:
  int _capa;
  int _capa2;
};

class DataAnalysis{
private:
  //Constructor
  DataAnalysis(){};


  //Destructor
  ~DataAnalysis(){};

  static DataAnalysis* _MyDataAnalysis_;
  int _IWreckCount_ = 0;
  int _ITankerCount_ = 0;

  vector <UserManipulated*> _ActifUser_;
  vector <UserManipulated*> _ActifEnemi1_;
  vector <UserManipulated*> _ActifEnemi2_;
  vector <RobotManipulated*> _Passif_;
  vector <RobotManipulated*> _Tanker_;
  vector <RobotManipulated*> _Wreck_;
  const Data* a_data = Data::GetData();
  const vector <Data::UnitData>& RawDataVect=a_data->GetUnitsData();

public:

  static DataAnalysis* GetData(){
    DataAnalysis* MyDataAnalysis ;
    if (_MyDataAnalysis_ == 0) {
      _MyDataAnalysis_= new DataAnalysis();
    }
    return _MyDataAnalysis_;
  }

  const vector <RobotManipulated*>& GetWrecks() const {return _Wreck_;}
  const vector <UserManipulated*>& GetXYMe() const {return _ActifUser_;}
  const vector <UserManipulated*>& GetVxVyMe() const {return _ActifUser_;}

  void UpdateManipulatedObject(const Data::UnitData* a_data,ManipulatedObject* a_mo){
    a_mo->SetXY(a_data->x,a_data->y);
    a_mo->SetRadius(a_data->radius);
    a_mo->SetUnitId(a_data->unitId);
    a_mo->SetUnitType(a_data->unitType);
}

  void InitManipulatedObject(const Data::UnitData* a_data,ManipulatedObject* a_mo) {
    UpdateManipulatedObject(a_data,a_mo);
  };

  void UpdateUserManipulated(const Data::UnitData* a_data,UserManipulated* a_um)
  {
    a_um->SetPlayer(a_data->player);
    a_um->SetThrottle(0);
    UpdateManipulatedObject(a_data,a_um);
  }

  void InitUserManipulated(const Data::UnitData* a_data,UserManipulated* a_um){
    if(a_data->player == 0){
      _ActifUser_.push_back(a_um);
    }
    else if(a_data->player == 1){
      _ActifEnemi1_.push_back(a_um);
    }
    else if(a_data->player == 2){
      _ActifEnemi2_.push_back(a_um);
    }

    InitManipulatedObject(a_data, a_um);
    UpdateUserManipulated(a_data, a_um);
  }

  void UpdateRobotManipulated(const Data::UnitData* a_data,RobotManipulated* a_rm){
    UpdateManipulatedObject(a_data,a_rm);
  }

  void InitRobotManipulated(const Data::UnitData* a_data,RobotManipulated* a_rm){
    InitManipulatedObject(a_data,a_rm);
    _Passif_.push_back(a_rm);
    UpdateRobotManipulated(a_data,a_rm);
  }

  void UpdateReaper(const Data::UnitData* a_data,Reaper* a_reaper){
    UpdateUserManipulated(a_data,a_reaper);
  }

  void InitReaper(const Data::UnitData* a_data,Reaper* a_reaper){
    InitUserManipulated(a_data,a_reaper);
    UpdateReaper(a_data,a_reaper);
  }

  void UpdateDestroyer(const Data::UnitData* a_data,Destroyer* a_destroyer){
    UpdateUserManipulated(a_data,a_destroyer);
  }

  void InitDestroyer(const Data::UnitData* a_data,Destroyer* a_destroyer){
    InitUserManipulated(a_data,a_destroyer);
    UpdateDestroyer(a_data,a_destroyer);
  }

  void UpdateDoof(const Data::UnitData* a_data,Doof* a_doof){
    UpdateUserManipulated(a_data,a_doof);
  }

  void InitDoof(const Data::UnitData* a_data,Doof* a_doof){
    InitUserManipulated(a_data,a_doof);
    UpdateDoof(a_data,a_doof);
  }

  void UpdateTanker(const Data::UnitData* a_data,Tanker* a_tanker){
    UpdateRobotManipulated(a_data,a_tanker);
  }

  void InitTanker(const Data::UnitData* a_data,Tanker* a_tanker){
    InitRobotManipulated(a_data,a_tanker);
    _Tanker_.push_back(a_tanker);
    UpdateTanker(a_data,a_tanker);
  }

  void UpdateWreck(const Data::UnitData* a_data,Wreck* a_wreck){
    UpdateRobotManipulated(a_data,a_wreck);
  }

  void InitWreck(const Data::UnitData* a_data,Wreck* a_wreck){
    InitRobotManipulated(a_data,a_wreck);
    _Wreck_.push_back(a_wreck);
    UpdateWreck(a_data,a_wreck);
  }

  void Initialize(){

    for (auto unitData: RawDataVect){
      if (unitData.unitType < 3) {
        if (unitData.unitType == 0) {
          Reaper* a_reaper = new Reaper();
          InitReaper(&unitData,a_reaper);
        }
        else if (unitData.unitType == 1) {
          Destroyer * a_destroyer = new Destroyer();
          InitDestroyer(&unitData,a_destroyer);
        }
        else if (unitData.unitType == 2) {
          Doof * a_doof = new Doof();
          InitDoof(&unitData,a_doof);
        }
      }
      else if (unitData.unitType == 3) {
        Tanker * a_tanker = new Tanker();
        InitTanker(&unitData,a_tanker);
        _ITankerCount_++;
      }
      else if (unitData.unitType == 4) {
        Wreck * a_wreck = new Wreck();
        InitWreck(&unitData,a_wreck);
        _IWreckCount_++;
      }
    }
  }

  void UpDate(){
    int iterU=0;
    int iterE1=0;
    int iterE2=0;
    int iterT=0;
    int iterW=0;
    for (auto unitData: RawDataVect){
      if (unitData.unitType < 3){//actif
        if (unitData.unitType == 0) {//reaper
          if(unitData.player == 0){
            UpdateUserManipulated(&unitData,_ActifUser_[iterU]);
            iterU++;
          }
          else if(unitData.player == 1){
            UpdateUserManipulated(&unitData,_ActifEnemi1_[iterE1]);
            iterE1++;
          }
          else if(unitData.player == 2){
            UpdateUserManipulated(&unitData,_ActifEnemi2_[iterE2]);
            iterE2++;
          }
        }
        else if (unitData.unitType == 1) {//destroyer
          if(unitData.player == 0){
            UpdateUserManipulated(&unitData,_ActifUser_[iterU]);
            iterU++;
          }
          else if(unitData.player == 1){
            UpdateUserManipulated(&unitData,_ActifEnemi1_[iterE1]);
            iterE1++;
          }
          else if(unitData.player == 2){
            UpdateUserManipulated(&unitData,_ActifEnemi2_[iterE2]);
            iterE2++;
          }
        }
        else if (unitData.unitType == 2) {//doof
          if(unitData.player == 0){
            UpdateUserManipulated(&unitData,_ActifUser_[iterU]);
            iterU++;
          }
          else if(unitData.player == 1){
            UpdateUserManipulated(&unitData,_ActifEnemi1_[iterE1]);
            iterE1++;
          }
          else if(unitData.player == 2){
            UpdateUserManipulated(&unitData,_ActifEnemi2_[iterE2]);
            iterE2++;
          }
        }
      }
      else if (unitData.unitType == 3) {//passif-tanker
        if (_Tanker_.size() < iterT) {
        UpdateRobotManipulated(&unitData,_Tanker_[iterT]);
        }
        else {
          InitTanker(&unitData,(Tanker*)_Tanker_[iterT]);
          iterT++;
          _ITankerCount_=iterT;
        }
      }
      else if (unitData.unitType == 4) {//passif-wreck
        if (_Wreck_.size() < iterW){
          UpdateRobotManipulated(&unitData,_Wreck_[iterW]);
        }
        else {
          InitWreck(&unitData,(Wreck*)_Wreck_[iterW]);
          iterW++;
          _IWreckCount_=iterW;
        }
      }
    }
  }
};

class Decide{
 private:
  Decide(){};
  ~Decide(){};

  int _xWreck_;
  int _yWreck_;
  int _xMe_;
  int _yMe_;
  int _Vx_;
  int _Vy_;
  float _d_;


  static Decide* _output_;

  const DataAnalysis* a_UnitFacto = DataAnalysis::GetData();

 public:
  static Decide* GetIt(){
    if (_output_ == 0) {
      _output_ = new Decide();
    }
    return _output_;
  }

  struct OutPUTE {
    int x = 0;
    int y = 0;
    int Acc = 0;
  };

  vector <OutPUTE*> OutPut;

  void Remplissage(){
    OutPut.push_back(new OutPUTE);
  }

  OutPUTE* GetOutPUTE(int iter){
    return OutPut[iter];
  }

  float Position(){
    for (auto& wreck: a_UnitFacto->GetWrecks ()){
      wreck->GetXY(_xWreck_,_yWreck_);
    }
    for (auto& me: a_UnitFacto->GetXYMe ()){
      me->GetXY(_xMe_,_yMe_);
    }
    _d_ = sqrt(pow((_xWreck_-_xMe_),2)+pow((_yWreck_-_yMe_),2));
    return _d_;
  }

  float Velocity(){
    for (auto& me: a_UnitFacto->GetVxVyMe ()){
      me->GetVxVyMe(_Vx_,_Vy_);
    }
  }

  void Deplacement(OutPUTE* a_outpute){
  }

  void Cout(OutPUTE* a_outpute){
    cout << a_outpute->x<< " " << a_outpute->y << " " << a_outpute->Acc << endl;
    cout << "WAIT" << endl;
    cout << "WAIT" << endl;
  }
};

Data* Data::_MyData_ = 0;
DataAnalysis* DataAnalysis::_MyDataAnalysis_ = 0;
Decide* Decide::_output_ = 0;

int main()
{int iter = 0;
  // game loop
  while (1) {
    iter++;

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug
    // messages..." << endl;
    Data::GetData ()->DataReading();
    if (iter == 1) {
      DataAnalysis::GetData()->Initialize();
    }
    else {
      DataAnalysis::GetData()->UpDate();
    }

    Decide::GetIt()->Remplissage();
    Decide::GetIt()->Cout(Decide::GetIt()->GetOutPUTE(0));

  }
}

///Try for loop
// for (auto data: RawDataVect)
    // {
    //   if (data.unitType < 3) {
    //     //humain
    //     if (data.player == 0) {
    //       //moi
    //       if (data.unitType == 0) {
    //         //reaper
    //         InitReaper(a_data,a_reaper);
    //       }
    //       else if (data.unitType == 1) {
    //         //destroyer
    //         InitDestroyer(a_data,a_destroyer);
    //       }
    //       else if (data.unitType == 2) {
    //         //doof
    //         InitDoof(a_data,a_doof);
    //       }
    //     }
    //     else if (data.player == 1) {
    //       //enemi1
    //       if (data.unitType == 0) {
    //         //reaper
    //         InitReaper(a_data,a_reaper);
    //       }
    //       else if (data.unitType == 1) {
    //         //destroyer
    //       }
    //       else if (data.unitType == 2) {
    //         //doof
    //       }
    //     }
    //     else if (data.player == 2) {
    //       //enemi2
    //       if (data.unitType == 0) {
    //         //reaper
    //       }
    //       else if (data.unitType == 1) {
    //         //destroyer
    //       }
    //       else if (data.unitType == 2) {
    //         //doof
    //       }
    //     }
    //   }
    //   else {
    //     //robot
    //     if (data.unitType == 3) {
    //       //tanker
    //     }
    //     if (data.unitType == 4) {
    //       //wreck
    //     }
    //   }
    // }//endfor
