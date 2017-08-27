#include <iostream>
#include <clocale>
#include <cstdio>
#include <string>
#include <sstream>
#include <cmath>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "LoadTexture.h"
#include "Player.h"
#include "Bullet.h"
#include "MainConst.h"

struct map_t map;
Player player(true, 50, WIDTH_D / 5.5, HEIGHT_D / 5.5, 0);
Bullet bullets[MAX_BULLETS_ON_SCREEN];
static bool shoot_p = false;

void initGl() {

}

void render() {
    player.drawPlayer();
    for (int i = 0; i < MAX_BULLETS_ON_SCREEN; i++) {
        if (bullets[i].active) {
            bullets[i].drawBullet();
        }
    }
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "");

    GLFWwindow* window;
    if (!glfwInit()) return -1;
    window = glfwCreateWindow(WIDTH_I, HEIGHT_I, "Space Invasers", NULL, NULL);
    glfwMakeContextCurrent(window);
    int width = WIDTH_I, height = HEIGHT_I;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, WIDTH_I, HEIGHT_I);
    glOrtho(0, width, height, 0, 0, 1);

    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();

        player.update(window);

        if (glfwGetKey(window, GLFW_KEY_SPACE)) {
            shoot_p = true;
        }

        if (shoot_p) {
            for (int i = 0; i < MAX_BULLETS_ON_SCREEN; i++) {
                if (bullets[i].active == 0) {
                    bullets[i].shoot(player.x, player.y, player.angle);
                    break;
                }
            }
            shoot_p = false;
        }

        for (int i = 0; i < MAX_BULLETS_ON_SCREEN; i++) {
            bullets[i].update();
        }

        render();

        glfwSwapBuffers(window);
    }

    glfwTerminate();

    return 0;
}

