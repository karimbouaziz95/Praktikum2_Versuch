#include "FzgVerhalten.h"
#include "Weg.h"




FzgVerhalten::FzgVerhalten(Weg * pWeg)
{
	p_pWeg = pWeg;
}

FzgVerhalten::~FzgVerhalten()
{
}


double FzgVerhalten::dGetLimit()
{
	if (p_pWeg == 0)
		return 0.0;
	return p_pWeg->GetLimit();
}
