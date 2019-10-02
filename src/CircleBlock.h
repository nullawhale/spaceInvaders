#ifndef __CIRCLEBLOCK__
#define __CIRCLEBLOCK__

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include "MainConst.h"
#include "Vec.h"

class CircleBlock{
public:
    CircleBlock();
    ~CircleBlock();
    CircleBlock(Vec2 _center, double _r);
    void drawCircleBlock();
    void update(double _x, double _y, double _r);

    Vec2 center;
    double r;
    int active;
};

#endif // __CIRCLEBLOCK__
