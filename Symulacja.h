#pragma once
#include "Grzejnik.h"
#include "Pomieszczenie.h"
#include "Regulator.h"
#include <iostream>
#include <vector>
#include <fstream>

struct Pomiar {
	float czas;
	float temperatura;
	float sterowanie;
};


class Symulacja
{
private:
	Grzejnik grzejnik;
	Pomieszczenie pomieszczenie;
	float aktualny_czas;
	std::vector<Pomiar> rejestr;
	Regulator* regulator;

public:
	
	Symulacja();
	void iteracja(float czas);
	void przebieg(int iteracja, float dt);
	void zapis(std::string nazwa_pliku);
	void wyswietl();
	//Grzejnik& getGrzejnik() { return grzejnik; }
	//Pomieszczenie& getPomieszczenie() { return pomieszczenie; }
	void setRegulator(Regulator* regulator);
};

