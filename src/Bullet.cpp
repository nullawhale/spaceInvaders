#include "Bullet.h"

Bullet::Bullet(){}

Bullet::Bullet(double p_x, double p_y, int p_angle) {
    active = 1;
    x = p_x;
    y = p_y;
    angle = p_angle;
    dx = -BULLET_SPEED * sin(p_angle * M_PI / 180);
    dy =  BULLET_SPEED * cos(p_angle * M_PI / 180);
    block = new CircleBlock(Vec2(p_x, p_y), BULLET_SIZE);
}

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
    if (active == 1) {
        x += dx;
        y += dy;
        block->update(x, y, block->r);
    }

    if (active == 1 && (x >= WIDTH_I || x <= 0 || y >= HEIGHT_I || y <= 0)) {
        active = 0;
    }
}
