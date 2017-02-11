#ifndef __ASTEROID__
#define __ASTEROID__

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