#include "Symulacja.h"
#include "RegulatorBB.h"
#include "RegulatorPID.h"
#include <iostream>

#define TMP 23
#define DT 1
#define CYKLE 1000

int main() {
	Symulacja sim;

	RegulatorPID regulator;
	regulator.setZadanaTemperatura(TMP);
	//regulator.setHistereza(2);
	regulator.set_dt(DT);
	sim.setRegulator(&regulator);

	sim.przebieg(CYKLE, DT);

	sim.zapis("symulacja.csv");

	return 0;
}