#ifndef __BULLET__
#define __BULLET__

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <cstdio>
#include <vector>
#include "CircleBlock.h"
#include "MainConst.h"

class Bullet{
public:
    Bullet();
    Bullet(double p_x, double p_y, int p_angle);
    void draw();
    void update();

    double x;
    double y;
    double dx;
    double dy;
    int angle;
    int active;
    int hp;
    CircleBlock* block;
};

#endif // __BULLET__
