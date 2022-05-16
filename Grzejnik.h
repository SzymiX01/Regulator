#pragma once
#include <iostream>
class Grzejnik
{
private:
	int moc;
	float procent_mocy;
public:
	Grzejnik(int moc_);
	void steruj(float procent);
	float oddajCieplo();
};

