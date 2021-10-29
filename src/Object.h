#ifndef SPACEINVADERS_OBJECT_H
#define SPACEINVADERS_OBJECT_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Vec.h"

class Object {
public:
    Object() = default;

    static VAO *createObject(GLenum primitive_mode,
                             int numVertices,
                             const GLfloat *vertex_buffer_data,
                             const GLfloat *color_buffer_data, GLenum fill_mode);

    static VAO *createObject(GLenum primitive_mode,
                             int numVertices,
                             const GLfloat *vertex_buffer_data,
                             GLfloat red,
                             GLfloat green,
                             GLfloat blue,
                             GLenum fill_mode);

    static void drawObject(VAO *vao);
};

#endif //SPACEINVADERS_OBJECT_H
