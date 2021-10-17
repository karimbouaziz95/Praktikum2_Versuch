#pragma once
#include <string>
#include <iostream>

using namespace std;


class AktivesVO
{
public:
	AktivesVO();
	virtual ~AktivesVO(){};
	virtual void vAbfertigung() = 0;
	virtual void vAusgabe();
	virtual ostream& ostreamAusgabe(ostream& Stream);

	string GetName() const;

protected:
	int p_iID;
	static int p_iMaxID;
	string p_sName;
	double p_dZeit;
};

ostream& operator<<(ostream& Stream, AktivesVO& VO);
