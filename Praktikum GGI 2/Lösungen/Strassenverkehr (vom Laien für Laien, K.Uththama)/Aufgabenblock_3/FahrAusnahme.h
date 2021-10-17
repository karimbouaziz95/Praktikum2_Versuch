#pragma once
#include "Fahrzeug.h"
#include "Weg.h"
#include "Kreuzung.h"

class FahrAusnahme
{
public:
	//Konstruktoren
	FahrAusnahme(void);
	FahrAusnahme(Weg*, Fahrzeug*);

	//Destruktor
	virtual ~FahrAusnahme(void);

	//Methode rein virtuell
	virtual void vBearbeiten() = 0;

protected:
	//Zeiger auf Weg mit Ausnahme
	Weg* p_pWeg;

	//Zeiger auf das Fahrzeug mit Ausnahme
	Fahrzeug* p_pFzg;
};

