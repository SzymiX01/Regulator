#include "Symulacja.h"

Symulacja::Symulacja()
	: pomieszczenie{2, 5, 5},
	grzejnik(5000),
	aktualny_czas(0),
	regulator(nullptr)
{}

void Symulacja::iteracja(float dt) {
	regulator->steruj();
	pomieszczenie.dodajCieplo(grzejnik.oddajCieplo());
	pomieszczenie.aktualizuj(dt);
}

void Symulacja::przebieg(int iteracje, float dt) {
	std::cout << "Start petli symulacji" << std::endl;
	regulator->set_dt(dt); // zakomentowac do wyjatku dzielenia przez 0

	rejestr.push_back({ aktualny_czas, pomieszczenie.getTemperatura() });
	
	try {
		iteracja(dt);
	}
	catch(const char* wyjatek){
		std::cout << wyjatek << std::endl;
		std::cout << "Przerywam dzialanie petli symulacji" << std::endl;
		return;
	}

	aktualny_czas += dt;
	rejestr.push_back({ aktualny_czas, pomieszczenie.getTemperatura() });

	for (int it = 1; it < iteracje; it++) {
		iteracja(dt);
		aktualny_czas += dt;
		rejestr.push_back({ aktualny_czas, pomieszczenie.getTemperatura() });
	}
	std::cout << "Koniec petli symulacji" << std::endl;
}

void Symulacja::zapis(std::string nazwa_pliku) {
	std::ofstream plik;
	try{
		plik.open(nazwa_pliku);
		plik << "Czas ; Temperatura" << std::endl;
	}
	catch (...) {
		std::cout << "Nie udalo sie otworzyc pliku " << nazwa_pliku << std::endl;
		std::cout << "Przerywam zapis do pliku" << std::endl;
		return;
	}

	std::locale pol("pl_PL");
	plik.imbue(pol);
	for (Pomiar x : rejestr) {
		plik << x.czas << "; " << x.temperatura << std::endl;
	}
	plik.close();

	std::cout << "Zapisano dane do pliku " << nazwa_pliku << std::endl;
}

void Symulacja::wyswietl() {
	for (Pomiar x : rejestr){
		std::cout << x.czas << "; " << x.temperatura << "; " << std::endl;
	}
}

void Symulacja::setRegulator(Regulator* _regulator) {
	regulator = _regulator;
	regulator->setGrzejnik(&grzejnik); // zakomentowac do wyjatku nieprzypisania grzejnika
	regulator->setPomieszczenie(&pomieszczenie); // j.w. tylko pomieszczenia
}