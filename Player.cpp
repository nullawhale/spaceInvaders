#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <math.h>
#include "Player.h"
#include "DrawBresenhamLine.h"
#include "MainConst.h"

Player::Player(){}

Player::Player(double _x, double _y, int a){
	x = _x;
	y = _y;
	angle = a;
}

DrawBresenhamLine dBl;

void Player::drawPlayer(double _x, double _y, int a){
	//dBl.drawPoint(_x, _y);
	int pwh = PLAYER_SIZE;
	glPushMatrix();

	glTranslated(_x, _y, 0);
	glRotated(a, 0, 0, 1);

	glBegin(GL_LINE_STRIP);
		glVertex3f(-pwh, -pwh, 0);
		glVertex3f( 0,    pwh, 0);
		glVertex3f( pwh, -pwh, 0);
		glVertex3f(-pwh+10, -pwh+10, 0);
		glVertex3f(-pwh, -pwh, 0);
	glEnd();

	glPopMatrix();
}

void Player::update(){
	if (x >= WIDTH_D - PLAYER_SIZE){ x = WIDTH_D - PLAYER_SIZE; }
	if (x <= PLAYER_SIZE){ x = PLAYER_SIZE; }
	if (y >= HEIGHT_D - PLAYER_SIZE){ y = HEIGHT_D - PLAYER_SIZE; }
	if (y <= PLAYER_SIZE){ y = PLAYER_SIZE; }
}