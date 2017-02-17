#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <math.h>
#include <cstdio>
#include <vector>
#include "Bullet.h"
#include "DrawBresLine.h"

Bullet::Bullet(){}

void Bullet::drawBullet(){
	//int bs = BULLET_SIZE;
	
	glPushMatrix();

	glTranslated(x, y, 0);
	glRotated(angle, 0, 0, 1);

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
		glVertex3f(0, 0, 0.0);
	glEnd();
// 	BresLine(-bs, -bs, 0, bs);
// 	BresLine(0, bs, bs, -bs);
// 	BresLine(bs, -bs, -bs, -bs);

	glPopMatrix();
}

void Bullet::update(u8 * d){
    dx = BULLET_SPEED * sin(angle * M_PI / 180);
    dy = BULLET_SPEED * cos(angle * M_PI / 180);

    int tmp_x, tmp_y;

    tmp_x = x;
    x -= dx;

    tmp_y = y;
    y += dy;

    //TODO: fix this bicycle (something with types)
	std::vector<pair_t> collision_line = BresLine((int)tmp_x, (int)tmp_y, (int)x, (int)y, false);
	for (size_t i = 0; i < collision_line.size(); i++){
		if (d[(int)collision_line[i].y * 640 *3 + (int)collision_line[i].x * 3] == 255){
			active = 0;
			x = y = -1;
		}
	}
}
