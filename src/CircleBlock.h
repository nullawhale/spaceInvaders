#ifndef SPACEINVADERS_CIRCLEBLOCK_H
#define SPACEINVADERS_CIRCLEBLOCK_H

#include "Vec.h"

class CircleBlock {
public:
    CircleBlock(Vec2 center, double r);

    void drawCircleBlock() const;

    void update(double _x, double _y, double _r);

    Vec2 center;
    double r;
    bool active;
};

#endif //SPACEINVADERS_CIRCLEBLOCK_H
