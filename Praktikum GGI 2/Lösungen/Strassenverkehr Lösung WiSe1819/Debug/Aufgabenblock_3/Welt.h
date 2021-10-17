#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include <list>
#include "Kreuzung.h"

class Welt
{
public:
	Welt(void);
	virtual ~Welt(void);

	void vEinlesen();
	void vSimulation();
	void vEinlesenMitGrafik();

private:
	list<Kreuzung*> p_ptKreuzungen;
};

