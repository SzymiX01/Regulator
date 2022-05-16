#pragma once

class Regulator
{
protected:

	float zadanaTemperatura;

public:
	Regulator() 
		: zadanaTemperatura(0) {};
	void setZadanaTemperatura(float _zadanaTemeratura) { zadanaTemperatura = _zadanaTemeratura;  };
	virtual float steruj(float aktualnaTemperatura) { return 0.5; };
};
