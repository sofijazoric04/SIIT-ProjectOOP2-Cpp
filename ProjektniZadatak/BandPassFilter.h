#pragma once
#include "LowPassFilter.h"
#include "HighPassFilter.h"

class BandPassFilter : 
	public LowPassFilter, public HighPassFilter 
{
};

