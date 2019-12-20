#ifndef __WORLD__
#define __WORLD__

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "LoadTexture.h"

class World {
public:
    World();
    // World(map_t);
    void initWorld();
    void drawWorld();

    LoadTexture tex;
};

#endif // __WORLD__
