#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <math.h>
#include "Bullet.h"
#include "DrawBresenhamLine.h"
#include "Player.h"
#include "MainConst.h"

Bullet::Bullet(){}

Bullet::Bullet(double _x, double _y, int a, int _active){
	x = _x;
	y = _y;
	angle = a;
	active = _active;
}

void Bullet::drawBullet(double _x, double _y, int a){
	if (active != 1) angle = a;
	
	glPushMatrix();

	glBegin(GL_POINTS);
		glVertex3f(_x, _y, 0);
	glEnd();

	glPopMatrix();
}

void Bullet::update(double _x, double _y){
	if (active == 1){
		x -= 10 * sin(angle * M_PI / 180);
		y += 10 * cos(angle * M_PI / 180);
	}
	if (x >= WIDTH_D || x <= 0 || y >= HEIGHT_D || y <= 0){
		active = 0;
		x = _x;
		y = _y;
	}
}