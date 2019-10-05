#ifndef __CIRCLEBLOCK__
#define __CIRCLEBLOCK__

#include "Vec.h"

class CircleBlock{
public:
    CircleBlock(Vec2 center, double r);
    void drawCircleBlock();
    void update(double _x, double _y, double _r);

    Vec2 center;
    double r;
    bool active;
};

#endif // __CIRCLEBLOCK__
