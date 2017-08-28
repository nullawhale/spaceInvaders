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
#include "Gun.h"
#include "MainConst.h"

struct map_t map;
Player player(true, 50, WIDTH_D / 5.5, HEIGHT_D / 5.5, 0);
Gun gun;

void initGl() {

}

void render() {
    player.drawPlayer();
    gun.draw();
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
        gun.update(window, player);

        render();

        glfwSwapBuffers(window);
    }

    glfwTerminate();

    return 0;
}

