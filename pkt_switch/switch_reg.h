#ifndef SWITCH_REG_H_INCLUDED
#define SWITCH_REG_H_INCLUDED

#include "pkt.h"

struct switch_reg {
	pkt val;
	bool free;

	// constructor
	switch_reg()    
	{
		free = true;
	}
};

#endif // SWITCH_REG_H_INCLUDED
