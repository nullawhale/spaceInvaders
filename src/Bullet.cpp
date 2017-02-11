#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <math.h>
#include "Bullet.h"
#include "DrawBresenhamLine.h"
#include "Player.h"
#include "MainConst.h"

Bullet::Bullet(){}

void Bullet::drawBullet(){
	int bs = BULLET_SIZE;
	
	glPushMatrix();

	glTranslated(x, y, 0);
	glRotated(angle, 0, 0, 1);
	glBegin(GL_LINE_STRIP);
		glColor3d(1, 0, 0);
		glVertex3f(-bs,   -bs,   0);
		glVertex3f( 0,     bs,   0);
		glVertex3f( bs,   -bs,   0);
		glVertex3f(-bs,   -bs,   0);
	glEnd();

	glPopMatrix();
}

void Bullet::update(){
    if(active == 1) {
    	x -= BULLET_SPEED * sin(angle * M_PI / 180);
    	y += BULLET_SPEED * cos(angle * M_PI / 180);
    }

    if (active == 1 && (x >= WIDTH_D || x <= 0 || y >= HEIGHT_D || y <= 0)){
		active = 0;
	}
}