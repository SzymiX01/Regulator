#pragma once
#include "Regulator.h"
class RegulatorBB :
    public Regulator
{
private:
    float histereza;
    float sterowanie;
public:
    RegulatorBB() : histereza(0), sterowanie(0) {};
    void setHistereza(float _histereza);
    float steruj(float aktualnaTemperatura);
};

