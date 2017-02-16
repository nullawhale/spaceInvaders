#ifndef __LOAD_TEXTURE__
#define __LOAD_TEXTURE__

struct Pekish {
    GLuint texture;
    unsigned char ** data;
    unsigned int width, height;
};

struct Pekish LoadTexture(const char* filename);

#endif // __LOAD_TEXTURE__
