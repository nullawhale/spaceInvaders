#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <math.h>
#include "Bullet.h"
#include "DrawBresenhamLine.h"

Bullet::Bullet(double _x, double _y, int a){
	x = _x;
	y = _y;
	angle = a;
}

void Bullet::drawBullet(double _x, double _y){
	
	update();

	glPushMatrix();

	glBegin(GL_POINTS);
		glVertex3f(_x, _y, 0);
	glEnd();

	glPopMatrix();
}

void Bullet::update(){
	x -= 25 * sin(angle * M_PI / 180);
	y += 25 * cos(angle * M_PI / 180);
}