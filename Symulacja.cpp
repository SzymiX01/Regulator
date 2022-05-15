#include "Symulacja.h"

Symulacja::Symulacja()
	: pomieszczenie{2.5, 5, 5},
	grzejnik(2500)
{}

void Symulacja::iteracja(float czas) {
	pomieszczenie.dodajCieplo(grzejnik.oddajCieplo());
	pomieszczenie.aktualizuj(czas);
}

void Symulacja::przebieg(int iteracje, float dt) {
	for (int it = 0; it < iteracje; it++) {
		iteracja(dt);
	}
}

void Symulacja::zapis(char* dane) {

}