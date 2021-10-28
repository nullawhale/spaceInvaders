#ifndef SPACEINVADERS_SHADER_H
#define SPACEINVADERS_SHADER_H

#include "GL/glew.h"

class Shader {
public:
    Shader() = default;

    static GLuint LoadShader(const char *vertex_path, const char *fragment_path);
};

#endif //SPACEINVADERS_SHADER_H
