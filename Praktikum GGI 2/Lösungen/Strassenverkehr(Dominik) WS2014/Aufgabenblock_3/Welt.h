#pragma once

#include "Kreuzung.h"


class Welt
{

public:
	Welt(void);
	~Welt(void){};

	void vSimulation();
	void vEinlesen();
	void vEinlesenMitGrafik();

private:


	list<Kreuzung*>p_ptKreuzungen;
};