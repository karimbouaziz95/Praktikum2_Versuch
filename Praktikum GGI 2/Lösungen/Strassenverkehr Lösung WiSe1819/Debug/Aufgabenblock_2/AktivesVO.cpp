#include "AktivesVO.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;
static int p_iMaxID = 1;

AktivesVO::AktivesVO(void)
{
	vInitialisierung();
	
}

AktivesVO::AktivesVO(const string sName)
{
	vInitialisierung();
	
}


AktivesVO::~AktivesVO()
{
}

void AktivesVO::vAbfertigung() //rein virtuelle Methode
{
	
}

ostream & AktivesVO::ostreamAusgabe(ostream & output)
{

	cout << setfill(' '); // Reset Fill
	output << setfill(' ');
	output << left << setw(8) << setfill(' ') << p_iID;
	output << left << setw(8) << setfill(' ') << p_sName;
	output << left << setw(3) << setfill(' ') << ":";
	output << fixed;
	return output;
}

//Überladen des Ausgabe-Operators "<<"
ostream& operator <<(ostream& output, AktivesVO& aktVo)
{
	aktVo.ostreamAusgabe(output);
	return output;
}

void AktivesVO::vInitialisierung()
{

	p_sName = "";
	p_dZeit = 0;
	p_iID = p_iMaxID;
	p_iMaxID++;

}
