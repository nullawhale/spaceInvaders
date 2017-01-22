#ifndef __PLAYER__
#define __PLAYER__

class Player{
public:
	Player();
	Player(double _x, double _y, int a);	
	void drawPlayer(double x, double y, int a, int moveing);
	void update();

	double x;
	double y;
	int angle;
};

#endif // __PLAYER__
