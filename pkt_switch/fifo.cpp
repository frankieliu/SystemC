#undef SC_INCLUDE_FX

#include "fifo.h"

void fifo::pkt_in(const pkt& data_pkt) {
	regs[pntr++] = data_pkt;
	empty = false;
	if (pntr == 4)
		full = true;      
}

pkt fifo::pkt_out() {
	pkt temp;
	temp = regs[0];
	if (--pntr == 0)
		empty = true;
	else { 
		regs[0] = regs[1];
		regs[1] = regs[2];
		regs[2] = regs[3];
	} 
	return(temp);  
}
