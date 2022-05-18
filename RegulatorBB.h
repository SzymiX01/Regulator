#pragma once
#include "Regulator.h"

#define HISTEREZA 2

class RegulatorBB :
    public Regulator
{
public:
    RegulatorBB() = default;
    ~RegulatorBB() = default;
    RegulatorBB(RegulatorBB&) = default;

    void steruj();
};

