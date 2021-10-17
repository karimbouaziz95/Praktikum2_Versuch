#ifndef AKTIVESVO_H
#define AKTIVESVO_H
#pragma once
#include <sstream>
#include <iomanip>
#include <string>
#include <iostream>


using namespace std;

class AktivesVO
{

public:
	AktivesVO();
	virtual ~AktivesVO();

	virtual void    vAbfertigung() = 0;

	virtual ostream& ostreamAusgabe(ostream&);

	void vInitialisierung();

	string p_sName;

	string getsName()const;

protected:
	
	int p_iID;
	static int p_iMaxID;
	double p_dZeit;
};


ostream& operator << (ostream& out, AktivesVO& x);













#endif