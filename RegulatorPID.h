#pragma once
#include "Regulator.h"
class RegulatorPID :
    public Regulator
{
private:
    float dt;
    float kp, ki, kd;
    float poprzedniaTemperatura;
    float poprzedniUchyb;
    float calkaUchybu;
public:
    RegulatorPID();
    float steruj(float aktualnaTemperatura);
    void set_dt(float dt);
    //void setNastawy(float _kp, float _ki, float _kd);
};

