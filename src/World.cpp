#include "World.h"

World::World() {}

void World::initWorld() {
    if (!tex.initTexture("./map.bmp")) {
        printf("Failed to initialize texture when initializing sprite!\n;");
    }
}

void World::drawWorld() {
}
