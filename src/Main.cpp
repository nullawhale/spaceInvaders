#include <iostream>
#include <clocale>
#include <cstdio>
#include <cstring>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif
#include "LoadTexture.h"
#include "Player.h"
#include "Bullet.h"
#include "Block.h"
#include "CircleBlock.h"
#include "MainConst.h"
#include "Vec.h"
#include "TestCollisions.cpp"
#include "World.h"

World world;
Player player(true, 50, 15, 15, 0);
std::vector<Bullet> bullets;
std::vector<CircleBlock> blocks;
void initGl() {

}

void drawText(int x, int y, const std::string &text) {
    glColor3f(0.0, 1.0, 0.0);
    glRasterPos2f(x, y);
    for (auto ch : text) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ch);
    }
}

void render() {

    world.drawWorld();

    player.drawPlayer();
    player.block->drawCircleBlock();

    for (auto &b : bullets) {
        b.draw();
        b.block->drawCircleBlock();
    }

    for (auto &bl : blocks) {
        bl.drawCircleBlock();
    }

    auto bulls = std::to_string(bullets.size());
    auto hp = std::to_string(50);
    auto blcks = std::to_string(blocks.size());
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

    world.initWorld();
    blocks.emplace_back(Vec2{200, 200}, 100);
    blocks.emplace_back(Vec2{400, 350}, 30);

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

        bullets.erase(std::remove_if(std::begin(bullets),
                                     std::end(bullets),
                                     [](auto &b) { return !b.active; }),
                      std::end(bullets));

        render();

        for (auto &bl : blocks) {
            if (CircleCircle(bl, *player.block)) {
                player.stop();
            }
            for (auto &b : bullets) {
                if (CircleCircle(bl, *b.block)) {
                    b.active = false;
                    if (bl.r <= 5) bl.active = false;
                    bl.r -= 1;
                }
            }
        }

        blocks.erase(std::remove_if(blocks.begin(), blocks.end(), [](auto &b) { return !b.active; }),
                     blocks.end());

        // std::cout << CircleCircle(circle, *player.block) << std::endl;

        glfwSwapBuffers(window);
    }

    glfwTerminate();

    return 0;
}
