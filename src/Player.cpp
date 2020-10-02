#include "Player.h"

Player::Player() = default;

Player::Player(bool l, int _hp, double _x, double _y, int a) {
    life = l;
    hp = _hp;
    x = _x;
    y = _y;
    angle = a;
    block = new CircleBlock({_x, _y}, PLAYER_SIZE);
}

void Player::drawPlayer() const {
    int ps = PLAYER_SIZE;

    glPushMatrix();

    glTranslated(x, y, 0);
    glRotated(angle, 0, 0, 1);

    glBegin(GL_LINE_STRIP);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-ps, -ps, 0);
    glVertex3f(0, ps, 0);
    glVertex3f(ps, -ps, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(-ps, -ps, 0);
    glEnd();

    glPopMatrix();
}

void Player::reset(int _x, int _y) {
    hp = 50;
    life = true;
    x = _x;
    y = _y;
    a = 0;
    dx = dy = 0;
}

void Player::stop() {
    // dx = dy = 0;
    a = 0;
    x -= dx; y -= dy;
}

void Player::update(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_LEFT)) {
        angle -= ROTATE_SPEED;
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT)) {
        angle += ROTATE_SPEED;
    }
    if (glfwGetKey(window, GLFW_KEY_UP)) {
        angle_tmp = angle;
        if (a < 1) a += 0.05;
        dx = -a * sin(angle * M_PI / 180);
        dy =  a * cos(angle * M_PI / 180);
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN)) {
        if (a > 0) a -= 0.05;
        dx = -a * sin(angle_tmp * M_PI / 180);
        dy =  a * cos(angle_tmp * M_PI / 180);
    }

    if (hp <= 0) {
        hp = 0;
        life = false;
    }

    if (angle >= 360 || angle <= -360) {
        angle = 0;
    }

    x += dx;
    y += dy;
    block->update(x, y, block->r);

    if (x >= WIDTH_D - PLAYER_SIZE) { x = WIDTH_D - PLAYER_SIZE; }
    if (x <= PLAYER_SIZE) { x = PLAYER_SIZE; }
    if (y >= HEIGHT_D - PLAYER_SIZE) { y = HEIGHT_D - PLAYER_SIZE; }
    if (y <= PLAYER_SIZE) { y = PLAYER_SIZE; }
}
