#ifndef PKT_H_INCLUDED
#define PKT_H_INCLUDED

#include "systemc.h"

struct pkt {
	sc_int<8> data;
	sc_int<4> id;
	bool dest0;
	bool dest1;
	bool dest2;
	bool dest3;

	inline bool operator == (const pkt& rhs) const {
		return (rhs.data == data && rhs.id == id && rhs.dest0 == dest0 && rhs.dest1 == dest1 && rhs.dest2 == dest2 && rhs.dest3 == dest3);
	}

};

inline ostream& operator << ( ostream& os, const pkt& /* a */ ) {
	os << "streaming of struct pkt not implemented";
	return os;
}

inline void
#if defined(SC_API_VERSION_STRING)
sc_trace( sc_trace_file* tf, const pkt& a, const std::string& name )
#else
sc_trace( sc_trace_file* tf, const pkt& a, const sc_string& name )
#endif
{
	sc_trace( tf, a.data, name + ".data" );
	sc_trace( tf, a.id, name + ".id" );
	sc_trace( tf, a.dest0, name + ".dest0" );
	sc_trace( tf, a.dest1, name + ".dest1" );
	sc_trace( tf, a.dest2, name + ".dest2" );
	sc_trace( tf, a.dest3, name + ".dest3" );
}
#endif // PKT_H_INCLUDED
