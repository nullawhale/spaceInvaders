#include <cmath>
#include "Block.h"
#include "CircleBlock.h"
#include "CheckCollision.h"

CheckCollision::CheckCollision() = default;

bool CheckCollision::AABBxAABB(Block a, Block b) {
    if (a.max.x < b.min.x or a.min.x > b.max.x)
        return false;
    if (a.max.y < b.min.y or a.min.y > b.max.y)
        return false;
    return true;
}

bool CheckCollision::CircleCircle(const CircleBlock &a, const CircleBlock &b) {
    return pow(b.center.x - a.center.x, 2) +
           pow(a.center.y - b.center.y, 2) <= pow(a.r + b.r, 2);
}
