#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <math.h>
#include <cstdio>
#include <vector>
#include "Bullet.h"

Bullet::Bullet(){}

void Bullet::drawBullet(){
    glPushMatrix();

    glTranslated(x, y, 0);
    glRotated(angle, 0, 0, 1);

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
        glVertex3f(0, 0, 0.0);
    glEnd();

    glPopMatrix();
}

void Bullet::shoot(double p_x, double p_y, int p_angle){
    active = 1;
    x = p_x;
    y = p_y;
    angle = p_angle;
    hp = 2;
    dx = -BULLET_SPEED * sin(p_angle * M_PI / 180);
    dy =  BULLET_SPEED * cos(p_angle * M_PI / 180);
}

void Bullet::update(u8 * d){
    if (active == 1) {
        x += dx;
        y += dy;
    }

    if (d[(int)y * 640 *3 + (int)x * 3] == 255){
        dx = -dx;
        dy = -dy;
        if (hp > 0) hp--;
    }

    if (hp == 0){
        active = 0;
    }
}
