#include "RegulatorBB.h"


void RegulatorBB::setHistereza(float _histereza) {
	histereza = _histereza;
}

float RegulatorBB::steruj(float aktualnaTemperatura) {
	if (aktualnaTemperatura > zadanaTemperatura + histereza / 2) {
		sterowanie = 0;
	}
	else if (aktualnaTemperatura < zadanaTemperatura - histereza / 2) {
		sterowanie = 1;
	}
	return sterowanie;
}