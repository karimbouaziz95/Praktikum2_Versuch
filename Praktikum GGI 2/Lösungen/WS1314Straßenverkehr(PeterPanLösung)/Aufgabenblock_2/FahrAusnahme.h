#pragma once
class Fahrzeug;
class Weg;

class FahrAusnahme
{
public:
	FahrAusnahme(void);
	FahrAusnahme(Fahrzeug* pFzg, Weg* pWeg);
	virtual ~FahrAusnahme(void);
	virtual void vBearbeiten(void) = 0;

protected:
	Fahrzeug* p_pFzg;
	Weg* p_pWeg;
};

