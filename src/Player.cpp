#include "Player.h"

Player::Player() {}

Player::Player(bool l, int _hp, double _x, double _y, int a) {
    life = l;
    hp = _hp;
    x = _x;
    y = _y;
    angle = a;
}

void Player::drawPlayer() {
    int ps = PLAYER_SIZE;

    glPushMatrix();

    glTranslated(x, y, 0);
    glRotated(angle, 0, 0, 1);

    glBegin(GL_LINE_STRIP);
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(-ps, -ps, 0);
        glVertex3f(0, ps, 0);
        glVertex3f(ps, -ps, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(-ps, -ps, 0);
        /*if (moving) {
            glVertex3f(-ps/2, -ps/2, 0);
            glColor3f(1.0, 0.0, 0.0);
            glVertex3f(0, -ps*2, 0);
            glColor3f(0.0, 1.0, 0.0);
            glVertex3f(ps/2, -ps/2, 0);
        }*/
    glEnd();

    glPopMatrix();
}

void Player::reset(int _x, int _y){
    hp = 50;
    life = true;
    x = _x;
    y = _y;
    a = 0;
    dx = dy = 0;
}

void Player::update(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_LEFT)) {
        angle -= ROTATE_SPEED;
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT)) {
        angle += ROTATE_SPEED;
    }
    if (glfwGetKey(window, GLFW_KEY_UP)) {
        if (a < 1) a += 0.1;
        dx = -a * sin(angle * M_PI / 180);
        dy =  a * cos(angle * M_PI / 180);
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN)) {
        dx = dy = 0;
        a = 0;
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

    /*
    if (x >= WIDTH_D - SIZE) { x = WIDTH_D - SIZE; }
    if (x <= SIZE) { x = SIZE; }
    if (y >= HEIGHT_D - SIZE) { y = HEIGHT_D - SIZE; }
    if (y <= SIZE) { y = SIZE; }
    */
}
