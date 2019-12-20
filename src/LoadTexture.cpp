#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include "LoadTexture.h"


bool LoadTexture::initTexture(const char* filename) {

    unsigned char* data = stbi_load(filename, &width, &height, &nrChannels, STBI_rgb_alpha);

    if (!data) {
        printf("Failed to load image from %s\n", filename);
        return false;
    }

    glCreateTextures(GL_TEXTURE_2D, 1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    stbi_image_free(data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glGenerateMipmap(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, 0);

    return true;
}

void LoadTexture::bindTexture() {
    glBindTexture(GL_TEXTURE_2D, texture);
}

