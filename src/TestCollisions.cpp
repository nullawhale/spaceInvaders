#include "Block.h"

bool AABBxAABB(Block a, Block b) {
    if(a.max.x < b.min.x or a.min.x > b.max.x) return false;
    if(a.max.y < b.min.y or a.min.y > b.max.y) return false;
    return true;
}
