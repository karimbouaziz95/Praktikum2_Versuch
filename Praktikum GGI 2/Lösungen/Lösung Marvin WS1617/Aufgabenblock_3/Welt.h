// file:	Welt.h
// author:	xxxxxx xxxxxx (xxxxxx)
// date:	27.09.2016

#pragma once

#include "Kreuzung.h"

// Diese Klasse stellt die gesamte Simulationsumgebung dar.
class Welt
{

public:

	// Standard-Konstruktor.
	Welt();

	// Standard-Destruktor.
	virtual ~Welt();

	// Liest eine Simulationsumgebung aus einem Eingabestrom ein.
	void vEinlesen(istream& in);

	// Liest eine Simulationsumgebung mit Grafikunterstützung aus einem Eingabestrom ein.
	void vEinlesenMitGrafik(istream& in);

	// Fertigt alle enthaltenen Kreuzungen ab (Simulationsschritt).
	void vSimulation();

	// Zeichnet alle untergeordneten Verkehrsobjekte.
	void vZeichnen();

	// Diese Ausgabefunktion bildet die Basis für die Überladung des Stream-Operators.
	ostream& ostreamAusgabe(ostream& out) const;

private:

	// Diese Liste enthält die Zeiger auf alle in der Welt vorhandenen Kreuzungen.
	list<Kreuzung*> p_pKreuzungen;

};

ostream& operator << (ostream& out, const Welt& w);