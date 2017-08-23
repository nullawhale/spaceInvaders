#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include "Player.h"

Player::Player() {}

Player::Player(bool l, int _hp, double _x, double _y, int a) {
	life = l;
	hp = _hp;
	x = _x;
	y = _y;
	angle = a;
}

void Player::drawPlayer() {
	int ps = PLAYER_SIZE;

	glPushMatrix();

	glTranslated(x, y, 0);
	glRotated(angle, 0, 0, 1);

        glBegin(GL_LINE_STRIP);
            glColor3f(0.0, 1.0, 0.0);
            glVertex3f(-ps, -ps, 0);
            glVertex3f(0, ps, 0);
            glVertex3f(ps, -ps, 0);
            glVertex3f(0, 0, 0);
            glVertex3f(-ps, -ps, 0);
            if (moving) {
                glVertex3f(-ps/2, -ps/2, 0);
                glColor3f(1.0, 0.0, 0.0);
                glVertex3f(0, -ps*2, 0);
                glColor3f(0.0, 1.0, 0.0);
                glVertex3f(ps/2, -ps/2, 0);
            }
        glEnd();

	glPopMatrix();
}

void Player::reset(int _x, int _y){
	hp = 50;
	life = true;
	x = _x;
	y = _y;
	a = 0;
	dx = dy = 0;
}

void Player::update(u8 * d) {
	if (left) {
		angle += ROTATE_SPEED;
	}
	if (right) {
		angle -= ROTATE_SPEED;
	}
	if (moving) {
		if (a < 1) a += 0.1;
		dx = -a * sin(angle * M_PI / 180);
		dy =  a * cos(angle * M_PI / 180);
	}
	if (slowdown) {
		dx = dy = 0;
		a = 0;
	}

	if (d[(int)(y+dy) * 640 *3 + (int)(x+dx) * 3] == 255) {
		dx = -dx * 0.1;
		dy = -dy * 0.1;
		hp--;
		//life = false;
	} else {
		x += dx;
		y += dy;
	}

	if (hp <= 0) {
		hp = 0;
		life = false;
	}

	if (angle >= 360 || angle <= -360) {
		angle = 0;
	}

	/*
	if (x >= WIDTH_D - PLAYER_SIZE) { x = WIDTH_D - PLAYER_SIZE; }
	if (x <= PLAYER_SIZE) { x = PLAYER_SIZE; }
	if (y >= HEIGHT_D - PLAYER_SIZE) { y = HEIGHT_D - PLAYER_SIZE; }
	if (y <= PLAYER_SIZE) { y = PLAYER_SIZE; }
	*/
}
