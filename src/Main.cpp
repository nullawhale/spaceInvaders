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
#include "Block.h"
#include "MainConst.h"
#include "Vec2.h"
#include "TestCollisions.cpp"

struct map_t map;
Player player(true, 50, WIDTH_D / 5.5, HEIGHT_D / 5.5, 0);
Gun gun;
Block block(Vec2(50, 50), Vec2(100, 100));
Block block2(Vec2(300, 300), Vec2(400, 400));

void initGl() {

}

void render() {
    player.drawPlayer();
    gun.draw();
    block.drawBlock();
    block2.drawBlock();
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

	std::cout << AABBxAABB(block, block2) << std::endl;

        glfwSwapBuffers(window);
    }

    glfwTerminate();

    return 0;
}

