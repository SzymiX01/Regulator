#pragma once
#include "Regulator.h"
class RegulatorPID :
    public Regulator
{
private:
    float kp, ki, kd;
    float poprzedniaTemperatura;
    float poprzedniUchyb;
    float calkaUchybu;
public:
    RegulatorPID();
    ~RegulatorPID() = default;
    RegulatorPID(RegulatorPID&) = default;

    void steruj();
};

