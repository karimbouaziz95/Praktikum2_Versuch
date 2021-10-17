
#include "FzgVerhalten.h"
#include "Weg.h"
#include "Fahrzeug.h"
class Weg;
class Fahrzeug;

//<Konstruktoren_Destruktoren>
FzgVerhalten::FzgVerhalten()
{
	
}
FzgVerhalten::FzgVerhalten(Weg* pweg)
{

	p_pSaveWeg = pweg;

}
FzgVerhalten::~FzgVerhalten()
{
}
//</Konstruktoren_Destruktoren>



//<Setter_Getter_Funktionen>
Weg* FzgVerhalten::getp_pSaveWeg()
{
	return p_pSaveWeg;
}
//</Setter_Getter_Funktionen>
