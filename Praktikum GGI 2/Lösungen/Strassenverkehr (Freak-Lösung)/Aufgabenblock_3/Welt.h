#pragma once

#include <istream>
#include <list>

using namespace std;

class Kreuzung;

class Welt
{
public:
	// Konstruktor:
	Welt(void);
	// Destruktor:
	virtual ~Welt(void);

	// Einlesen der Daten aus Stream:
	void vEinlesen(istream& istreamStream);
	void vEinlesenMitGrafik(istream& istreamStream);

	// Simulation:
	void vSimulation();
private:
	list<Kreuzung*> p_pKreuzungen;
};

