#ifndef __BULLET__
#define __BULLET__

class Bullet{
public:
	Bullet();
	Bullet(double _x, double _y, int a, int _active);
	void drawBullet(double _x, double _y, int a);
	void updateCord();
	void update();
	void set_curr_player_cord(double _x, double _y);

	double x;
	double y;
	int angle;
	int active;

private:
	double cur_player_x;
	double cur_player_y;
};

#endif // __BULLET__