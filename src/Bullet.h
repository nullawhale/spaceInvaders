#ifndef __BULLET__
#define __BULLET__

#include "MainConst.h"

class Bullet{
public:
	Bullet();
	void drawBullet();
	void update(u8 * d);

	double x;
	double y;
	double dx;
	double dy;
	int angle;
	int active;
};

#endif // __BULLET__