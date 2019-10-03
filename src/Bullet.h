#ifndef __BULLET__
#define __BULLET__

#include "CircleBlock.h"

#include <memory>

class Bullet {
public:
    Bullet(double x, double y, int angle);
    void draw();
    void update();

    double x;
    double y;
    int angle;
    double dx;
    double dy;
    bool active;
    int hp;
    std::unique_ptr<CircleBlock> block;
};

#endif // __BULLET__
