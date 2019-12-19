#ifndef __LOAD_TEXTURE__
#define __LOAD_TEXTURE__

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <cstdlib>
#include <cstdio>
#include "MainConst.h"

class LoadTexture {
    public:
        struct map_t {
            GLuint texture;
            u8* data;
            char* name;
        };

        bool initTexture(const char* filename);
        void bindTexture();
};

#endif // __LOAD_TEXTURE__
