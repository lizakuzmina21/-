#pragma once
#include "Trans.h"

class Factory
{
public:
	virtual void create_passenger() = 0;
	virtual void create_truck() = 0;
	virtual void create_tram() = 0;//трамвай
};

