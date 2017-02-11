#ifndef __BULLET__
#define __BULLET__

class Bullet{
public:
	Bullet();
	void drawBullet();
	void update();

	double x;
	double y;
	double dx;
	double dy;
	int angle;
	int active;
};

#endif // __BULLET__