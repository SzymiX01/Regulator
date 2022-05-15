#pragma once
#include "Grzejnik.h"
#include "Pomieszczenie.h"

class Symulacja
{
private:

	Grzejnik grzejnik;
	Pomieszczenie pomieszczenie;

public:
	Symulacja();
	void iteracja(float czas);
	void przebieg(int iteracja, float dt);
	void zapis(char* dane);
};

