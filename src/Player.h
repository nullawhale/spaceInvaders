#ifndef __PLAYER__
#define __PLAYER__

#include <cmath>
#include "MainConst.h"

class Player{
public:
	Player();
	Player(bool l, int _hp, double _x, double _y, int a);
	void drawPlayer();
	void update(u8 * d);
	void reset(int _x, int _y);

	double x;
	double y;
	double dx;
	double dy;
	double a; // acceleration
	int angle; // angle
	int moving; // 0 - idle; 1 - moving;
	int slowdown;
	int left;	 // 1 - left;
	int right;   // 1 - right;
	bool life;
	int hp;
};

#endif // __PLAYER__
