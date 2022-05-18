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
};

class Symulacja
{
private:
	Grzejnik grzejnik;
	Pomieszczenie pomieszczenie;
	Regulator* regulator;

	float aktualny_czas;
	std::vector<Pomiar> rejestr;
	
public:
	
	Symulacja();
	~Symulacja() = default;
	Symulacja(Symulacja&) = default;
	void iteracja(float dt);
	void przebieg(int iteracja, float dt);

	void setRegulator(Regulator* regulator);

	void zapis(std::string nazwa_pliku);
	void wyswietl();
	
};

