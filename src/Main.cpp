#include <iostream>
#include <clocale>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Player.h"
#include "Bullet.h"
#include "CircleBlock.h"
#include "Constants.h"
#include "Vec.h"
#include "CheckCollision.h"
#include "World.h"
#include "Shader.h"

World world;
Player player(true, 50, 15, 15, 0);
std::vector<Bullet> bullets;
std::vector<CircleBlock> blocks;

void initGl() {
    world.filename = "../map.bmp";
    world.initWorld();
}

/*void drawText(int x, int y, const std::string &text) {
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(x, y);
    for (auto ch : text) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ch);
    }
}*/

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
    auto accel = std::to_string(player.a);
//    drawText(100, HEIGHT_I-10, bulls);
//    drawText(150, HEIGHT_I-10, hp);
//    drawText(200, HEIGHT_I-10, "blcks");
//    drawText(100, HEIGHT_I-10, accel.substr(0, accel.find(',')+3));
}

void error_callback(int error, const char *description) {
    fprintf(stderr, "Error (%d): %s\n", error, description);
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

int main(int argc, char **argv) {
    setlocale(LC_ALL, "");

    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        std::cerr << "Can't initialize GLFW" << std::endl;
    }

    glfwDefaultWindowHints();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow *window = glfwCreateWindow(WIDTH_I, HEIGHT_I, "Space Invaders", nullptr, nullptr);
    if (window == nullptr) {
        std::cerr << "Failed to open GLFW  window" << std::endl;
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK) {
        std::cerr << "Can't initialize GLEW" << std::endl;
    }

    int width = WIDTH_I, height = HEIGHT_I;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    Vec3 vertices[6];
    vertices[0] = Vec3(-0.5f, -0.5f, 0.0f);
    vertices[1] = Vec3(0.5f, -0.5f, 0.0f);
    vertices[2] = Vec3(0.5f, 0.5f, 0.0f);

    vertices[3] = Vec3(-0.5f, -0.5f, 0.0f);
    vertices[4] = Vec3(0.5f, 0.5f, 0.0f);
    vertices[5] = Vec3(-0.5f, 0.5f, 0.0f);

    GLuint VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid *) nullptr);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);

    GLuint shaderProgram = Shader::LoadShader("shaders/vertexShader.glsl", "shaders/fragmentShader.glsl");

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glfwSetKeyCallback(window, key_callback);

        glClearColor(0.0, 0.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);

        glBindVertexArray(VAO);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    /*int width = WIDTH_I, height = HEIGHT_I;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, WIDTH_I, HEIGHT_I);
    glOrtho(0, width, height, 0, 0, 1);*/

//    initGl();

    /*blocks.emplace_back(Vec2{200, 200}, 100);
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
            if (CheckCollision::CircleCircle(bl, *player.block)) {
                player.stop();
            }
            for (auto &b : bullets) {
                if (CheckCollision::CircleCircle(bl, *b.block)) {
                    b.active = false;
                    if (bl.r <= 5) bl.active = false;
                    bl.r -= 1;
                }
            }
        }

        blocks.erase(
                std::remove_if(
                        blocks.begin(),
                        blocks.end(),
                        [](auto &b) {
                            return !b.active;
                        }),
                blocks.end());

        // std::cout << CircleCircle(circle, *player.block) << std::endl;

        glfwSwapBuffers(window);
    }*/

    glfwTerminate();

    return 0;
}
