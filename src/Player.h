#ifndef __PLAYER__
#define __PLAYER__

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>
#include "MainConst.h"

class Player{
public:
    Player();
    Player(bool l, int _hp, double _x, double _y, int a);
    void drawPlayer();
    void update(GLFWwindow* window);
    void reset(int _x, int _y);

    double x;
    double y;
    double dx;
    double dy;
    double a; // acceleration
    int angle; // angle
    bool life;
    int hp;
};

#endif // __PLAYER__
