#include "switch_clk.h"

void switch_clk::entry() {
	static bool var_switch_cntrl = false;
	{
		switch_cntrl = var_switch_cntrl;
		var_switch_cntrl = !var_switch_cntrl;
	}
}

