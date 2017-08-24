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
    void KeyboardMove(int key, int _x, int _y);
    void KeyboardMoveUp(int key, int _x, int _y);

    double x;
    double y;
    double dx;
    double dy;
    double a; // acceleration
    int angle; // angle
    bool life;
    int hp;
private:
    int moving;
    int slowdown;
    int left;
    int right;
};

#endif // __PLAYER__
