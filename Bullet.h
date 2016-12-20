#ifndef __BULLET__
#define __BULLET__

class Bullet{
public:
	Bullet();
	Bullet(double _x, double _y, int a, int _active);
	void drawBullet(double _x, double _y, int a);
	void update(double _x, double _y, int a);

	double x;
	double y;
	int angle;
	int active;
};

#endif // __BULLET__