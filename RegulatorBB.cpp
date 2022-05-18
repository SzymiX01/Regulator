#include "RegulatorBB.h"


void RegulatorBB::steruj() {
	if (grzejnik == nullptr)
		throw "Nieprzypisany grzejnik";
	if (pomieszczenie == nullptr)
		throw "Nieprzypisane pomieszczenie";

	if (pomieszczenie->getTemperatura() > zadanaTemperatura + HISTEREZA / 2) {
		grzejnik->ustaw(0);
	}
	else if (pomieszczenie->getTemperatura() < zadanaTemperatura - HISTEREZA / 2) {
		grzejnik->ustaw(1);
	}
}