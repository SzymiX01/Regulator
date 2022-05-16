#include "Symulacja.h"

Symulacja::Symulacja()
	: pomieszczenie{2, 5, 5},
	grzejnik(5000),
	aktualny_czas(0),
	regulator(nullptr)
{}

void Symulacja::iteracja(float czas) {
	float sterowanie = regulator->steruj(pomieszczenie.getTemperatura());
	grzejnik.ustaw(sterowanie);
	rejestr.push_back({ aktualny_czas, pomieszczenie.getTemperatura(), sterowanie });
	pomieszczenie.dodajCieplo(grzejnik.oddajCieplo());
	pomieszczenie.aktualizuj(czas);
	
}

void Symulacja::przebieg(int iteracje, float dt) {
	for (int it = 0; it < iteracje; it++) {
		aktualny_czas += dt;
		iteracja(dt);
	}
}

void Symulacja::zapis(std::string nazwa_pliku) {
	std::ofstream plik(nazwa_pliku);
	std::locale pol("pl_PL");
	plik.imbue(pol);
	for (Pomiar x : rejestr) {
		plik << x.czas << "; " << x.temperatura << "; " << x.sterowanie << std::endl;
	}
	plik.close();
}

void Symulacja::wyswietl() {
	for (Pomiar x : rejestr){
		std::cout << x.czas << "; " << x.temperatura << "; " << x.sterowanie << std::endl;
	}
}

void Symulacja::setRegulator(Regulator* _regulator) {
	regulator = _regulator;
}