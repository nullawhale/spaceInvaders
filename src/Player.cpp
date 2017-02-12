#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include "Player.h"
#include "DrawBresLine.h"
#include "MainConst.h"

Player::Player() {}

Player::Player(double _x, double _y, int a) {
	x = _x;
	y = _y;
	angle = a;
}

void Player::drawPlayer() {
	int ps = PLAYER_SIZE;
	
	glPushMatrix();
	
	glTranslated(x, y, 0);
	glRotated(angle, 0, 0, 1);

	glColor3f(1.0, 1.0, 1.0);
	DrawBresLine(-ps, -ps, 0, ps);
	DrawBresLine(0, ps, ps, -ps);
	DrawBresLine(ps, -ps, 0, 0);
	DrawBresLine(0, 0, -ps, -ps);
	if (moving) {
		glColor3f(1.0, 0.0, 0.0);
		DrawBresLine(-ps/2, -ps/2, 0, -ps*2);
		DrawBresLine(0, -ps*2, ps/2, -ps/2);
	}
	
	glPopMatrix();
}

void Player::update() {
	if (x >= WIDTH_D - PLAYER_SIZE) { x = WIDTH_D - PLAYER_SIZE; }
	if (x <= PLAYER_SIZE) { x = PLAYER_SIZE; }
	if (y >= HEIGHT_D - PLAYER_SIZE) { y = HEIGHT_D - PLAYER_SIZE; }
	if (y <= PLAYER_SIZE) { y = PLAYER_SIZE; }
}
