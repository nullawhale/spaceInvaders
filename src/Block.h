#ifndef SPACEINVADERS_BLOCK_H
#define SPACEINVADERS_BLOCK_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Vec.h"

class Block {
public:
    Block(Vec2 min, Vec2 max);

    void drawBlock() const;

    void update(GLFWwindow *window);

    Vec2 min;
    Vec2 max;
};

#endif //SPACEINVADERS_BLOCK_H
