
#include "Object.h"

VAO *Object::createObject(GLenum primitive_mode,
                          int numVertices,
                          const GLfloat *vertex_buffer_data,
                          const GLfloat *color_buffer_data, GLenum fill_mode) {

    struct VAO *vao = new VAO;
    vao->PrimitiveMode = primitive_mode;
    vao->NumVertices = numVertices;
    vao->FillMode = fill_mode;

    glGenVertexArrays(1, &(vao->VertexArrayID));
    glGenBuffers(1, &(vao->VertexBuffer));
    glGenBuffers(1, &(vao->ColorBuffer));

    glBindVertexArray(vao->VertexArrayID);
    glBindBuffer(GL_ARRAY_BUFFER, vao->VertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, 3 * numVertices * sizeof(GLfloat), vertex_buffer_data, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *) nullptr);

    glBindBuffer(GL_ARRAY_BUFFER, vao->ColorBuffer);
    glBufferData(GL_ARRAY_BUFFER, 3 * numVertices * sizeof(GLfloat), color_buffer_data, GL_STATIC_DRAW);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void *) nullptr);

    return vao;
}

VAO *Object::createObject(GLenum primitive_mode,
                          int numVertices,
                          const GLfloat *vertex_buffer_data,
                          const GLfloat red,
                          const GLfloat green,
                          const GLfloat blue,
                          GLenum fill_mode) {
    auto *color_buffer_data = new GLfloat[3 * numVertices];
    for (int i = 0; i < numVertices; i++) {
        color_buffer_data[3 * i] = red;
        color_buffer_data[3 * i + 1] = green;
        color_buffer_data[3 * i + 2] = blue;
    }

    return Object::createObject(primitive_mode, numVertices, vertex_buffer_data, color_buffer_data, fill_mode);
}

void Object::drawObject(VAO *vao) {
    glPolygonMode(GL_FRONT_AND_BACK, vao->FillMode);

    glBindVertexArray(vao->VertexArrayID);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vao->VertexBuffer);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, vao->ColorBuffer);

    glDrawArrays(vao->PrimitiveMode, 0, vao->NumVertices);
}


