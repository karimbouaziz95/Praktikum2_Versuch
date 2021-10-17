#include "Fahrzeug.h"

 Fahrzeug::Fahrzeug(int p_iMaxID){
	 this->p_iID = p_iMaxID;
	 this->p_sName = "";
	 cout << "ein Fahrzeug mit der ID :" << this->p_iID << "und mit der Name "<< this->p_sName <<"hinzugefügt"<<endl;
}
 Fahrzeug::Fahrzeug(int p_iMaxID, string name) {
	 this->p_iID = p_iMaxID;
	 this->p_sName = name;
	 cout << "ein Fahrzeug mit der ID:" << this->p_iID <<"und mit dem Name "<< this->p_sName <<endl;
 }