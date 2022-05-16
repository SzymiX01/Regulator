#include "Grzejnik.h"

Grzejnik::Grzejnik(float moc_)
	: moc(moc_),
	procent_mocy(1)
{}

float Grzejnik::oddajCieplo() {
	return procent_mocy * moc;
}

void Grzejnik::ustaw(float procent) {
	if (procent <= 1.0) {
		procent_mocy = procent;
	}
	else if (procent > 1.0) {
		procent_mocy = 1;
		//std::cout << "Podany wska¿nik procentowy za wysoki \n";
	}
	else {
		procent_mocy = 0;
		//std::cout << "Podany wska¿nik procentowy za niski \n";
	}
	//std::cout << "Ustwiono moc na: " << procent_mocy * moc << "W"<<std::endl;
}
