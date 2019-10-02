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
#include "Block.h"
#include "CircleBlock.h"
#include "MainConst.h"
#include "Vec2.h"
#include "Vec3.h"
#include "TestCollisions.cpp"

struct map_t map;
Player player(true, 50, 15, 15, 0);
std::vector<Bullet> bullets;
std::vector<CircleBlock*> blocks;
// CircleBlock* circle = new CircleBlock(Vec2(200, 200), 100);
void initGl() {

}

void drawText(int x, int y, char *string) {
    glColor3f(0.0, 1.0, 0.0);
    glRasterPos2f(x, y);
    int len = (int)strlen(string);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
    }
}

void render() {
    player.drawPlayer();
    player.block->drawCircleBlock();

    for (auto &b : bullets) {
        b.draw();
        b.block->drawCircleBlock();
    }

    for (auto &bl : blocks) {
        bl->drawCircleBlock();
    }

    char* bulls = new char[bullets.size() +1];
    strcpy(bulls, std::to_string(bullets.size()).c_str());
    char* hp = new char[3];
    strcpy(hp, "50");
    char* blcks = new char[blocks.size() +1];
    strcpy(blcks, std::to_string(blocks.size()).c_str());
    drawText(100, HEIGHT_I-10, bulls);
    drawText(150, HEIGHT_I-10, hp);
    drawText(200, HEIGHT_I-10, blcks);
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

    blocks.push_back(new CircleBlock({200, 200}, 100));
    blocks.push_back(new CircleBlock({400, 350}, 30));

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
        oldState = newState;

        auto b = std::begin(bullets);
        while (b != std::end(bullets)) {
            if ((*b).active == 0) {
                b = bullets.erase(b);
            } else {
                ++b;
            }
        }

        render();

        for (auto &bl : blocks) {
            if (CircleCircle(*bl, *player.block)) {
                player.stop();
            }
            for (auto &b : bullets) {
                if (CircleCircle(*bl, *b.block)) {
                    b.active = 0;
                    if (bl->r <= 5) bl->active = 0;
                    bl->r -= 1;
                }
            }
        }

        for (auto it = blocks.begin(); it != blocks.end();) {
            if ((*it)->active == 0) {
                it = blocks.erase(it);
            } else {
                ++it;
            }
        }

        // std::cout << CircleCircle(circle, *player.block) << std::endl;

        glfwSwapBuffers(window);
    }

    glfwTerminate();

    return 0;
}
