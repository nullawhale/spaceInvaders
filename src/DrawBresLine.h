#ifndef __DRAW_BRES_LINE__
#define __DRAW_BRES_LINE__

#include "MainConst.h"
#include <vector>

struct pair_t {
	double x, y;
};

std::vector<pair_t> BresLine(double x, double y, double x1, double y1, bool draw=true);

#endif // __DRAW_BRES_LINE__
