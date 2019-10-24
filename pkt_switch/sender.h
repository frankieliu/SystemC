#ifndef SENDER_H_INCLUDED
#define SENDER_H_INCLUDED

#include "systemc.h"
#include "pkt.h"

struct sender: sc_module {
  sc_out<pkt> pkt_out; 
  sc_in<sc_int<4> > source_id;       
  sc_in_clk CLK;

  SC_CTOR(sender)
    {
      SC_CTHREAD(entry, CLK.pos()); 
     }  
  void entry();
};
#endif // SENDER_H_INCLUDED
