#include "receiver.h"

void receiver::entry() {
	pkt temp_val;
	// Ignore the first packet arriving on start-on
	if (first == 1) {first = 0;}
	else {
		temp_val = pkt_in.read();
		cout << "                                  .........................." << endl;
		cout << "                                  New Packet Received" << endl;
		cout << "                                  Receiver ID: " << (int)sink_id.read() + 1 << endl;
		cout << "                                  Packet Value: " << (int)temp_val.data << endl;
		cout << "                                  Sender ID: " << (int)temp_val.id + 1 << endl;
		cout << "                                  .........................." << endl;
	} 

}
