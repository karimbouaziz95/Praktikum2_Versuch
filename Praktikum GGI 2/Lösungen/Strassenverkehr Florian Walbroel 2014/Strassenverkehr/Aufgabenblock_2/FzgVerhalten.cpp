#pragma once

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "FzgVerhalten.h"
#include "Weg.h"

FzgVerhalten::FzgVerhalten(Weg *WegPointer)
{
	p_ptWeg = WegPointer;
}

