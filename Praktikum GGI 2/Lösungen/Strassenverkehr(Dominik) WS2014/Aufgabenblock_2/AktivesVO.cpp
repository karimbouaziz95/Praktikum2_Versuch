#include "AktivesVO.h"


int AktivesVO::p_iMaxID = 0;


//<Konstruktoren_Destruktoren>
AktivesVO::AktivesVO()
{
}
AktivesVO::~AktivesVO()
{
}
//</Konstruktoren_Destruktoren>



//<Allgemeine_Funktionen>
void AktivesVO::vInitialisierung()
{

	p_sName = "";
	p_iMaxID++;
	p_iID = p_iMaxID;
	
	

}
//</Allgemeine_Funktionen>



//<Setter_Getter_Funktionen>
string AktivesVO::getsName()const {


	return p_sName;


}
//</Setter_Getter_Funktionen>



//<Ueberladungen>
ostream& operator << (ostream& out, AktivesVO& x)
{
	return x.ostreamAusgabe(out);
}
ostream& AktivesVO::ostreamAusgabe(ostream& out)
{
	out << setiosflags(ios::left) <<
	setw(5) << p_iID << setw(10)
	<< p_sName << setw(5) << ":";
	return out;
}
//</Ueberladungen>