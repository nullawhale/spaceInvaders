#ifndef __BLOCK__
#define __BLOCK__

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Vec.h"

class Block{
public:
    Block(Vec2 min, Vec2 max);
    void drawBlock();
    void update(GLFWwindow* window);

    Vec2 min;
    Vec2 max;
};

#endif // __BLOCK__
