#include <string>
#include <iostream>
using namespace std;

class Fahrzeug
{
private :
	int p_iID;
	string p_sName;
	Fahrzeug();
	Fahrzeug(int p_iMaxID);
	Fahrzeug(int p_iMaxID,string name);
	-Fahrzeug();
 };

