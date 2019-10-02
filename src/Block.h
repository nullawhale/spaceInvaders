#ifndef __BLOCK__
#define __BLOCK__

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include "MainConst.h"
#include "Vec.h"

class Block{
public:
    Block();
    Block(Vec2 _min, Vec2 _max);
    void drawBlock();
    void update(GLFWwindow* window);

    Vec2 min;
    Vec2 max;
};

#endif // __BLOCK__
