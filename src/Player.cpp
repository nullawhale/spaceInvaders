#include <glm/gtx/transform.hpp>
#include "Player.h"

Player::Player() = default;

Player::Player(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3,
               float dx, float dy, float angle,
               float r, float g, float b) {
//    this->x = x;
//    this->y = y;
    this->r = r;
    this->g = g;
    this->b = b;
    vertices[0] = v2 - v1;
    vertices[1] = v3 - v1;
    this->angle = angle;
    this->dx = dx;
    this->dy = dy;
    create();
}

void Player::create() {
    GLfloat vertex_buffer_data[] = {
            0, 0, 0,
            vertices[0][0], vertices[0][1], vertices[0][2],
            vertices[1][0], vertices[1][1], vertices[1][2]
    };

    GLfloat color_buffer_data[] = {
            r, g, b,
            r, g, b,
            r, g, b
    };
    vao = Object::createObject(GL_TRIANGLES, 3, vertex_buffer_data, color_buffer_data, GL_FILL);
}

void Player::draw(glm::mat4 M) {
    Matrices.model = glm::mat4(0.5f);
    glm::mat4 translate = glm::translate(glm::vec3(x, y, 0.0f));
    Matrices.model *= translate;
    glm::mat4 MVP = M * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    Object::drawObject(vao);
}

void Player::update() {
    x += dx;
    y += dy;
}

glm::vec3 Player::get_vertex(int i) {
    return vertices[i];
}

glm::mat4 Player::get_transform(glm::mat4 M) const {
    glm::mat4 translate = glm::translate(glm::vec3(x, y, 0.0f));
    glm::mat4 rotate = glm::rotate((float) (angle * M_PI / 180.0f), glm::vec3(0, 0, 1));
    glm::mat4 transform = translate * rotate;
    return transform * M;
}
