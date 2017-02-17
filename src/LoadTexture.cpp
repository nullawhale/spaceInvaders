#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <cstdio>
#include "LoadTexture.h"

#pragma pack(push, 1)
struct header_t
{
    u8 field[2];
    u32 size;
    u16 reserved1, reserved2;
    u32 data_offset;
};

struct info_header_t
{
    u32 header_size;
    int width;
    int height;
    u16 planes;
    u16 bits_per_pixel;
    u32 compression_method;
    u32 size;
    int h_resolution;
    int v_resolution;
    u32 number_of_colors;
    u32 number_of_important_colors;
};
#pragma pack(pop)

struct map_t LoadTexture(const char* filename){
    struct map_t map;
    map.name = (char*)filename;

    FILE* file = fopen(filename, "rb");

    struct header_t header;
    fread(&header, sizeof(header), 1, file);

    struct info_header_t info_header;
    fread(&info_header, sizeof(info_header), 1, file);

    map.data = new u8[info_header.size];
    fseek(file, header.data_offset, SEEK_SET);

    fread(map.data, 1, info_header.size, file);

    fclose(file);

    glGenTextures(1, &map.texture);

    glBindTexture(GL_TEXTURE_2D, map.texture);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, info_header.width, info_header.height, 0, GL_BGR, GL_UNSIGNED_BYTE, map.data);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); //TODO: Understand how it works!
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    return map;
}
