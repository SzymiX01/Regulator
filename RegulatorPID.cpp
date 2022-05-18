#include "RegulatorPID.h"

/*
float dt;
float kp, ki, kd;
float porzedniaTemperatura;
float sterowanie;
*/

RegulatorPID::RegulatorPID()
	: kp(4.0), ki(0.02), kd(0.1),
	poprzedniaTemperatura(20), poprzedniUchyb(0), calkaUchybu(0)
{}


void RegulatorPID::steruj(){
	if (grzejnik == nullptr)
		throw "Nieprzypisany grzejnik";
	if (pomieszczenie == nullptr)
		throw "Nieprzypisane pomieszczenie";
	if (dt == 0)
		throw "Dzielenie przez 0";

	float aktualnaTemperatura = pomieszczenie->getTemperatura();
	float uchyb = zadanaTemperatura - aktualnaTemperatura;
	float up = kp * uchyb;

	calkaUchybu += uchyb * dt;
	float ui = ki * calkaUchybu;

	float pochodnaUchybu = (uchyb - poprzedniUchyb) / dt;
	float ud = kd * pochodnaUchybu;

	poprzedniaTemperatura = aktualnaTemperatura;
	poprzedniUchyb = uchyb;
	float sterowanie = up + ui + ud;

	if (sterowanie > 1)
		grzejnik->ustaw(1);
	else if (sterowanie < 0)
		grzejnik->ustaw(0);

	grzejnik->ustaw(sterowanie);
}