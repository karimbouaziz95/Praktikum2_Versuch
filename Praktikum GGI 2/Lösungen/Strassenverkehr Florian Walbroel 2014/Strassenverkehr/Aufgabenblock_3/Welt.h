#pragma once
#include "Kreuzung.h"


class Welt
{
public:
	Welt(void);
	~Welt(void){};

	void vEinlesen();
	void vSimulation();
	void vEinlesenMitGrafik();

private:
	list<Kreuzung*>p_ptKreuzungen;
};
