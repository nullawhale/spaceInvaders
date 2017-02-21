#ifndef __PLAYER__
#define __PLAYER__

#include "MainConst.h"

class Player{
public:
	Player();
	Player(double _x, double _y, int a);	
	void drawPlayer();
	void update(u8 * d);

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
};

#endif // __PLAYER__
