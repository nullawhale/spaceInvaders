#ifndef __LOAD_TEXTURE__
#define __LOAD_TEXTURE__

#include "MainConst.h"

struct map_t {
    GLuint texture;
    u8* data;
    char* name;
};

struct map_t LoadTexture(const char* filename);

#endif // __LOAD_TEXTURE__
