#ifndef __BULLET__
#define __BULLET__

class Bullet{
public:
	Bullet();
	void drawBullet();
	void update(unsigned char ** d);

	double x;
	double y;
	double dx;
	double dy;
	int angle;
	int active;
};

#endif // __BULLET__