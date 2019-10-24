#ifndef SWITCH_H_INCLUDED
#define SWITCH_H_INCLUDED

#include "systemc.h"
#include "pkt.h"

struct mcast_pkt_switch : sc_module {

	sc_in<bool>  switch_cntrl;
	sc_in<pkt>  in0;
	sc_in<pkt>  in1;
	sc_in<pkt>  in2;
	sc_in<pkt>  in3;

	sc_out<pkt>  out0;
	sc_out<pkt>  out1;
	sc_out<pkt>  out2;
	sc_out<pkt>  out3;   

	SC_CTOR(mcast_pkt_switch) 
	{
		SC_THREAD(entry);
		sensitive << in0;
		sensitive << in1;
		sensitive << in2;
		sensitive << in3;
		sensitive << switch_cntrl.pos();
	}  

	void entry();  

};
#endif // SWITCH_H_INCLUDED
