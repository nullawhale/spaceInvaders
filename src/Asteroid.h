#ifndef __ASTEROID__
#define __ASTEROID__

#include "MainConst.h"

class Asteroid{
public:
	Asteroid();
	void drawAsteroid();
	void update();

	double x;
	double y;
	double dx;
	double dy;
	int angle;
	int life;
};

#endif // __BULLET__