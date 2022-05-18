#include "Symulacja.h"
#include "RegulatorBB.h"
#include "RegulatorPID.h"
#include <iostream>


#define DT 0.5
#define CYKLE 1000

int main() {
	Symulacja sim;
	RegulatorPID* pid;
	RegulatorBB* BB;

	char wybor;
	while (true) {
		std::cout << "Wybierz regulator uzyty do symulacji: " << std::endl;
		std::cout << "1 - BB " << std::endl;
		std::cout << "2 - PID " << std::endl;
		std::cout << "Wybor: ";
		std::cin >> wybor;
		if (wybor == '1') {
			BB = new RegulatorBB();
			sim.setRegulator(BB);
			break;
		}
		if (wybor == '2') {
			pid = new RegulatorPID();
			sim.setRegulator(pid);
			break;
		}
		else {
			std::cout << std::endl << "Nie dokonano prawidlowego wyboru!" << std::endl;

		}
	}

	sim.przebieg(CYKLE, DT);
	sim.zapis("symulacja.csv");

	return 0;
}