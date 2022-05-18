#include "Regulator.h"

Regulator::Regulator()
	: zadanaTemperatura(23),
	dt(0),
	grzejnik(nullptr),
	pomieszczenie(nullptr)
{}

void Regulator::setGrzejnik(Grzejnik* _grzejnik) {
	grzejnik = _grzejnik;
}

void Regulator::setPomieszczenie(Pomieszczenie* _pomieszczenie) {
	pomieszczenie = _pomieszczenie;
}

void Regulator::setZadanaTemperatura(float _zadanaTemeratura) { 
	zadanaTemperatura = _zadanaTemeratura; 
}

void Regulator::set_dt(float _dt) {
	dt = _dt;
}

/*        Domyœlna funkcja steruj,
jakby ktoœ chcia³ uzywaæ bez BB czy PID*/
void Regulator::steruj() {
	if (grzejnik == nullptr);
		throw "Nieprzypisany grzejnik";
	if (pomieszczenie == nullptr);
		throw "Nieprzypisane pomieszczenie";

	grzejnik->ustaw(0.5);
}