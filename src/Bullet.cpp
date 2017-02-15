#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <math.h>
#include <stdio.h>
#include "Bullet.h"
#include "DrawBresLine.h"
#include "MainConst.h"

Bullet::Bullet(){}

void Bullet::drawBullet(){
	int bs = BULLET_SIZE;
	
	glPushMatrix();

	glTranslated(x, y, 0);
	glRotated(angle, 0, 0, 1);

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
		glVertex3f(bs, bs, 0.0);
	glEnd();
//	DrawBresLine(bs/2, bs/2, bs+5, bs+5);
//	DrawBresLine(-bs, -bs, 0, bs);
//	DrawBresLine(0, bs, bs, -bs);
//	DrawBresLine(bs, -bs, -bs, -bs);

	glPopMatrix();
}

void Bullet::update(unsigned char ** d){
    if(active == 1) {
    	x -= BULLET_SPEED * sin(angle * M_PI / 180);
    	y += BULLET_SPEED * cos(angle * M_PI / 180);
    }

    if (active == 1 && (x >= WIDTH_D || x <= 0 || y >= HEIGHT_D || y <= 0)){
		active = 0;
	}

	if (d[(int)x][(int)y] == 255){
		active = 0;
	}
}
