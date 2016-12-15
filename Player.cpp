#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <math.h>
#include "Player.h"
#include "DrawBresenhamLine.h"

Player::Player(double _x, double _y, int a){
	x = _x;
	y = _y;
	angle = a;
}

DrawBresenhamLine dBl;

void Player::drawPlayer(double _x, double _y, int a){
	//dBl.drawPoint(_x, _y);
	glPushMatrix();

	glTranslated(_x, _y, 0);
	glRotated(a, 0, 0, 1);

	glBegin(GL_LINE_STRIP);
		glVertex3f(-5, -5, 0);
		glVertex3f( 0,  5, 0);
		glVertex3f( 5, -5, 0);
		glVertex3f(-5, -5, 0);
	glEnd();

	glPopMatrix();
}