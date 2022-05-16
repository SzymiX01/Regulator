#pragma once
#include <iostream>
class Grzejnik
{
private:
	float moc;
	float procent_mocy;
public:
	Grzejnik(float moc_);
	void ustaw(float procent);
	float oddajCieplo();
};

