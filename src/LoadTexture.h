#ifndef SPACEINVADERS_LOADTEXTURE_H
#define SPACEINVADERS_LOADTEXTURE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdio>
#include "Constants.h"

struct map_t {
    GLuint texture;
    u8 *data;
    char *name;
};

struct map_t LoadTexture(const char* filename);

#endif //SPACEINVADERS_LOADTEXTURE_H
