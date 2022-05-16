#include "RegulatorPID.h"

/*
float dt;
float kp, ki, kd;
float porzedniaTemperatura;
float sterowanie;
*/

RegulatorPID::RegulatorPID()
	: dt(1),
	kp(4.0), ki(0.02), kd(0.1),
	poprzedniaTemperatura(20), poprzedniUchyb(0), calkaUchybu(0)
{}


float RegulatorPID::steruj(float aktualnaTemperatura){
	float uchyb = zadanaTemperatura - aktualnaTemperatura;
	float up = kp * uchyb;

	calkaUchybu += uchyb * dt;
	float ui = ki * calkaUchybu;

	float pochodnaUchybu = (uchyb - poprzedniUchyb) / dt;
	float ud = kd * pochodnaUchybu;

	poprzedniaTemperatura = aktualnaTemperatura;
	poprzedniUchyb = uchyb;
	float steruj = up + ui + ud;

	if (steruj > 1)
		return 1;
	else if (steruj < 0)
		return 0;

	return steruj;
}

void RegulatorPID::set_dt(float _dt){
	dt = _dt;
}
//void RegulatorPID::setNastawy(float _kp, float _ki, float _kd){}