#ifndef SPACEINVADERS_BULLET_H
#define SPACEINVADERS_BULLET_H

#include "CircleBlock.h"

#include <memory>

class Bullet {
public:
    Bullet(double x, double y, int angle);

    void draw() const;

    void update();

    double x;
    double y;
    int angle;
    double dx;
    double dy;
    bool active;
    int hp{};
    std::unique_ptr<CircleBlock> block;
};

#endif //SPACEINVADERS_BULLET_H
