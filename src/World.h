#ifndef __WORLD__
#define __WORLD__

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "LoadTexture.h"

class World {
public:
    World(map_t _map);
    void drawWorld();

    map_t map;
};

#endif // __WORLD__
