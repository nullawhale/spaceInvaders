#include "Bullet.h"
#include "MainConst.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <cmath>
#include <memory>

Bullet::Bullet(double x, double y, int angle) :
    x{x},
    y{y},
    angle{angle},
    dx{-BULLET_SPEED * std::sin(angle * M_PI / 180)},
    dy{ BULLET_SPEED * std::cos(angle * M_PI / 180)},
    active{true},
    block{std::make_unique<CircleBlock>(Vec2{x, y}, BULLET_SIZE)} {}

void Bullet::draw() {
    glPushMatrix();

    glTranslated(x, y, 0);
    glRotated(angle, 0, 0, 1);

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
        glVertex3f(0, 0, 0.0);
    glEnd();

    glPopMatrix();
}

void Bullet::update() {
    if (active) {
        x += dx;
        y += dy;
        block->update(x, y, block->r);
    }

    if (active && (x >= WIDTH_I || x <= 0 || y >= HEIGHT_I || y <= 0)) {
        active = false;
    }
}
