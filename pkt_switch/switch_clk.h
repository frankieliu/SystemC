#ifndef SWITCH_CLK_H_INCLUDED
#define SWITCH_CLK_H_INCLUDED

#include "systemc.h"

struct switch_clk: sc_module {
	sc_out<bool>   switch_cntrl;
	sc_in_clk CLK;

	SC_CTOR(switch_clk) {
		SC_METHOD(entry);
		dont_initialize();
		sensitive << CLK.pos(); 
	}
	void entry();
};
#endif // SWITCH_CLK_H_INCLUDED
