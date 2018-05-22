#include <iostream>
#include <clocale>
#include <cstdio>
#include <cstring>
#include <vector>
#include <sstream>
#include <cmath>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/freeglut.h>
#include "LoadTexture.h"
#include "Player.h"
#include "Bullet.h"
#include "Gun.h"
#include "Block.h"
#include "MainConst.h"
#include "Vec2.h"
#include "TestCollisions.cpp"

struct map_t map;
Player player(true, 50, 15, 15, 0);
std::vector<Bullet> bullets;

void initGl() {

}

void drawText(int x, int y, char *string) {
    glRasterPos2f(x, y);
    int len = (int)strlen(string);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
    }
}

void render() {
    player.drawPlayer();
    for (auto &b : bullets) {
        b.draw();
    }
    char* buff = new char[bullets.size() +1];
    strcpy(buff, std::to_string(bullets.size()).c_str());
    drawText(100, HEIGHT_I-10, buff);
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "");

    GLFWwindow* window;
    glutInit(&argc, argv);
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

        static int oldState = GLFW_RELEASE;
        int newState = glfwGetKey(window, GLFW_KEY_SPACE);
        if (newState == GLFW_RELEASE && oldState == GLFW_PRESS) {
            bullets.push_back(Bullet(player.x, player.y, player.angle));
        }
        oldState = newState;

        for (auto &b : bullets) {
            b.update();
        }

        auto b = std::begin(bullets);
        while (b != std::end(bullets)) {
            if ((*b).active == 0) {
                b = bullets.erase(b);
            } else {
                ++b;
            }
        }

        render();

        glfwSwapBuffers(window);
    }

    glfwTerminate();

    return 0;
}
