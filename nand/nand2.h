#include "systemc.h"
SC_MODULE(nand2)  // creates a class for nand2
{
	sc_in<bool> A,B;   // input and output ports
	sc_out<bool> F;
  /*
	 * In general a port is declared using sc_port
	 * input ports using sc_signal would like
	 * sc_port<sc_signal_in_if<bool>,1> A,B;
	 * the above is a shortcut
	 *
	 * Also note that the port may be of any C++ or
	 * SystemC type
	 */


	void do_nand2() {  // a function
		F.write( !(A.read() && B.read()) );
		/*
		 * Note you can get away without using the read and write
		 * methods the = operator and type conversion operators
		 * are overloaded
		 *
		 * F = !(A&&B) works just as well
		 */
	}
	SC_CTOR(nand2)     // constructor method
	{
		/*
		 * The constructor method does the following
		 * 1. create hierarchy
		 * 2. register function as processes with the simulation kernel
		 * 3. declare sensitivity lists for processes
		 */
		SC_METHOD(do_nand2);  // register do_nand2 with kernel
		sensitive << A << B;  // sensitiviy list
	}
};

