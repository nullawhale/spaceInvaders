#ifndef SPACEINVADERS_WORLD_H
#define SPACEINVADERS_WORLD_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "LoadTexture.h"

class World {
public:
    World();

    void initWorld();

    void drawWorld() const;

    map_t map{};
    const char *filename{};
};

#endif //SPACEINVADERS_WORLD_H
