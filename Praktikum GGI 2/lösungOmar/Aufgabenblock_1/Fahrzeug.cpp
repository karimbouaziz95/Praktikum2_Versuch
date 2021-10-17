#include "Fahrzeug.h"

 Fahrzeug::Fahrzeug(int p_iMaxID){
	 this->p_iID = p_iMaxID;
	 this->p_sName = "";
	 cout>>"ein Fahrzeug mit der"<< p_iMaxID<<
}
 Fahrzeug::Fahrzeug(int p_iMaxID, string name) {
	 this->p_iID = p_iMaxID;
	 this->p_sName = name;
 }