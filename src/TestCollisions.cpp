#include <cmath>
#include "Block.h"
#include "Bullet.h"
#include "CircleBlock.h"

bool AABBxAABB(Block a, Block b) {
    if(a.max.x < b.min.x or a.min.x > b.max.x) return false;
    if(a.max.y < b.min.y or a.min.y > b.max.y) return false;
    return true;
}

bool CircleCircle(CircleBlock a, CircleBlock b) {
    if (pow(b.center.x - a.center.x, 2) + 
        pow(a.center.y - b.center.y, 2) <= pow(a.r + b.r, 2)) {
        return true;
    }
    return false;
}