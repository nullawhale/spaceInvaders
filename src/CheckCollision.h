#ifndef SPACEINVADERS_CHECKCOLLISION_H
#define SPACEINVADERS_CHECKCOLLISION_H

#include "Block.h"
#include "CircleBlock.h"

class CheckCollision {
public:
    CheckCollision();

    static bool AABBxAABB(Block a, Block b);

    static bool CircleCircle(const CircleBlock &a, const CircleBlock &b);
};

#endif //SPACEINVADERS_CHECKCOLLISION_H
