#ifndef __BULLET__
#define __BULLET__

#include "MainConst.h"

class Bullet{
public:
    Bullet();
    void drawBullet();
    void shoot(double p_x, double p_y, int p_angle);
    void update();

    double x;
    double y;
    double dx;
    double dy;
    int angle;
    int active;
    int hp;
};

#endif // __BULLET__
