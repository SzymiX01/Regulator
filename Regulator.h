#pragma once

#include "Grzejnik.h"
#include "Pomieszczenie.h"


class Regulator
{
protected:

	float zadanaTemperatura;
	float dt;
	Grzejnik* grzejnik;
	Pomieszczenie* pomieszczenie;

public:
	Regulator();
	~Regulator() = default;
	Regulator(Regulator&) = default;

	void setGrzejnik(Grzejnik* _grzejnik);
	void setPomieszczenie(Pomieszczenie* _pomieszczenie);
		
	void setZadanaTemperatura(float _zadanaTemeratura); // po co podawac za kazdym razem, jak mozna raz
	void set_dt(float _dt);	//j.w.

	virtual void steruj();
};
