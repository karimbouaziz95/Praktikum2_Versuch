#pragma once
class Weg;
class Fahrzeug;

class FahrAusnahme
{
public:
	FahrAusnahme(Weg* weg, Fahrzeug* fzg);
	virtual ~FahrAusnahme();
	virtual void vBearbeiten(void) = 0;

protected:

	Weg *pWeg;
	Fahrzeug *pFahrzeug;
};

