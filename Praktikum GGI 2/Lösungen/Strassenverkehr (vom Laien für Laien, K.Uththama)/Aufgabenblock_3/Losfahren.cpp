#include "Losfahren.h"
#include "FzgParken.h"

//Std.Konstruktor
Losfahren::Losfahren(void)
{
}


//Destruktor
Losfahren::~Losfahren(void)
{
}


void Losfahren::vBearbeiten()
{
	cout << "Fahrausnahme : Losfahren"                                          << endl
		 << "Startzeitpunkt : " << (p_pFzg->getVerPtr())->dgetstartTime()		<< endl
		 << "Objekt : "  << p_pFzg->sgetName() << "  faehrt auf "             << endl
		 << "Weg : "       << *p_pWeg            << "los ! "					<< endl << endl;
	p_pFzg->vsetactTime((p_pFzg->getVerPtr())->dgetstartTime());
	p_pWeg->vAbgabe(p_pFzg);
	p_pWeg->vAnnahme(p_pFzg);
}
