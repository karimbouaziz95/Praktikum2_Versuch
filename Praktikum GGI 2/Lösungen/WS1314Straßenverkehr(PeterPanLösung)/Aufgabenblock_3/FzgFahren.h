#pragma once
#include "FzgVerhalten.h"
#include "Weg.h"
class FzgParken;

class FzgFahren : public FzgVerhalten
{

public:
	FzgFahren(void);
	FzgFahren(Weg *way);
	virtual ~FzgFahren(void);
};

