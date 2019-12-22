#ifndef __WORLD__
#define __WORLD__

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "LoadTexture.h"

class World {
public:
    World();

    void initWorld();
    void drawWorld();

    map_t map;
    const char* filename;
};

#endif // __WORLD__
