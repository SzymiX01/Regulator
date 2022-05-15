#include "Grzejnik.h"

Grzejnik::Grzejnik(int moc_)
	: moc(moc_),
	procent_mocy(1)
{}

float Grzejnik::oddajCieplo() {
	return procent_mocy * moc;
}
