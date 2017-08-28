#include "Gun.h"

Gun::Gun(){}

void Gun::draw() {
    for (int i = 0; i < MAX_BULLETS_ON_SCREEN; i++) {
        if (bullets[i].active) {
            bullets[i].drawBullet();
        }
    }
}

void Gun::update(GLFWwindow* window, Player player) {
    if (glfwGetKey(window, GLFW_KEY_SPACE)) {
        shoot = true;
    }

    if (shoot) {
        for (int i = 0; i < MAX_BULLETS_ON_SCREEN; i++) {
            if (bullets[i].active == 0) {
                bullets[i].shoot(player.x, player.y, player.angle);
                break;
            }
        }
        shoot = false;
    }

    for (int i = 0; i < MAX_BULLETS_ON_SCREEN; i++) {
        bullets[i].update();
    }
}
