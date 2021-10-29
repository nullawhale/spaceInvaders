#ifndef SPACEINVADERS_PLAYER_H
#define SPACEINVADERS_PLAYER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>
#include "CircleBlock.h"
#include "Constants.h"

class Player {
public:
    Player();

    Player(bool l, int _hp, double _x, double _y, int a);

    void drawPlayer() const;

    void update(GLFWwindow *window);

    void stop();

    void reset(int _x, int _y);

    double x{};
    double y{};
    double dx{};
    double dy{};
    double velocity{};
    double a{}; // acceleration
    int angle{}; // angle
    bool life{};
    int hp{};
    CircleBlock *block{};
private:
    int angle_tmp{};
};

#endif //SPACEINVADERS_PLAYER_H
