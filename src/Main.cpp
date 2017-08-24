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
Bullet bullets_p[MAX_BULLETS_ON_SCREEN];

int main(int argc, char** argv) {
    setlocale(LC_ALL, "");

    GLFWwindow* window;

    if (!glfwInit()) return -1;

    window = glfwCreateWindow(WIDTH_I, HEIGHT_I, "Space Invasers", NULL, NULL);

    glfwMakeContextCurrent(window);

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    do {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    while (glfwGetKey(window, GLFW_KEY_Q) != GLFW_PRESS && glfwWindowShouldClose(window) == 0 );

    return 0;
}

