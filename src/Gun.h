#ifndef __GUN__
#define __GUN__

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include "MainConst.h"
#include "Bullet.h"
#include "Player.h"

class Gun {
public:
    Gun();
    void draw();
    void update(GLFWwindow* window, Player player);

private:
    bool shoot;
    //std::vector<Bullet> bullets;
    Bullet bullets[MAX_BULLETS_ON_SCREEN];
};

#endif // __GUN__
