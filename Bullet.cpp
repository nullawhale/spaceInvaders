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

void Bullet::set_curr_player_cord(double _x, double _y){
	cur_player_x = _x;
	cur_player_y = _y;
}

void Bullet::update(){
	if (active == 1){
		x -= 10 * sin(angle * M_PI / 180);
		y += 10 * cos(angle * M_PI / 180);
	}
	if (x >= WIDTH_D){
		active = 0;
		x = WIDTH_D;
	}
	if (x <= 0){
		active = 0;
		x = 0;
	}
	if (y >= HEIGHT_D){
		active = 0;
		x = cur_player_x;
		y = cur_player_y;
	}
	if (y <= 0){
		active = 0;
		y = 0;
	}
}