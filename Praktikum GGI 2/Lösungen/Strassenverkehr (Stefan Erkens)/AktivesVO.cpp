#pragma once

#include "AktivesVO.h"

AktivesVO::AktivesVO()
{
	p_iMaxID ++;
	p_iID = p_iMaxID;
	p_sName = "";
	p_dZeit = 0;
}


AktivesVO::AktivesVO(string name)
{
	p_iMaxID ++;
	p_iID = p_iMaxID;
	p_sName = name;
	p_dZeit = 0;
}


void AktivesVO::vAusgabe()
{
	cout << setiosflags(ios::fixed) << setprecision(2) << left << setw(4) << p_iID << setw(7) << p_sName << ":  ";
}

ostream& AktivesVO::ostreamAusgabe(ostream& data)
{
	data << setiosflags(ios::fixed) << setprecision(2) << left << setw(4) << p_iID << setw(9) << p_sName << ":  "; 
	return data;
}

ostream& operator << (ostream& data_out, AktivesVO& name)
{
	name.ostreamAusgabe(data_out);
	return data_out;
}