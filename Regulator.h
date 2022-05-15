#pragma once
class Regulator
{
private:
    int P;
    int I;
    int D;
    
public:
    Regulator(int P_, int I_, int D_):
    P(P_),
    I(I_),
    D(D_){}
};

