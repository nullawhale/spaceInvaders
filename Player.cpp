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

void Player::drawPlayer(double _x, double _y, int a, int moveing){
	int ps = PLAYER_SIZE;
	
	glPushMatrix();	
	
	if (moveing){
		glTranslated(_x, _y, 0);
		glRotated(a, 0, 0, 1);
		glBegin(GL_LINE_STRIP);
			glColor3d(1, 1, 1);
			glVertex3f(-ps,    -ps,    0);
			glVertex3f( 0,      ps,    0);
			glVertex3f( ps,    -ps,    0);
			glVertex3f(-ps+ps, -ps+ps, 0);
			glVertex3f(-ps,    -ps,    0);
			glVertex3f(-ps/2,  -ps/2,  0);
			glColor3d(1, 0, 0);
			glVertex3f(0,      -ps*2,    0);
			glColor3d(1, 1, 1);
			glVertex3f(ps/2,   -ps/2,  0);
		glEnd();
	} else {
		glTranslated(_x, _y, 0);
		glRotated(a, 0, 0, 1);
		glBegin(GL_LINE_STRIP);
			glColor3d(1, 1, 1);
			glVertex3f(-ps,    -ps,    0);
			glVertex3f( 0,      ps,    0);
			glVertex3f( ps,    -ps,    0);
			glVertex3f( 0,      0,     0);
			glVertex3f(-ps,    -ps,    0);
		glEnd();
	}
	glPopMatrix();
}

void Player::update(){
	if (x >= WIDTH_D - PLAYER_SIZE){ x = WIDTH_D - PLAYER_SIZE; }
	if (x <= PLAYER_SIZE){ x = PLAYER_SIZE; }
	if (y >= HEIGHT_D - PLAYER_SIZE){ y = HEIGHT_D - PLAYER_SIZE; }
	if (y <= PLAYER_SIZE){ y = PLAYER_SIZE; }
}
