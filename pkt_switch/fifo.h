#ifndef FIFO_H_INCLUDED
#define FIFO_H_INCLUDED

#include "systemc.h"
#include "pkt.h"

struct fifo {
  pkt regs[4];
	bool full;
	bool empty;
	sc_uint<3> pntr;

	// constructor
	fifo() {
		full = false;
		empty = true;
		pntr = 0;
	}

	// methods
	void pkt_in(const pkt& data_pkt);
	pkt pkt_out();
};
#endif // FIFO_H_INCLUDED
