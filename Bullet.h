#ifndef __BULLET__
#define __BULLET__

class Bullet{
public:
	Bullet(double _x, double _y, int a);
	void drawBullet(double _x, double _y);
	void update();

	double x;
	double y;
	int angle;
};

#endif // __BULLET__