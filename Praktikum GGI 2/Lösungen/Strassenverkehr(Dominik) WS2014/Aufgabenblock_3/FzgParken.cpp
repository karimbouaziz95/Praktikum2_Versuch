#include "FzgParken.h"
#include "FahrAusnahme.h"
#include "FzgVerhalten.h"
#include "Losfahren.h"


//<Konstruktoren_Destruktoren>
FzgParken::FzgParken()
{
}
FzgParken::FzgParken(Weg* pweg,double dStartzeitpunkt)
{

	p_pSaveWeg = pweg;
	p_dStartzeitpunkt = dStartzeitpunkt;

}
FzgParken::~FzgParken()
{
}
//</Konstruktoren_Destruktoren>



//<Allgemeine_Funktionen>
double FzgParken::dStrecke(Fahrzeug* pdriveThing,double time)
{
	
	if (fabs(dGlobaleZeit - p_dStartzeitpunkt)<0.01 || p_dStartzeitpunkt - 0.5 < dGlobaleZeit)
	{
		throw Losfahren(pdriveThing,p_pSaveWeg) ;
		 

	}
	

	return 0.0;
}
//</Allgemeine_Funktionen>