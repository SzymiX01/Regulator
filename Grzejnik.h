#pragma once
#include <iostream>
class Grzejnik
{
private:
	float moc;
	float procent_mocy;
public:
	Grzejnik(float moc_);
	void steruj(float procent);
	float oddajCieplo();
};

