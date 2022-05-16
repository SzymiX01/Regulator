#include "Symulacja.h"
#include <iostream>

int main() {
	Symulacja sim;
	sim.wyswietl();
	sim.przebieg(100, 0.1);
	sim.wyswietl();
	return 0;
}