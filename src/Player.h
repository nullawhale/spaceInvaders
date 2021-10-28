#ifndef SPACEINVADERS_PLAYER_H
#define SPACEINVADERS_PLAYER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>
#include <glm/glm.hpp>
#include "CircleBlock.h"
#include "Constants.h"
#include "Object.h"

class Player {
public:
    Player();

    Player(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3,
           float dx, float dy, float angle,
           float r, float g, float b);

    void create();

    void draw(glm::mat4 M);

    void update();

    glm::vec3 get_vertex(int i);

    glm::mat4 get_transform(glm::mat4 M) const;

//    void reset(int _x, int _y);

private:
    int angle_tmp{};
    glm::vec3 vertices[2]{};
    VAO *vao{};
    float x{};
    float y{};
    float dx{};
    float dy{};
    float angle{};
    float r{};
    float g{};
    float b{};
};

#endif //SPACEINVADERS_PLAYER_H
