#ifndef __BULLET__
#define __BULLET__

class Bullet{
public:
	Bullet();
	Bullet(double _x, double _y, int a, int _active);
	void drawBullet(double _x, double _y, int a);
	void updateCord();
	void update(double _x, double _y);
	void set_curr_player_cord(double _x, double _y);

	double x;
	double y;
	int angle;
	int active;
};

#endif // __BULLET__