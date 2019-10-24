#ifndef RECEIVER_H_INCLUDED
#define RECEIVER_H_INCLUDED

#include "systemc.h"
#include "pkt.h"

struct receiver: sc_module {
  sc_in<pkt> pkt_in;  
  sc_in<sc_int<4> > sink_id;  
  int first;
  SC_CTOR(receiver) {
      SC_METHOD(entry); 
      dont_initialize();
      sensitive << pkt_in;
      first = 1;
    }  
 void entry();
};
#endif // RECEIVER_H_INCLUDED
