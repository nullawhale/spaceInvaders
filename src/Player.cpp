#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include "h"

Player::Player() {}

Player::Player(bool l, int _hp, double _x, double _y, int a) {
    life = l;
    hp = _hp;
    x = _x;
    y = _y;
    angle = a;
}

void Player::KeyboardMove(int key, int _x, int _y) {
    switch (key) {
        case GLUT_KEY_LEFT:
            left = 1;
            break;
        case GLUT_KEY_RIGHT:
            right = 1;
            break;
        case GLUT_KEY_UP:
            moving = 1;
            break;
        case GLUT_KEY_DOWN:
            slowdown = 1;
            break;
    }
}

void Player::KeyboardMoveUp(int key, int _x, int _y) {
    switch (key) {
        case GLUT_KEY_LEFT:
            left = 0;
            break;
        case GLUT_KEY_RIGHT:
            right = 0;
            break;
        case GLUT_KEY_UP:
            moving = 0;
            break;
        case GLUT_KEY_DOWN:
            slowdown = 0;
            break;
    }
}

void Player::draw() {
    int ps = SIZE;

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
        if (moving) {
            glVertex3f(-ps/2, -ps/2, 0);
            glColor3f(1.0, 0.0, 0.0);
            glVertex3f(0, -ps*2, 0);
            glColor3f(0.0, 1.0, 0.0);
            glVertex3f(ps/2, -ps/2, 0);
        }
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

void Player::update(u8 * d) {
    if (left) {
        angle += ROTATE_SPEED;
    }
    if (right) {
        angle -= ROTATE_SPEED;
    }
    if (moving) {
        if (a < 1) a += 0.1;
        dx = -a * sin(angle * M_PI / 180);
        dy =  a * cos(angle * M_PI / 180);
    }
    if (slowdown) {
        dx = dy = 0;
        a = 0;
    }

    if (d[(int)(y+dy) * 640 *3 + (int)(x+dx) * 3] == 255) {
        dx = -dx * 0.1;
        dy = -dy * 0.1;
        hp--;
        //life = false;
    } else {
        x += dx;
        y += dy;
    }

    if (hp <= 0) {
        hp = 0;
        life = false;
    }

    if (angle >= 360 || angle <= -360) {
        angle = 0;
    }

    /*
    if (x >= WIDTH_D - SIZE) { x = WIDTH_D - SIZE; }
    if (x <= SIZE) { x = SIZE; }
    if (y >= HEIGHT_D - SIZE) { y = HEIGHT_D - SIZE; }
    if (y <= SIZE) { y = SIZE; }
    */
}
